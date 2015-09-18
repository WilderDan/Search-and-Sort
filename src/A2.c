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

// Parameters:
#define MAX_VAL  9999
#define NUM_RUNS 10
const int SIZES[] = {500, 1000, 2500, 5000};

#define NUM_SORT_FUNCS 4

// Array indices:
#define BUBBLE         0
#define COCKTAIL       1
#define SHELLSORT_1    2
#define SHELLSORT_2    3

double average_CPU_time(void (*sortFuncPtr)(int [], int), 
                        int arr[], int size, int numRuns) {
/* 1) Randomly Initialize 'arr' with 'size' elements.  
 * 2) Call 'sort_function' with 'arr' and 'size' as arguments
 * 3) Record cpu time taken
 * 4) Repeat steps 1-3 'numRuns' times
 * 5) Return average
 */

  int i; 
  double total = 0.0;
  clock_t start, end;

  for (i = 0; i < numRuns; ++i) {
    randomInitialize(arr, size, MAX_VAL);
    start = clock();
    (*sortFuncPtr)(arr, size);    
    end = clock();
    total += ((double) (end - start)) / CLOCKS_PER_SEC;  
  } 

  return total / numRuns;
}

int main() {

  const int NUM_SIZES = sizeof(SIZES)/sizeof(SIZES[0]);
  double cpu_times[NUM_SORT_FUNCS][NUM_SIZES];
  int i, *arr;

  // For each size in SIZES
  for (i = 0; i < NUM_SIZES; ++i) {
    // Allocate
    arr = (int *) malloc(SIZES[i] * sizeof(int));

    // Time
    cpu_times[BUBBLE][i] =
      average_CPU_time(bubbleSort, arr, SIZES[i], NUM_RUNS);

    cpu_times[COCKTAIL][i] = 
      average_CPU_time(cocktailSort, arr, SIZES[i], NUM_RUNS);

    cpu_times[SHELLSORT_1][i] =
      average_CPU_time(shellSort_1, arr, SIZES[i], NUM_RUNS);

    cpu_times[SHELLSORT_2][i] =
      average_CPU_time(shellSort_2, arr, SIZES[i], NUM_RUNS);

    // Free
    free(arr);
  }

  // Print Results The output of the program is average 
  //  execution times for all sizes. 
  
  printf("Average CPU Execution Times: (%d runs)\n", NUM_RUNS);
  for (i = 0; i < NUM_SIZES; i++) {
    printf("\tArray Size %d:\n", SIZES[i]);
    printf("\t\tBubble Sort == %lf msec\n", cpu_times[BUBBLE][i] * 1000);
    printf("\t\tCocktail Sort == %lf msec\n", cpu_times[COCKTAIL][i] * 1000);
    printf("\t\tShell Sort (1) == %lf msec\n", cpu_times[SHELLSORT_1][i] * 1000);
    printf("\t\tShell Sort (2) == %lf msec\n", cpu_times[SHELLSORT_2][i] * 1000);    
  }

  return 0;
}
