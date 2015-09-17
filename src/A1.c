/*  Author: 		Dan Wilder
 *
 *  School:		University of Missouri - St. Louis
 *  Semester:		Fall 2015
 *  Class: 		CS 3130 - Design and Analysis of Algorithms   
 *  Instructor:		Galina N. Piatnitskaia
 *
 *  Description:
 *    [25 points] Write a program to implement four sorting algorithms:
 *  (a) bubble sort with swaps counting, (b) cocktail (or shaker) sort with 
 *  swaps counting, (c) and (d) two versions of Shell sort (with two different
 *  sequences of “gaps”). Each algorithm must be implemented as a function. Run
 *  your program for an array containing 100 random integers. Show the original
 *  and sorted arrays in your output. REMEMBER to display arrays in the form of
 *  a square table with aligned columns!
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/sort_algorithms.h"
#include "../include/array_utilities.h"

#define SIZE 100
#define MAX_VAL 9999

int main() {

  int origin[SIZE];
  int arr[SIZE];
  
  srand(time(NULL));
  randomInitialize(origin, SIZE, MAX_VAL);

  printf("Original Array:\n\n");
  fprintArray(stdout, origin, SIZE);

  copyArray(arr, origin, SIZE);
  bubbleSort(arr, SIZE);
  printf("Bubble Sort with swaps counting:\n\n");
  fprintArray(stdout, arr, SIZE);
 
  copyArray(arr, origin, SIZE);
  cocktailSort(arr, SIZE);
  printf("Cocktail Sort with swaps counting:\n\n");
  fprintArray(stdout, arr, SIZE);
 
  copyArray(arr, origin, SIZE);
  shellSort_1(arr, SIZE);
  printf("Shellsort with gap sequence 2^k + 1 (1 appended to sequence)\n\n");
  fprintArray(stdout, arr, SIZE);

  copyArray(arr, origin, SIZE);
  shellSort_1(arr, SIZE);
  printf("Shellsort with gap sequence (3^k - 1)/2\n\n");
  fprintArray(stdout, arr, SIZE);

  // Save to file for use in part B
  FILE *f = fopen("A1.sortedArray", "w");
  if (f == NULL) {
    fprintf(stderr, "Error opening file!\n");
    exit(1);
  }
  
  fprintArray(f, arr, SIZE);
  fclose(f);

  return 0;
}
