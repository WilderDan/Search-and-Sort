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
  int gaps_1[8] = {701, 301, 132, 57, 23, 10, 4, 1};

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
  shellSort(arr, SIZE, gaps_1, 8);
  printf("Shellsort with gap sequence {701, 301, 132, 57, 23, 10, 4, 1}:\n\n");
  printArray(arr, SIZE);

  return 0;
}
