/*  Author: 		Dan Wilder
 *
 *  School:		University of Missouri - St. Louis
 *  Semester:		Fall 2015
 *  Class: 		CS 3130 - Design and Analysis of Algorithms   
 *  Instructor:		Galina N. Piatnitskaia
 */

#include "../include/search_algorithms.h"

int linearSearch(int arr[], int size, int search) {
  int i;

  for (int i = 0; i < size; ++i) 
    if (arr[i] == search)
      return i;

  // Not found:
  return -1;
}

int binarySearch(int arr[], int size, int search) {

  first = 0;
  last = n - 1;
  middle = (first+last)/2;

  while (first <= last) {

    if (arr[middle] < search)
      first = middle + 1;
    
    else if (arr[middle] > search)
      last = middle -1;
 
    else 
      return middle;
 
    middle = (first + last)/2;
  }
  // Not found:
  return -1;
}
