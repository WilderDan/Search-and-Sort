/*  Author: 		Dan Wilder
 *
 *  School:		University of Missouri - St. Louis
 *  Semester:		Fall 2015
 *  Class: 		CS 3130 - Design and Analysis of Algorithms   
 *  Instructor:		Galina N. Piatnitskaia
 *
 *  Description:
 *    [15 points] Write a program to compare efficiency of two searching 
 *  methods. Apply each of them to 10 sorted arrays of random integers of 
 *  each of the following sizes: 500, 1000, 2500 and 5000. The output of 
 *  the program is average execution times for all sizes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/search_algorithms.h"
#include "../include/sort_algorithms.h"
#include "../include/array_utilities.h"

// Parameters:
#define MIN_VAL  1
#define MAX_VAL  999
#define NUM_RUNS 10
const int SIZES[] = {500, 1000, 2500, 5000};

#define NUM_SEARCH_FUNCS 2

// Array indices:
#define LINEAR        0
#define BINARY        1

double average_CPU_time(int (*searchFuncPtr)(int [], int, int), 
                        int arr[], int size, int numRuns) {
/* 1) Randomly Initialize 'arr' with 'size' elements.  
 * 2) Sort array
 * 2) Call search function with 'arr' and 'size' and random search value
 * 3) Record cpu time taken for SEARCH ONLY
 * 4) Repeat steps 1-3 'numRuns' times
 * 5) Return average
 */

  int i; 
  double total = 0.0;
  clock_t start, end;

  for (i = 0; i < numRuns; ++i) {
    randomInitialize(arr, size, MIN_VAL, MAX_VAL);
    shellSort_2(arr, size);
    start = clock();
    (*searchFuncPtr)(arr, size, (rand() % (MAX_VAL-MIN_VAL)) + MIN_VAL);    
    end = clock();
    total += ((double) (end - start)) / CLOCKS_PER_SEC;  
  } 

  return total / numRuns;
}

int main() {

  const int NUM_SIZES = sizeof(SIZES)/sizeof(SIZES[0]);
  double cpu_times[NUM_SEARCH_FUNCS][NUM_SIZES];
  int i, *arr;

  srand(time(NULL));

  // For each size in SIZES
  for (i = 0; i < NUM_SIZES; ++i) {
    // Allocate
    arr = (int *) malloc(SIZES[i] * sizeof(int));

    // Time
    cpu_times[LINEAR][i] =
      average_CPU_time(linearSearch, arr, SIZES[i], NUM_RUNS);

    cpu_times[BINARY][i] = 
      average_CPU_time(binarySearch, arr, SIZES[i], NUM_RUNS);

    // Free memory
    free(arr);
  }

  // Print Results
  printf("Average CPU Execution Times: (%d runs each)\n", NUM_RUNS);
  for (i = 0; i < NUM_SIZES; i++) {
    printf("\tArray Size %d:\n", SIZES[i]);
    printf("\t\tLinear Search == %lf msec\n", cpu_times[LINEAR][i] * 1000);
    printf("\t\tBinary Search == %lf msec\n", cpu_times[BINARY][i] * 1000);
  }

  return 0;
}
