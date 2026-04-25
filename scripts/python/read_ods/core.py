import sys
import pandas as pd
from datetime import datetime



class DataRegion:
    def __init__(self, name, start_row, start_col, height, width, data_type='int'):
        self.name = name
        self.start_row = start_row
        self.start_col = start_col
        self.height = height
        self.width = width
        self.data_type = data_type
        self.data = None


def read_ods_file(filename, sheet_name=None):
    """Read ODS file and return full DataFrame"""
    try:
        if sheet_name:
            df = pd.read_excel(filename, sheet_name=sheet_name, engine='odf', header=None)
        else:
            df = pd.read_excel(filename, engine='odf', header=None)

        # Replace NaN with 0 for numeric arrays, empty string for string arrays
        df = df.fillna(0)
        return df
    except Exception as e:
        print(f"Error reading ODS file: {e}")
        sys.exit(1)


def format_value(val, data_type='int'):
    """Format a value for C array syntax based on type"""
    if data_type == 'string' or data_type == 'char*':
        if pd.isna(val):
            return '""'
        # Convert to string and escape quotes
        val_str = str(val).replace('"', '\\"')
        return f'"{val_str}"'
    elif data_type == 'float' or data_type == 'double':
        if pd.isna(val):
            return '0.0'
        return str(float(val))
    elif data_type == 'bool':
        if pd.isna(val):
            return 'false'
        return 'true' if val else 'false'
    else:  # int, uint16_t, etc.
        if pd.isna(val):
            return '0'
        # Check if it's a number
        try:
            if isinstance(val, str):
                # Try to convert string to number
                return str(int(float(val)))
            return str(int(val))
        except:
            return '0'


def extract_region(df, start_row, start_col, height, width):
    """Extract a rectangular region from the DataFrame"""
    # Convert to 0-based indexing
    start_row = max(0, start_row - 1)  # Convert from 1-based to 0-based
    start_col = max(0, start_col - 1)

    end_row = min(len(df), start_row + height)
    end_col = min(len(df.columns), start_col + width)

    # Extract the region
    region_data = df.iloc[start_row:end_row, start_col:end_col]

    # If region is smaller than requested, pad with zeros/empty
    if region_data.shape[0] < height or region_data.shape[1] < width:
        # Create padded array
        padded = pd.DataFrame(index=range(height), columns=range(width))
        padded = padded.fillna(0)

        # Fill with actual data
        for i in range(region_data.shape[0]):
            for j in range(region_data.shape[1]):
                padded.iloc[i, j] = region_data.iloc[i, j]

        return padded.values.tolist()

    return region_data.values.tolist()


def parse_region_string(region_str):
    """Parse region string like 'matrix1:2,3,4,5:int' or 'config:1,1,10,5'"""
    parts = region_str.split(':')

    if len(parts) < 2:
        raise ValueError(f"Invalid region format: {region_str}")

    name = parts[0]
    coords = parts[1].split(',')

    if len(coords) < 4:
        raise ValueError(f"Invalid coordinates format: {parts[1]}")

    start_row = int(coords[0])
    start_col = int(coords[1])
    height = int(coords[2])
    width = int(coords[3])

    data_type = 'int'
    if len(parts) > 2:
        data_type = parts[2]

    return DataRegion(name, start_row, start_col, height, width, data_type)


def generate_c_arrays(regions, output_name="config"):
    """Generate C arrays for all regions"""
    lines = []

    # Header
    lines.append("/**")
    lines.append(" * Auto-generated C arrays from ODS file")
    lines.append(f" * Generated: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
    lines.append(" */")
    lines.append("")

    # Include guards
    guard_name = f"{output_name.upper()}_H"
    lines.append("")

    # Generate each array
    for region in regions:
        if not region.data:
            continue

        lines.append(f"/** Region: {region.name} */")
        lines.append(f"/** Position: row={region.start_row}, col={region.start_col} */")
        lines.append(f"/** Dimensions: {region.height}x{region.width} */")
        lines.append("")

        # Get actual dimensions
        actual_height = len(region.data)
        actual_width = len(region.data[0]) if actual_height > 0 else 0


        for i, row in enumerate(region.data):
            formatted_values = [format_value(val, region.data_type) for val in row]
            row_str = ", ".join(formatted_values)

            if i < actual_height - 1:
                row_str += ","
            lines.append(row_str)

        lines.append("")

    return "\n".join(lines)

