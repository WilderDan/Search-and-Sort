/*  Author: 		Dan Wilder
 *
 *  School:		University of Missouri - St. Louis
 *  Semester:		Fall 2015
 *  Class: 		CS 3130 - Design and Analysis of Algorithms   
 *  Instructor:		Galina N. Piatnitskaia
 */

#ifndef ARRAY_UTILITIES_H
#define ARRAY_UTILITIES_H

#include <stdio.h>

void fprintArray(FILE *, int [], int);
void randomInitialize(int [], int, int, int);
void copyArray(int [], int [], int);
void readArrayFile(FILE *, int [], int);

#endif
