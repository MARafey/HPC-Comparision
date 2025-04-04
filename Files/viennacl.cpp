#include <iostream>
#include <vector>
#include <viennacl/matrix.hpp>
#include <viennacl/linalg/prod.hpp>

using namespace std;

int main() {
    int N;
    cout << "Enter the size of the matrix: ";
    cin >> N;

    // Use a 2D vector for host matrices
    vector<vector<int>> A_host(N, vector<int>(N));
    vector<vector<int>> B_host(N, vector<int>(N));
    vector<vector<int>> C_host(N, vector<int>(N));

    cout << "Enter elements of the first matrix:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A_host[i][j];
            B_host[i][j] = A_host[i][j];
        }
    }

    // Create ViennaCL matrices
    viennacl::matrix<int> A(N, N);
    viennacl::matrix<int> B(N, N);
    viennacl::matrix<int> C(N, N);

    // Copy data from host to ViennaCL matrices
    viennacl::copy(A_host, A);
    viennacl::copy(B_host, B);

    // Perform matrix multiplication
    C = viennacl::linalg::prod(A, B);

    return 0;
}