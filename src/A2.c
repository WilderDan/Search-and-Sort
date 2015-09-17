/*  Author: 		Dan Wilder
 *
 *  School:		University of Missouri - St. Louis
 *  Semester:		Fall 2015
 *  Class: 		CS 3130 - Design and Analysis of Algorithms   
 *  Instructor:		Galina N. Piatnitskaia
 *
 *  Description:
 *    [15 points] Write a program to compare efficiency of four sorting 
 *  algorithms from part (1). To do that, you will have to use some function
 *  to measure the time of execution of a code fragment. Apply each sorting 
 *  method to 10 different arrays of random integers of each of the following
 *  sizes: 500, 1000, 2500 and 5000. The output of the program is average 
 *  execution times for all sizes. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/sort_algorithms.h"
#include "../include/array_utilities.h"

#define MAX_VAL   9999
#define NUM_SIZES 4
const int SIZES[NUM_SIZES] = {500, 1000, 2500, 5000};

int main() {

  // Array holding arrays of different sizes
  int *arr[NUM_SIZES]; 
  int i;

  // Allocate each array for each size
  for (i = 0; i < NUM_SIZES; ++i)
    arr[i] = (int *) malloc(SIZES[i] *sizeof(int));
   
  // Free memory
  for (i = 0; i < NUM_SIZES; ++i) 
    free(arr[i]);
  
  return 0;
}
