#include "myfunctions.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int A[N][N] = {{1, 2, 3, 5}, {1, 5, 3, 4},{1, 2, 3, 5}, {1, 5, 3, 4}};
  int B[N][N] = {{1, 2, 3, 5}, {1, 5, 3, 4},{1, 2, 3, 5}, {1, 5, 3, 4}};
  int Add[N][N];


  /* run addition */
  m_add(A, B, Add);
  printf("Output of addition\n");
//  show_matrix(Add);

  int Ex_Add[N][N] = {{2,4,6,10}, {2, 10, 6, 8}, {2, 4, 6, 10},{2, 10, 6, 8}};


  if (m_compare(Add, Ex_Add)){

	  printf("FAIL: Output DOES NOT match the golden output \n");
	  return -1;
  }
  else {
	  printf ("PASS: The output matches the golden output!\n");
	  return 0;
  }




  /* run multiplication */
//  m_multiply(A, B, M);
//  printf("Output of multiplication\n");
//  show_matrix(M);
//
//  /* test compare */
//  // put your compare test code here
//  int x = m_compare(A, B);
//  printf("Output of comparison\n");
//  printf("%d\n", x);
//  x = m_compare(A, A);
//  printf("%d\n", x);
//
//  /*Exercise 3 */
//
//  int Ex_Add[N][N] = {{5, 5}, {5, 5}};
//  int Ex_Multi[N][N] = {{0, 5}, {20, 13}};
//
//  if (m_compare(Ex_Add, Add) == 0 && m_compare(Ex_Multi, M) == 0) {
//    printf("Pass\n");
//    return 0;
//  } else if (m_compare(Ex_Add, Add) == 1 && m_compare(Ex_Multi, M) == 0) {
//    printf("Fail\n");
//    return -1;
//  } else {
//    printf("Fail\n");
//    return -2;
//  }
//   return 0;
}
