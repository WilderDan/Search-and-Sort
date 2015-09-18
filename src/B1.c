/*  Author: 		Dan Wilder
 *
 *  School:		University of Missouri - St. Louis
 *  Semester:		Fall 2015
 *  Class: 		CS 3130 - Design and Analysis of Algorithms   
 *  Instructor:		Galina N. Piatnitskaia
 *
 *  Description:
 *    [10 points] Write a program to implement a linear search and binary 
 *  search algorithms. As input arrays, use sorted arrays that are an output 
 *  from part (A) of your project. Search for a random number that is between 
 *  the smallest and biggest value of your sorted array. The output in this 
 *  part is one sorted array, the key value you were searching for, and the 
 *  result of your search using both algorithms. You are NOT supposed to take
 *  an advantage of an array to be sorted when implementing a linear search!
 */

#include <stdio.h> 
#include <stdlib.h>
#include "../include/array_utilities.h"
#include "../include/search_algorithms.h"

#define INPUT_FILENAME "A1.sortedArray"
#define SIZE 100

int main() {
  
  int arr[SIZE];
  FILE *inFile = fopen(INPUT_FILENAME, "r");

  if (inFile == NULL) {
    fprintf(stderr, "Error opening file... Goodbye!");
    exit(1);
  } 

  readArrayFile(inFile, arr, SIZE);
  fclose(inFile);

  fprintArray(stdout, arr, SIZE);
  return 0;
}
