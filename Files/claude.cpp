#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

// Function for a single thread to compute part of the result matrix
void multiplyPartial(const vector<vector<int>> &A, const vector<vector<int>> &B, 
                     vector<vector<int>> &C, int startRow, int endRow, int N) {
    for (int i = startRow; i < endRow; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to multiply matrices using threads
void multiplyMatricesThreaded(const vector<vector<int>> &A, const vector<vector<int>> &B, 
                              vector<vector<int>> &C, int N) {
    // Determine number of threads based on hardware
    unsigned int numThreads = thread::hardware_concurrency();
    if (numThreads == 0) numThreads = 4; // Default if hardware_concurrency fails
    
    // Limit threads based on problem size and system resources
    numThreads = min(numThreads, static_cast<unsigned int>(N));
    
    // Calculate rows per thread
    vector<thread> threads;
    int rowsPerThread = N / numThreads;
    
    // Create and start threads
    for (unsigned int t = 0; t < numThreads; t++) {
        int startRow = t * rowsPerThread;
        int endRow = (t == numThreads - 1) ? N : startRow + rowsPerThread;
        
        threads.push_back(thread(multiplyPartial, ref(A), ref(B), ref(C), startRow, endRow, N));
    }
    
    // Join all threads
    for (auto &t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }
}

int main() {
    int N;
    cout << "Enter the size of the matrix: ";
    cin >> N;
    
    // Initialize matrices
    vector<vector<int>> A(N, vector<int>(N)), B(N, vector<int>(N)), C(N, vector<int>(N));
    
    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            B[i][j] = A[i][j]; // Copy A to B as in original code
        }
    }
    
    // Perform threaded matrix multiplication
    multiplyMatricesThreaded(A, B, C, N);
    
    return 0;
}