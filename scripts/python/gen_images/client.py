# client.py
import requests
import json
import time
import argparse
import os
from typing import Optional

from python.config import settings


class AuraFlowClient:
    def __init__(self, base_url: str = "http://localhost:5000"):
        self.base_url = base_url.rstrip('/')

    def health(self):
        return requests.get(f"{self.base_url}/health").json()

    def list_gpus(self):
        return requests.get(f"{self.base_url}/gpus").json()

    def list_entities(self, object_type: Optional[str] = None):
        """
        List available objects (creatures, spells, skills, items)

        Args:
            object_type: Optional type to filter by (creature, spell, skill, item)
        """
        if object_type:
            return requests.get(f"{self.base_url}/objects/{object_type}").json()
        else:
            return requests.get(f"{self.base_url}/objects").json()

    def list_creatures(self):
        """Legacy method for backward compatibility"""
        return self.list_entities('creature')

    def list_spells(self):
        """List available spells"""
        return self.list_entities('spell')

    def list_skills(self):
        """List available skills"""
        return self.list_entities('skill')

    def list_items(self):
        """List available items"""
        return self.list_entities('item')

    def list_objects(self):
        """List available items"""
        return self.list_entities('object')

    def list_files(self, path: str = ""):
        """List files in a directory on the server"""
        response = requests.get(f"{self.base_url}/files/{path}" if path else f"{self.base_url}/files")
        return response.json()

    def generate(self, object_type: str, object_name: str, num_variants: Optional[int] = None,
                 height: int = 1024, width: int = 1024,
                 steps: int = 50, guidance_scale: float = 3.5,
                 wait: bool = False, poll_interval: int = 5):
        """
        Generate images for an object

        Args:
            object_type: Type of object (creature, spell, skill, item)
            object_name: Name of the object
            num_variants: Number of variants to generate
            height: Image height
            width: Image width
            steps: Inference steps
            guidance_scale: Guidance scale
            wait: Wait for job completion
            poll_interval: Polling interval in seconds when waiting
        """
        data = {
            "object_type": object_type,
            "object_name": object_name,
            "height": height,
            "width": width,
            "steps": steps,
            "guidance_scale": guidance_scale
        }
        if num_variants:
            data["num_variants"] = num_variants

        response = requests.post(f"{self.base_url}/generate", json=data)
        result = response.json()

        if response.status_code != 202:
            print(f"Error: {result.get('error')}")
            return result

        job_id = result['job_id']
        print(f"Job submitted: {job_id}")

        if wait:
            return self.wait_for_job(job_id, poll_interval)
        return result

    def get_job(self, job_id: str):
        return requests.get(f"{self.base_url}/jobs/{job_id}").json()

    def list_jobs(self):
        return requests.get(f"{self.base_url}/jobs").json()

    def wait_for_job(self, job_id: str, poll_interval: int = 5):
        while True:
            job = self.get_job(job_id)
            status = job['status']
            progress = job['progress']

            print(f"\rStatus: {status}, Progress: {progress}%", end='', flush=True)

            if status in ['completed', 'failed']:
                print()
                return job

            time.sleep(poll_interval)

    def download(self, remote_path: str, local_path: Optional[str] = None, create_dirs: bool = True):
        """
        Download a single file

        Args:
            remote_path: Path on server (can include object_type/object_name/filename)
            local_path: Local path to save file
            create_dirs: Create directories automatically
        """
        # Remove leading slash if present
        remote_path = remote_path.lstrip('/')

        response = requests.get(f"{self.base_url}/download/{remote_path}", stream=True)

        if response.status_code == 200:
            if not local_path:
                local_path = remote_path.split('/')[-1]

            # Get base output folder from settings
            base_output = getattr(settings, 'DOWNLOAD_FOLDER', './downloads')

            # Construct full local path
            full_local_path = os.path.join(local_path)

            # Create directories if needed
            print(f"REACHED")
            if create_dirs:
                print(f"{base_output} | {local_path}")
                os.makedirs(os.path.dirname(full_local_path) if os.path.dirname(full_local_path) else '.', exist_ok=True)

            with open(full_local_path, 'wb') as f:
                for chunk in response.iter_content(chunk_size=8192):
                    f.write(chunk)
            print(f"Downloaded to {full_local_path}")
            return True
        else:
            error_msg = response.json().get('error', 'Unknown error')
            print(f"Error downloading {remote_path}: {error_msg}")
            return False

    def download_all(self, remote_path: str = "", local_path: str = None, pattern: Optional[str] = None, recursive: bool = False):
        """
        Download all files from a remote directory

        Args:
            remote_path: Path on server to download from (can be empty for root)
            local_path: Local directory to save files
            pattern: Optional file pattern to filter (e.g., "*.png")
            recursive: Whether to download subfolders recursively
        """
        if local_path is None:
            local_path = getattr(settings, 'DOWNLOAD_FOLDER', './downloads')

        # Remove leading/trailing slashes
        remote_path = remote_path.strip('/')

        try:
            # List files on server
            files_data = self.list_files(remote_path)

            if 'error' in files_data:
                print(f"Error: {files_data['error']}")
                return 0, 0

            files = files_data.get('files', [])
            dirs = files_data.get('directories', [])

            # Create local directory
            os.makedirs(local_path, exist_ok=True)

            # Download files in current directory
            downloaded = 0
            skipped = 0

            for file_info in files:
                filename = file_info['name']

                # Only download PNG files by default
                if pattern and not self._matches_pattern(filename, pattern):
                    continue

                # If no pattern specified, only download PNG files
                if not pattern and not filename.endswith('.png'):
                    continue

                # Construct remote and local paths
                remote_file = os.path.join(remote_path, filename) if remote_path else filename
                local_file = os.path.join(local_path, filename)

                if os.path.exists(local_file):
                    print(f"Skipping (already exists): {local_file}")
                    skipped += 1
                    continue

                print(f"Downloading: {remote_file} -> {local_file}")
                if self.download(remote_file, local_file, create_dirs=True):
                    downloaded += 1
                else:
                    skipped += 1

            # Recursively download subdirectories
            if recursive and dirs:
                for dir_info in dirs:
                    dirname = dir_info['name']
                    remote_subdir = os.path.join(remote_path, dirname) if remote_path else dirname
                    local_subdir = os.path.join(local_path, dirname)

                    # Only recurse into directories that have files (creature, spell, skill, item folders)
                    # and their subdirectories
                    if dir_info.get('file_count', 0) > 0 or recursive:
                        print(f"\nEntering directory: {remote_subdir}")
                        sub_downloaded, sub_skipped = self.download_all(
                            remote_subdir, local_subdir, pattern, recursive
                        )
                        downloaded += sub_downloaded
                        skipped += sub_skipped

            return downloaded, skipped

        except Exception as e:
            print(f"Error during download_all: {e}")
            return 0, 0

    def download_job_images(self, job_id: str, output_dir: str = "downloads",
                            create_subdir: bool = True):
        """Download all images from a specific job"""
        job = self.get_job(job_id)

        if job['status'] != 'completed':
            print(f"Job {job_id} is not completed (status: {job['status']})")
            return False

        if 'output_files' not in job:
            print(f"No output files found for job {job_id}")
            return False

        # Create output directory
        if create_subdir:
            output_dir = os.path.join(output_dir, job_id)

        os.makedirs(output_dir, exist_ok=True)

        downloaded = 0
        for file_path in job['output_files']:
            filename = os.path.basename(file_path)
            print(f"Downloading: {filename}")

            # The file path in output_files might be the full server path
            # Extract the relative path from OUT_ROOT
            remote_path = file_path
            # Try to extract the object_type/object_name/filename part
            parts = file_path.split('/')
            if len(parts) >= 3:
                # Assuming format: .../object_type/object_name/filename
                remote_path = '/'.join(parts[-3:])

            if self.download(remote_path, os.path.join(output_dir, filename)):
                downloaded += 1

        print(f"Downloaded {downloaded} files to {output_dir}")
        return True

    def _matches_pattern(self, filename: str, pattern: str) -> bool:
        """Simple pattern matching (supports * wildcard)"""
        import fnmatch
        return fnmatch.fnmatch(filename, pattern)


def main():
    parser = argparse.ArgumentParser(description='AuraFlow Client')
    parser.add_argument('--server', type=str, default=getattr(settings, 'SVR_ADDRESS', 'http://localhost:5000'),
                        help='Server URL')

    subparsers = parser.add_subparsers(dest='command', help='Commands')

    # Health command
    subparsers.add_parser('health', help='Check server health')

    # List GPUs command
    subparsers.add_parser('gpus', help='List available GPUs')

    # List objects commands
    objects_parser = subparsers.add_parser('objects', help='List available objects')
    objects_parser.add_argument('--type', type=str, choices=['creature', 'spell', 'skill', 'item', 'object'],
                                help='Filter by object type')

    # Legacy creature command (for backward compatibility)
    subparsers.add_parser('creatures', help='List available creatures (legacy)')

    # New specific list commands
    subparsers.add_parser('spells', help='List available spells')
    subparsers.add_parser('skills', help='List available skills')
    subparsers.add_parser('items', help='List available items')

    # List jobs command
    subparsers.add_parser('jobs', help='List all jobs')

    # List files command
    files_parser = subparsers.add_parser('files', help='List files on server')
    files_parser.add_argument('path', type=str, nargs='?', default='',
                              help='Path to list (optional)')

    # Generate command
    gen_parser = subparsers.add_parser('generate', help='Generate images')
    gen_parser.add_argument('object_type', type=str, choices=['creature', 'spell', 'skill', 'item', 'object'],
                            help='Type of object to generate')
    gen_parser.add_argument('object_name', type=str, help='Name of the object')
    gen_parser.add_argument('--variants', type=int, help='Number of variants')
    gen_parser.add_argument('--height', type=int, default=1024, help='Image height')
    gen_parser.add_argument('--width', type=int, default=1024, help='Image width')
    gen_parser.add_argument('--steps', type=int, default=50, help='Inference steps')
    gen_parser.add_argument('--guidance', type=float, default=3.5, help='Guidance scale')
    gen_parser.add_argument('--wait', action='store_true', help='Wait for completion')
    gen_parser.add_argument('--poll', type=int, default=5, help='Poll interval in seconds')

    # Legacy generate command (for backward compatibility)
    legacy_gen_parser = subparsers.add_parser('generate-creature', help='Generate creature images (legacy)')
    legacy_gen_parser.add_argument('creature', type=str, help='Creature name')
    legacy_gen_parser.add_argument('--variants', type=int, help='Number of variants')
    legacy_gen_parser.add_argument('--height', type=int, default=1024, help='Image height')
    legacy_gen_parser.add_argument('--width', type=int, default=1024, help='Image width')
    legacy_gen_parser.add_argument('--steps', type=int, default=50, help='Inference steps')
    legacy_gen_parser.add_argument('--guidance', type=float, default=3.5, help='Guidance scale')
    legacy_gen_parser.add_argument('--wait', action='store_true', help='Wait for completion')
    legacy_gen_parser.add_argument('--poll', type=int, default=5, help='Poll interval in seconds')

    # Job status command
    job_parser = subparsers.add_parser('job', help='Get job status')
    job_parser.add_argument('job_id', type=str, help='Job ID')

    # Download single file command
    dl_parser = subparsers.add_parser('download', help='Download a single file')
    dl_parser.add_argument('remote_path', type=str, help='Remote path to download')
    dl_parser.add_argument('--output', '-o', type=str, help='Output path')
    dl_parser.add_argument('--no-create-dirs', action='store_false', dest='create_dirs',
                           help='Don\'t create directories automatically')

    # Download all files command
    dl_all_parser = subparsers.add_parser('download-all', help='Download all files from a directory')
    dl_all_parser.add_argument('--remote-path', '-r', type=str, default='',
                               help='Remote path to download from')
    dl_all_parser.add_argument('--local-path', '-l', type=str, default=None,
                               help='Local directory to save files')
    dl_all_parser.add_argument('--pattern', '-p', type=str, default=None,
                               help='File pattern filter (e.g., "*.png")')
    dl_all_parser.add_argument('--recursive', action='store_true',
                               help='Download subdirectories recursively')
    dl_all_parser.add_argument('--no-recursive', action='store_false', dest='recursive',
                               help='Don\'t download subdirectories')

    # Download job images command
    dl_job_parser = subparsers.add_parser('download-job', help='Download all images from a job')
    dl_job_parser.add_argument('job_id', type=str, help='Job ID')
    dl_job_parser.add_argument('--output', '-o', type=str, default='downloads',
                               help='Output directory')
    dl_job_parser.add_argument('--no-subdir', action='store_false', dest='create_subdir',
                               help='Don\'t create job subdirectory')

    args = parser.parse_args()

    client = AuraFlowClient(args.server)

    if args.command == 'health':
        print(json.dumps(client.health(), indent=2))

    elif args.command == 'gpus':
        print(json.dumps(client.list_gpus(), indent=2))

    elif args.command == 'entities':
        result = client.list_entities(args.type)
        print(json.dumps(result, indent=2))

    elif args.command == 'creatures':
        # Legacy command - maintain compatibility
        result = client.list_creatures()
        print(json.dumps(result, indent=2))

    elif args.command == 'spells':
        result = client.list_spells()
        print(json.dumps(result, indent=2))

    elif args.command == 'skills':
        result = client.list_skills()
        print(json.dumps(result, indent=2))

    elif args.command == 'items':
        result = client.list_items()
        print(json.dumps(result, indent=2))

    elif args.command == 'objects':
        result = client.list_objects()
        print(json.dumps(result, indent=2))

    elif args.command == 'jobs':
        print(json.dumps(client.list_jobs(), indent=2))

    elif args.command == 'files':
        print(json.dumps(client.list_files(args.path), indent=2))

    elif args.command == 'generate':
        result = client.generate(
            object_type=args.object_type,
            object_name=args.object_name,
            num_variants=args.variants,
            height=args.height,
            width=args.width,
            steps=args.steps,
            guidance_scale=args.guidance,
            wait=args.wait,
            poll_interval=args.poll
        )
        print(json.dumps(result, indent=2))

    elif args.command == 'generate-creature':
        # Legacy command - maintain compatibility
        result = client.generate(
            object_type='creature',
            object_name=args.creature,
            num_variants=args.variants,
            height=args.height,
            width=args.width,
            steps=args.steps,
            guidance_scale=args.guidance,
            wait=args.wait,
            poll_interval=args.poll
        )
        print(json.dumps(result, indent=2))

    elif args.command == 'job':
        print(json.dumps(client.get_job(args.job_id), indent=2))

    elif args.command == 'download':
        client.download(args.remote_path, args.output, args.create_dirs)

    elif args.command == 'download-all':
        downloaded, skipped = client.download_all(
            remote_path=args.remote_path,
            local_path=args.local_path,
            pattern=args.pattern,
            recursive=args.recursive
        )
        print(f"\nDownload complete: {downloaded} files downloaded, {skipped} skipped")

    elif args.command == 'download-job':
        client.download_job_images(args.job_id, args.output, args.create_subdir)

    else:
        parser.print_help()


if __name__ == '__main__':
    main()
