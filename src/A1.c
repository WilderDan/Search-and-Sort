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
  int arr[SIZE];

  srand(time(NULL));

  randomInitialize(arr, SIZE, 9999);
  printf("Original Array:\n\n");
  printArray(arr, SIZE);

  bubbleSort(arr, SIZE);
  printf("Bubble Sort with swaps counting:\n\n");
  printArray(arr, SIZE);

  randomInitialize(arr, SIZE, 9999);
  printf("Original Array:\n\n");
  printArray(arr, SIZE);

  cocktailSort(arr, SIZE);
  printf("Cocktail Sort with swaps counting:\n\n");
  printArray(arr, SIZE);

  return 0;
}
