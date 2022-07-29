#include "myfunctions.h"

/* this function adds matrices A & B and returns
  the output as result */
void m_add(int A[N][N], int B[N][N], int result[N][N]) {
  // implement matrix addition  here
  int i, j;
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      result[i][j] = A[i][j] + B[i][j];
    }
  return result;
}

/* this function multiplies matrices A & B and
  returns the output as result */
void m_multiply(int A[N][N], int B[N][N], int result[N][N]) {
  // implement matrix multiply here
  int i, j, k, sum = 0;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      for (k = 0; k < N; k++) {
        sum = sum + A[i][k] * B[k][j];
      }
      result[i][j] = sum;
      sum = 0;
    }
  }
  return result;
}

/* this function compares matrices A and B to see
  if they have the same values. Returns 0 if they
  are they are the same */
int m_compare(int A[N][N], int B[N][N]) {
  // implement comparison here
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (A[i][j] != B[i][j]) {
        return 1;
      }
    }
  }
  return 0;
}

/* helper function for displaying matrices */
void show_matrix(int m[N][N]) {
  for (int i = 0; i < N; i++) {
    printf("[ ");
    for (int j = 0; j < N; j++) {
      printf("%d ", m[i][j]);
    }
    printf("]\n");
  }
}
