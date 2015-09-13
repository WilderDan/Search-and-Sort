/*  Author: 		Dan Wilder
 *
 *  School:		University of Missouri - St. Louis
 *  Semester:		Fall 2015
 *  Class: 		CS 3130 - Design and Analysis of Algorithms   
 *  Instructor:		Galina N. Piatnitskaia
 */

#include <stdio.h>
#include "sort_algorithms.h"

void printArray(int [], int);

int main() {
  return 0;
}

void printArray(int arr[], int size) {
/* Print in square table (10x10) with columns aligned
 */
  int i;

  for (i=0; i < size; i++) {
    printf("%5d ", arr[i]);
    if ((i+1)%10 == 0)
      printf("\n");
  }

  printf("\n");
}
