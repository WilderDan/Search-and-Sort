#  Author: 		Dan Wilder
#
#  School:		University of Missouri - St. Louis
#  Semester:		Fall 2015
#  Class: 		CS 3130 - Design and Analysis of Algorithms   
#  Instructor:		Galina N. Piatnitskaia

CC=gcc
CFLAGS=-c -g -Wall

SOURCES_A1=src/A1.c src/sort_algorithms.c src/array_utilities.c
SOURCES_A2=src/A2.c src/sort_algorithms.c src/array_utilities.c
SOURCES_B1=src/B1.c src/search_algorithms.c src/array_utilities.c
SOURCES_B2=src/B2.c src/search_algorithms.c src/sort_algorithms.c src/array_utilities.c

OBJECTS_A1=$(addprefix obj/, $(notdir $(SOURCES_A1:.c=.o) ) )
OBJECTS_A2=$(addprefix obj/, $(notdir $(SOURCES_A2:.c=.o) ) )
OBJECTS_B1=$(addprefix obj/, $(notdir $(SOURCES_B1:.c=.o) ) )
OBJECTS_B2=$(addprefix obj/, $(notdir $(SOURCES_B2:.c=.o) ) )

A1=A1.out
A2=A2.out
B1=B1.out
B2=B2.out

all: $(A1) $(A2) $(B1) $(B2)

A1: $(A1)
A2: $(A2)
B1: $(B1)
B2: $(B2)

$(A1): $(OBJECTS_A1)  
	$(CC) $(OBJECTS_A1) -o $(A1) -lm

$(A2): $(OBJECTS_A2)  
	$(CC) $(OBJECTS_A2) -o $(A2) -lm

$(B1): $(OBJECTS_B1)  
	$(CC) $(OBJECTS_B1) -o $(B1) -lm

$(B2): $(OBJECTS_B2)  
	$(CC) $(OBJECTS_B2) -o $(B2) -lm

obj/A1.o: src/A1.c ./include/sort_algorithms.h ./include/array_utilities.h
	$(CC) $(CFLAGS) src/A1.c -o obj/A1.o

obj/A2.o: src/A2.c ./include/sort_algorithms.h ./include/array_utilities.h
	$(CC) $(CFLAGS) src/A2.c -o obj/A2.o

obj/B1.o: src/B1.c ./include/search_algorithms.h ./include/array_utilities.h
	$(CC) $(CFLAGS) src/B1.c -o obj/B1.o

obj/B2.o: src/B2.c ./include/search_algorithms.h ./include/sort_algorithms.h ./include/array_utilities.h
	$(CC) $(CFLAGS) src/B2.c -o obj/B2.o

obj/sort_algorithms.o: src/sort_algorithms.c ./include/sort_algorithms.h
	$(CC) $(CFLAGS) src/sort_algorithms.c -o obj/sort_algorithms.o

obj/search_algorithms.o: src/search_algorithms.c ./include/search_algorithms.h
	$(CC) $(CFLAGS) src/search_algorithms.c -o obj/search_algorithms.o

obj/array_utilities.o: src/array_utilities.c ./include/array_utilities.h
	$(CC) $(CFLAGS) src/array_utilities.c -o obj/array_utilities.o
	
.PHONY: clean

clean:
	rm $(OBJECTS_A1) $(OBJECTS_A2) $(OBJECTS_B1) $(OBJECTS_B2) $(A1) $(A2) $(B1) $(B2)

