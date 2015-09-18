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

#define MAX_CHARS 16
struct sortFunction {
  void (*funcPtr) (int [], int);
  char name[MAX_CHARS]; 
};

// PARAMETERS

#define MIN_VAL  1
#define MAX_VAL  999
#define NUM_RUNS 10

const int SIZES[] = {500, 1000, 2500, 5000};

const struct sortFunction SORT_FUNCS[]  = {
  {.funcPtr = bubbleSort, .name = "Bubble Sort"},
  {.funcPtr = cocktailSort, .name = "Cocktail Sort"},
  {.funcPtr = shellSort_1, .name = "Shell Sort(1)"},
  {.funcPtr = shellSort_2, .name = "Shell Sort(2)"},
};

double average_CPU_time(void (*sortFuncPtr)(int [], int), 
                        int arr[], int size, int numRuns) {
  int i; 
  double total = 0.0;
  clock_t start, end;

  for (i = 0; i < numRuns; ++i) {
    randomInitialize(arr, size, MIN_VAL, MAX_VAL);

    start = clock();
    (*sortFuncPtr)(arr, size);    
    end = clock();

    total += ((double) (end - start)) / CLOCKS_PER_SEC;  
  } 

  return total / numRuns;
}

int main() {

  const int NUM_SIZES = sizeof(SIZES)/sizeof(SIZES[0]);
  const int NUM_SORT_FUNCS = sizeof(SORT_FUNCS) / sizeof(SORT_FUNCS[0]);
  double cpu_times[NUM_SORT_FUNCS][NUM_SIZES];
  int i, j, *arr;

  // For each size in SIZES
  for (i = 0; i < NUM_SIZES; ++i) {
    // Allocate
    arr = (int *) malloc(SIZES[i] * sizeof(int));

    // Time each sort function of THIS PARTICULAR SIZE
    for (j = 0; j < NUM_SORT_FUNCS; ++j)
      cpu_times[j][i] =
        average_CPU_time(SORT_FUNCS[j].funcPtr, arr, SIZES[i], NUM_RUNS);

    // Free memory
    free(arr);
  }

  // Print Results
  printf("Average CPU Execution Times: (%d runs each)\n", NUM_RUNS);
  for (i = 0; i < NUM_SIZES; i++) {
    printf("\tArray Size %d:\n", SIZES[i]);
    
    for (j = 0; j < NUM_SORT_FUNCS; ++j) 
      printf("\t\t%s == %lf msec\n", SORT_FUNCS[j].name, cpu_times[j][i] * 1000);
  }

  return 0;
}
