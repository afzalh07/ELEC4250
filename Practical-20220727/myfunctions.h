#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

#include <stdio.h>

#define N 2     // defines size of matrices

/* helper function for displaying matrices */
void show_matrix(int m[N][N]);

/* this function adds matrices A & B and returns 
  the output as result */
void m_add(int A[N][N], int B[N][N], int result[N][N]);

/* this function multiplies matrices A & B and 
  returns the output as result */
void m_multiply(int A[N][N], int B[N][N], int result[N][N]);

/* this function compares matrices A & B to see 
  if they have the same values. Returns 0 if they 
  are they are the same */
int m_compare(int A[N][N], int B[N][N]);


#endif
