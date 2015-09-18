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

#define MAX_CHARS 16
struct searchFunction {
  int (*funcPtr) (int [], int, int);
  char name[MAX_CHARS]; 
};

// PARAMETERS

#define MIN_VAL  1
#define MAX_VAL  999
#define NUM_RUNS 10

const int SIZES[] = {500, 1000, 2500, 5000};

const struct searchFunction SEARCH_FUNCS[]  = {
  {.funcPtr = linearSearch, .name = "Linear Search"},
  {.funcPtr = binarySearch, .name = "Binary Search"}
};

double average_CPU_time(int (*searchFuncPtr)(int [], int, int), 
                        int arr[], int size, int numRuns) {
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
  const int NUM_SEARCH_FUNCS = sizeof(SEARCH_FUNCS) / sizeof(SEARCH_FUNCS[0]);
  double cpu_times[NUM_SEARCH_FUNCS][NUM_SIZES];
  int i, j, *arr;

  srand(time(NULL));

  // For each size in SIZES
  for (i = 0; i < NUM_SIZES; ++i) {
    // Allocate
    arr = (int *) malloc(SIZES[i] * sizeof(int));

    // Time
    for (j = 0; j < NUM_SEARCH_FUNCS; ++j)
      cpu_times[j][i] =
        average_CPU_time(SEARCH_FUNCS[j].funcPtr, arr, SIZES[i], NUM_RUNS);

    // Free memory
    free(arr);
  }

  // Print Results
  printf("Average CPU Execution Times: (%d runs each)\n", NUM_RUNS);
  for (i = 0; i < NUM_SIZES; i++) {
    printf("\tArray Size %d:\n", SIZES[i]);

     for (j = 0; j < NUM_SEARCH_FUNCS; ++j) 
      printf("\t\t%s == %lf msec\n", SEARCH_FUNCS[j].name, cpu_times[j][i] * 1000);
  }

  return 0;
}
