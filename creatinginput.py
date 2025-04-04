import numpy as np
import os

def generate_matrix_file(n, folder="matrix_inputs"):
    """Generates an n x n matrix and saves it to a text file without excessive memory usage."""
    os.makedirs(folder, exist_ok=True)
    filename = os.path.join(folder, f"matrix_{n}x{n}.txt")

    try:
        with open(filename, "w") as f:
            f.write(f"{n}\n")  # Write matrix size
            
            for _ in range(n):  # Write row by row to save memory
                row = np.random.randint(0, 100, size=n, dtype=np.uint8)  # Use uint8 to save memory
                f.write(" ".join(map(str, row)) + "\n")

        print(f"Generated: {filename}")

    except MemoryError:
        print(f"MemoryError: Could not generate matrix for size {n}x{n}. Skipping...")

# Define matrix sizes to generate
sizes = [25, 50, 100, 500, 1000, 5000, 10000, 50000,60000,70000, 100000,200000,300000, 500000, 1000000, 5000000, 10000000]

# Generate files safely
for size in sizes:
    generate_matrix_file(size)
