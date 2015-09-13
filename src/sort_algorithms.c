/*  Author: 		Dan Wilder
 *
 *  School:		University of Missouri - St. Louis
 *  Semester:		Fall 2015
 *  Class: 		CS 3130 - Design and Analysis of Algorithms   
 *  Instructor:		Galina N. Piatnitskaia
 */
 
#include "sort_algorithms.h"

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void bubbleSort(int arr[], int size) {
/* with swaps counting.
 */
  int i, j, swaps;

  for (i = 0; i <= size-1; ++i) {  
    swaps = 0;   
 
    for (j = size; j >= i+1; --j)
      if (arr[j] < arr[j-1]) {
        swap(&arr[j], &arr[j-1]);
        ++swaps;
      }

    if (swaps == 0)
      break;
  }
}
