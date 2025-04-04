#include <iostream>
#include <vector>
#include <thread>
#include <numeric> // for std::accumulate

using namespace std;

void multiplyMatricesThread(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int N, int startRow, int endRow) {
    for (int i = startRow; i < endRow; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiplyMatricesThreaded(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int N, int numThreads) {
    vector<thread> threads(numThreads);
    int rowsPerThread = N / numThreads;
    int remainingRows = N % numThreads;

    int startRow = 0;
    for (int i = 0; i < numThreads; i++) {
        int endRow = startRow + rowsPerThread + (i < remainingRows ? 1 : 0);
        threads[i] = thread(multiplyMatricesThread, ref(A), ref(B), ref(C), N, startRow, endRow);
        startRow = endRow;
    }

    for (int i = 0; i < numThreads; i++) {
        threads[i].join();
    }
}

int main() {
    int N;
    cout << "Enter the size of the matrix: ";
    cin >> N;

    vector<vector<int>> A(N, vector<int>(N)), B(N, vector<int>(N)), C(N, vector<int>(N));

    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            B[i][j] = A[i][j];
        }
    }

    int numThreads = thread::hardware_concurrency(); // Get number of available threads.
    if (numThreads == 0) {
        numThreads = 4; // Default to 4 threads if hardware_concurrency() fails.
    }

    multiplyMatricesThreaded(A, B, C, N, numThreads);
    return 0;
}