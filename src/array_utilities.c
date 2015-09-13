/*  Author: 		Dan Wilder
 *
 *  School:		University of Missouri - St. Louis
 *  Semester:		Fall 2015
 *  Class: 		CS 3130 - Design and Analysis of Algorithms   
 *  Instructor:		Galina N. Piatnitskaia
 */

#include "array_utilities.h"
#include <stdio.h>
#include <stdlib.h>

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

void randomInitialize(int arr[], int size, int maxVal) {
/* Initialize arr[0..size-1] to random int in interval [1, maxVal]
 * srand() should be called in application program ONCE prior to calling this
 */
  int i, randomInt;
   
  for (i = 0; i < size; i++) {
    randomInt = (rand() % maxVal-1) + 1;
    arr[i] = randomInt;
  }
}
