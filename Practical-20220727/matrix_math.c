#include "myfunctions.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int A[N][N] = {{1, 2}, {3, 4}};
  int B[N][N] = {{4, 3}, {2, 1}};
  int Add[N][N];
  int M[N][N];

  /* run addition */
  m_add(A, B, Add);
  printf("Output of addition\n");
  show_matrix(Add);

  /* run multiplication */
  m_multiply(A, B, M);
  printf("Output of multiplication\n");
  show_matrix(M);


  int Ex_Add[N][N] = {{0, 5}, {5, 5}};
  int Ex_Multi[N][N] = {{8, 5}, {20, 13}};


  /* test compare */
  // put your compare test code here
  int x = m_compare(Ex_Add, Add);
  printf("Output of comparison\n");
  printf("%d\n", x);
  x = m_compare(Ex_Multi, M);
  printf("%d\n", x);

  /*Exercise 3 */

    if (m_compare(Ex_Add, Add) == 0 && m_compare(Ex_Multi, M) == 0) {
    printf("Pass\n");
    return 0;
  } else if (m_compare(Ex_Add, Add) == 1 && m_compare(Ex_Multi, M) == 0) {
    printf("Fail\n");
    return -1;
  } else {
    printf("Fail\n");
    return -2;
  }
  // return 0;
}
