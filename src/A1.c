/*  Author: 		Dan Wilder
 *
 *  School:		University of Missouri - St. Louis
 *  Semester:		Fall 2015
 *  Class: 		CS 3130 - Design and Analysis of Algorithms   
 *  Instructor:		Galina N. Piatnitskaia
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/sort_algorithms.h"
#include "../include/array_utilities.h"

#define SIZE 100

int main() {

  int origin[SIZE];
  int arr[SIZE];

  srand(time(NULL));
  randomInitialize(origin, SIZE, 9999);

  printf("Original Array:\n\n");
  printArray(origin, SIZE);

  copyArray(arr, origin, SIZE);
  bubbleSort(arr, SIZE);
  printf("Bubble Sort with swaps counting:\n\n");
  printArray(arr, SIZE);
 
  copyArray(arr, origin, SIZE);
  cocktailSort(arr, SIZE);
  printf("Cocktail Sort with swaps counting:\n\n");
  printArray(arr, SIZE);
 
  copyArray(arr, origin, SIZE);
  shellSort(arr, SIZE);
  printf("Shellsort with gap sequence 2^k - 1; (1 appended to sequence)\n\n");
  printArray(arr, SIZE);

  return 0;
}
