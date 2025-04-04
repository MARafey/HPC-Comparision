#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

const int tile_size = 16;
void multiplyMatrices(vector < vector < int >> & A, vector < vector < int >> & B, vector < vector < int >> & C, int N) {
  #pragma omp parallel for shared(A, B, C, N)
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      C[i][j] = A[i][j] + B[i][j];
    }
  }
}

int main() {
  int N;
  cout << "Enter the size of the matrix: ";
  cin >> N;

  vector < vector < int >> A(N, vector < int > (N)), B(N, vector < int > (N)), C(N, vector < int > (N));

  cout << "Enter elements of first matrix:";
  for (int i_tile = 0; i_tile < N; i_tile += tile_size) {
    for (int i = i_tile; i < std::min(i_tile + tile_size, N); i++) {
      for (int j_tile = 0; j_tile < N; j_tile += tile_size) {
        for (int j = j_tile; j < std::min(j_tile + tile_size, N); j++) {
          cin >> A[i][j];
          B[i][j] =
            A[i][j];
        }
      }
    }
  }

  multiplyMatrices(A, B, C, N);

  return 0;
}