import sys
from core import read_ods_file, parse_region_string, extract_region, generate_c_arrays

def main():
    input_file="../../../gamplay/MONSTERS.ods"
    output='../../../src/GameCore/inc/type_effects.inc'
    sheet="Sheet3"
    name="type_effects:2,9,16,16:int"

    # Read the ODS file
    print(f"Reading {input_file}...")
    df = read_ods_file(input_file, sheet)

    print(f"Sheet dimensions: {len(df)} rows, {len(df.columns)} columns")

    # Parse regions and extract data
    regions = []
    try:
        region = parse_region_string(name)
        print(f"\nExtracting region '{region.name}':")
        print(f"  Position: row={region.start_row}, col={region.start_col}")
        print(f"  Size: {region.height}x{region.width}")
        print(f"  Type: {region.data_type}")

        # Extract the data
        region.data = extract_region(df, region.start_row, region.start_col,
                                     region.height, region.width)

        actual_height = len(region.data)
        actual_width = len(region.data[0]) if actual_height > 0 else 0
        print(f"  Extracted: {actual_height}x{actual_width} (may be padded if beyond sheet bounds)")

        regions.append(region)

    except Exception as e:
        print(f"Error parsing region '{name}': {e}")
        return 1

    # Generate the C arrays
    c_content = generate_c_arrays(regions, name)

    # Write to file
    with open(output, 'w') as f:
        f.write(c_content)

    print(f"\nSuccessfully generated {output} with {len(regions)} arrays")
    return 0


if __name__ == "__main__":
    sys.exit(main())