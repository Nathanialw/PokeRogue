#!/usr/bin/env python3
"""
Batch generation script for all objects (creatures, spells, skills, items)
"""

import subprocess
import time
import sys
import argparse
from typing import List, Tuple, Dict, Any
from python.data import _spell_img_data, _item_img_data, _skill_img_data, _creature_img_data, _object_img_data
from python.config import settings


def get_all_objects() -> Dict[str, List[str]]:
    """Get all objects grouped by type"""
    objects = {
        'creature': [obj['name'] for obj in _creature_img_data.CreaturesDict],
        'spell': [obj['name'] for obj in _spell_img_data.SpellsDict],
        'skill': [obj['name'] for obj in _skill_img_data.SkillsDict],
        'item': [obj['name'] for obj in _item_img_data.ItemsDict],
        'object': [obj['name'] for obj in _object_img_data.ObjectsDict]
    }

    # Sort each list alphabetically
    for obj_type in objects:
        objects[obj_type].sort()

    return objects


def generate_object(object_type: str, object_name: str, server_url: str = settings.SVR_ADDRESS,
                    wait: bool = False, variants: int = None) -> bool:
    """Generate images for a single object"""
    cmd = ["python", "-m", "python.gen_images.client", "--server", server_url,
           "generate", object_type, object_name]

    if variants:
        cmd.extend(["--variants", str(variants)])

    if wait:
        cmd.append("--wait")

    print(f"\n{'=' * 60}")
    print(f"Generating: {object_type}/{object_name}")
    print(f"{'=' * 60}")
    print(f"Command: {' '.join(cmd)}")

    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=300)  # 5 minute timeout
        if result.returncode == 0:
            print(f"✓ Success: {object_type}/{object_name}")
            if result.stdout:
                print(result.stdout)
            return True
        else:
            print(f"✗ Failed: {object_type}/{object_name}")
            if result.stderr:
                print(f"Error: {result.stderr}")
            if result.stdout:
                print(f"Output: {result.stdout}")
            return False
    except subprocess.TimeoutExpired:
        print(f"✗ Timeout for {object_type}/{object_name}")
        return False
    except Exception as e:
        print(f"✗ Exception for {object_type}/{object_name}: {e}")
        return False


def generate_all_objects(server_url: str = settings.SVR_ADDRESS,
                         delay: int = 2,
                         wait: bool = False,
                         start_from: Tuple[str, str] = None,
                         limit: int = None,
                         object_types: List[str] = None,
                         variants: int = None) -> Tuple[int, List[Tuple[str, str]]]:
    """Generate images for all objects"""

    # Get all objects
    all_objects = get_all_objects()

    # Filter by object types if specified
    if object_types:
        all_objects = {k: v for k, v in all_objects.items() if k in object_types}

    # Flatten all objects with their types
    object_list = []
    for obj_type in sorted(all_objects.keys()):
        for obj_name in all_objects[obj_type]:
            object_list.append((obj_type, obj_name))

    total = len(object_list)
    successful = 0
    failed = []

    print(f"Found {total} objects to generate")
    print(f"Object types: {', '.join(all_objects.keys())}")
    print(f"Server: {server_url}")
    print(f"Wait for completion: {wait}")
    print(f"Delay between jobs: {delay} seconds")
    if variants:
        print(f"Variants per object: {variants}")
    print()

    # Apply start_from filter if specified
    if start_from:
        start_type, start_name = start_from
        try:
            # Find the starting index
            start_index = -1
            for i, (obj_type, obj_name) in enumerate(object_list):
                if obj_type == start_type and obj_name == start_name:
                    start_index = i
                    break

            if start_index >= 0:
                object_list = object_list[start_index:]
                print(f"Starting from: {start_type}/{start_name} (index {start_index})")
            else:
                print(f"Warning: '{start_type}/{start_name}' not found, starting from beginning")
        except ValueError:
            print(f"Warning: '{start_type}/{start_name}' not found, starting from beginning")

    # Apply limit if specified
    if limit:
        object_list = object_list[:limit]
        print(f"Limited to {limit} objects")

    print()

    # Process each object
    for i, (obj_type, obj_name) in enumerate(object_list, 1):
        print(f"\n[{i}/{len(object_list)}] Processing {obj_type}/{obj_name}...")

        if generate_object(obj_type, obj_name, server_url, wait, variants):
            successful += 1
        else:
            failed.append((obj_type, obj_name))

        # Don't delay after the last one
        if i < len(object_list):
            print(f"Waiting {delay} seconds before next object...")
            time.sleep(delay)

    # Print summary
    print(f"\n{'=' * 60}")
    print("BATCH GENERATION COMPLETE")
    print(f"{'=' * 60}")
    print(f"Total objects: {total}")
    print(f"Successful: {successful}")
    print(f"Failed: {len(failed)}")

    if failed:
        print("\nFailed objects:")
        for obj_type, obj_name in failed:
            print(f"  • {obj_type}/{obj_name}")

    return successful, failed


def generate_by_type(object_type: str, server_url: str = settings.SVR_ADDRESS,
                     delay: int = 2, wait: bool = False,
                     start_from: str = None, limit: int = None,
                     variants: int = None) -> Tuple[int, List[str]]:
    """Generate images for all objects of a specific type"""

    all_objects = get_all_objects()

    if object_type not in all_objects:
        print(f"Error: Unknown object type '{object_type}'")
        print(f"Available types: {', '.join(all_objects.keys())}")
        return 0, []

    object_names = all_objects[object_type]
    total = len(object_names)
    successful = 0
    failed = []

    print(f"Found {total} {object_type}s to generate")
    print(f"Server: {server_url}")
    print(f"Wait for completion: {wait}")
    print(f"Delay between jobs: {delay} seconds")
    if variants:
        print(f"Variants per {object_type}: {variants}")
    print()

    # Apply start_from filter if specified
    if start_from:
        try:
            start_index = object_names.index(start_from)
            object_names = object_names[start_index:]
            print(f"Starting from: {start_from} (index {start_index})")
        except ValueError:
            print(f"Warning: '{start_from}' not found, starting from beginning")

    # Apply limit if specified
    if limit:
        object_names = object_names[:limit]
        print(f"Limited to {limit} {object_type}s")

    print()

    # Process each object
    for i, object_name in enumerate(object_names, 1):
        print(f"\n[{i}/{len(object_names)}] Processing {object_type}/{object_name}...")

        if generate_object(object_type, object_name, server_url, wait, variants):
            successful += 1
        else:
            failed.append(object_name)

        # Don't delay after the last one
        if i < len(object_names):
            print(f"Waiting {delay} seconds before next {object_type}...")
            time.sleep(delay)

    # Print summary
    print(f"\n{'=' * 60}")
    print(f"{object_type.upper()} GENERATION COMPLETE")
    print(f"{'=' * 60}")
    print(f"Total {object_type}s: {total}")
    print(f"Successful: {successful}")
    print(f"Failed: {len(failed)}")

    if failed:
        print(f"\nFailed {object_type}s:")
        for obj in failed:
            print(f"  • {obj}")

    return successful, failed


def check_server_health(server_url: str) -> bool:
    """Check if the server is responsive"""
    try:
        import requests
        response = requests.get(f"{server_url}/health", timeout=5)
        if response.status_code == 200:
            data = response.json()
            print(f"✓ Server is healthy")
            print(f"  GPUs: {data.get('gpus', 'N/A')}")
            print(f"  Workers alive: {data.get('workers_alive', 'N/A')}")
            print(f"  Queue size: {data.get('queue_size', 'N/A')}")
            return True
        else:
            print(f"✗ Server returned status {response.status_code}")
            return False
    except Exception as e:
        print(f"✗ Cannot connect to server: {e}")
        return False


def monitor_jobs(server_url: str, poll_interval: int = 10):
    """Monitor job queue and wait for all jobs to complete"""
    import requests
    import time

    print("\nMonitoring jobs...")

    while True:
        try:
            response = requests.get(f"{server_url}/jobs", timeout=5)
            if response.status_code == 200:
                jobs = response.json()

                pending = sum(1 for j in jobs if j['status'] == 'pending')
                processing = sum(1 for j in jobs if j['status'] == 'processing')
                completed = sum(1 for j in jobs if j['status'] == 'completed')
                failed = sum(1 for j in jobs if j['status'] == 'failed')

                print(f"\rPending: {pending:3d} | Processing: {processing:3d} | Completed: {completed:3d} | Failed: {failed:3d}", end='', flush=True)

                if pending == 0 and processing == 0:
                    print("\nAll jobs completed!")
                    break
            else:
                print(f"\nError checking jobs: {response.status_code}")
        except Exception as e:
            print(f"\nError: {e}")

        time.sleep(poll_interval)


def list_all_objects():
    """List all available objects with counts"""
    all_objects = get_all_objects()

    print("\nAvailable objects:")
    print("=" * 60)

    total_count = 0
    for obj_type in sorted(all_objects.keys()):
        count = len(all_objects[obj_type])
        total_count += count
        print(f"\n{obj_type.upper()}s ({count}):")
        for obj_name in all_objects[obj_type][:10]:  # Show first 10
            print(f"  • {obj_name}")
        if count > 10:
            print(f"  ... and {count - 10} more")

    print(f"\nTotal objects: {total_count}")
    print("=" * 60)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Batch generate all objects (creatures, spells, skills, items, objects)')
    parser.add_argument('--server', type=str, default=settings.SVR_ADDRESS,
                        help=f'Server URL (default: {settings.SVR_ADDRESS})')
    parser.add_argument('--delay', type=int, default=2,
                        help='Delay between job submissions in seconds (default: 2)')
    parser.add_argument('--wait', action='store_true',
                        help='Wait for each job to complete before submitting the next')
    parser.add_argument('--start-from', type=str,
                        help='Start from a specific object (format: type/name, e.g., "creature/Dragon")')
    parser.add_argument('--limit', type=int,
                        help='Limit number of objects to process')
    parser.add_argument('--no-check', action='store_true',
                        help='Skip server health check')
    parser.add_argument('--monitor', action='store_true',
                        help='Monitor jobs after submission until all complete')
    parser.add_argument('--type', type=str, choices=['creature', 'spell', 'skill', 'item', 'object'],
                        help='Generate only objects of this type')
    parser.add_argument('--list', action='store_true',
                        help='List all available objects and exit')
    parser.add_argument('--variants', type=int,
                        help='Number of variants to generate per object (overrides default)')

    args = parser.parse_args()

    # List objects if requested
    if args.list:
        list_all_objects()
        sys.exit(0)

    # Check server health
    if not args.no_check:
        print("Checking server health...")
        if not check_server_health(args.server):
            print("Server is not healthy. Aborting.")
            sys.exit(1)
        print()

    # Parse start_from if specified
    start_from = None
    if args.start_from:
        try:
            parts = args.start_from.split('/')
            if len(parts) == 2:
                start_from = (parts[0], parts[1])
            else:
                print(f"Error: start_from must be in format 'type/name' (e.g., 'creature/Dragon')")
                sys.exit(1)
        except:
            print(f"Error: start_from must be in format 'type/name' (e.g., 'creature/Dragon')")
            sys.exit(1)

    # Run batch generation
    if args.type:
        # Generate only one type
        successful, failed = generate_by_type(
            object_type=args.type,
            server_url=args.server,
            delay=args.delay,
            wait=args.wait,
            start_from=start_from[1] if start_from else None,
            limit=args.limit,
            variants=args.variants
        )
    else:
        # Generate all types
        successful, failed = generate_all_objects(
            server_url=args.server,
            delay=args.delay,
            wait=args.wait,
            start_from=start_from,
            limit=args.limit,
            object_types=None,  # All types
            variants=args.variants
        )

    # Monitor if requested
    if args.monitor and not args.wait:
        monitor_jobs(args.server)

    # Exit with appropriate code
    if failed:
        sys.exit(1)
    else:
        sys.exit(0)
