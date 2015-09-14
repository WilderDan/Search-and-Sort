/*  Author: 		Dan Wilder
 *
 *  School:		University of Missouri - St. Louis
 *  Semester:		Fall 2015
 *  Class: 		CS 3130 - Design and Analysis of Algorithms   
 *  Instructor:		Galina N. Piatnitskaia
 */
 
#include "../include/sort_algorithms.h"

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

void cocktailSort(int arr[], int size) {
/* with swaps counting.
 */
  int i, begin, end, swaps;
  
  begin = -1; // Index: Will be incremented to 0 on first iteration
  end = size - 1; // Size is num elements in arr; -1 as offset for index  
  do {
    swaps = 0;
    ++begin; // Elements before 'begin' are already in correct order 
    for(i = begin; i < end; ++i) { // Final i will be 1 before end
      if(arr[i] > arr[i + 1]) {
        swap( &arr[i], &arr[i + 1] );
        ++swaps;
      }
    }

    if (swaps == 0)
      break; // arr is sorted

    swaps = 0;
    --end;  // Elements after 'end' are already in correct order.
    for (i = end; i > begin; --i) { // Final i will be 1 after begin
      if (arr[i] < arr[i-1]) {
        swap(&arr[i], &arr[i - 1]);
        ++swaps;
      }
    }
  }
  while (swaps);
}
