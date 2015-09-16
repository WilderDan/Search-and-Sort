/*  Author: 		Dan Wilder
 *
 *  School:		University of Missouri - St. Louis
 *  Semester:		Fall 2015
 *  Class: 		CS 3130 - Design and Analysis of Algorithms   
 *  Instructor:		Galina N. Piatnitskaia
 */
 
#include "../include/sort_algorithms.h"
#include <math.h>

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void bubbleSort(int arr[], int size) {
/* with swaps counting.
 */
  int i, j, swaps;

  for (i = 0; i < size; ++i) {  
    swaps = 0;   
 
    for (j = size-1; j >= i+1; --j)
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

void shellSort_1(int arr[], int size) {

  int gap, i, j, k, temp;
 
  // Select initial k : 2^k + 1 < size - 1; Gap Sequence: 2^k + 1
  for (k = floor(log(size-1)/log(2)); k >= 0; --k) { 

    // Append 1 to gap sequence on final iteration
    gap = (k == 0) ? 1 : pow(2, k) + 1;

    for (i = gap; i < size; ++i) { 
      temp = arr[i];
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
        arr[j] = arr[j - gap];
      }    
      arr[j] = temp;
    }
  }
}

void shellSort_2(int arr[], int size) {

  int gap, i, j, k, temp;
 
  for (k = floor( log(2*ceil((size-1)/3)+1) / log(3) ); k > 0; --k) { 

    gap = (pow(3, k) - 1)/2;

    for (i = gap; i < size; ++i) { 
      temp = arr[i];
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
        arr[j] = arr[j - gap];
      }    
      arr[j] = temp;
    }
  }
}
