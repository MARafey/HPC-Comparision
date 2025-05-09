#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

void multiplyMatrices(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int N) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int N, numThreads;
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

    multiplyMatrices(A, B, C, N);

    return 0;
}