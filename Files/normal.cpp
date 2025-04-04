#include <iostream>
#include <vector>

using namespace std;

void multiplyMatrices(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int ll = 0; ll < N*N; ll++){

            }
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
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

    multiplyMatrices(A, B, C, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
