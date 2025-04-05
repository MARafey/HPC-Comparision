# HPC Matrix Multiplication Comparison

This project compares different implementations of matrix multiplication algorithms, including parallel and serial versions using various optimization techniques.

## Setup Requirements

- Python 3.x
- g++ compiler with OpenMP support
- valgrind
- Required Python packages:
  ```bash
  pip install pandas numpy
  ```

## Project Structure

```
HPC-Comparision/
├── Files/          # Contains different matrix multiplication implementations
├── Inputs/         # Input matrix files
├── Results/        # Performance analysis results
├── run.py         # Benchmarking script
```

## Running the Benchmarks

1. Place your matrix multiplication implementations in the `Files/` directory with `.cpp` extension
2. Ensure input matrices are in the `Inputs/` directory as `.txt` files
3. Run the benchmark:
   ```bash
   python run.py
   ```

## Input Format

The input files should be formatted as:

```
N           # Size of matrix (N x N)
<matrix A>  # N x N elements
<matrix B>  # N x N elements
```

## Results Analysis

The benchmarking measures several metrics:

- Execution time (User, System, and Elapsed)
- Memory usage (RSS)
- CPU usage
- Context switches
- Page faults
- I/O operations

### Performance Comparison

Based on the results for different matrix sizes (25x25 to 3200x3200):

1. Parinomo Implementation:

   - Best performance for large matrices
   - ~90% faster than serial implementation for 3200x3200
   - Optimal CPU utilization (100%)

2. ViennaCL Implementation:

   - Good performance for medium-sized matrices
   - Consistent memory usage

3. Serial Implementation:
   - Baseline for comparison
   - Suitable for small matrices (< 100x100)
   - Higher execution time for large matrices

## Contributing

1. Fork the repository
2. Add your implementation in the `Files/` directory
3. Run the benchmarks
4. Submit a pull request with your results

## License

MIT License
