CC=gcc
CFLAGS=-c -Wall

SOURCES_A1=src/A1.c src/sort_algorithms.c src/array_utilities.c
OBJECTS_A1=$(addprefix obj/, $(notdir $(SOURCES_A1:.c=.o) ) )

A1=A1.out

all: $(A1)

$(A1): $(OBJECTS_A1)  
	$(CC) $(OBJECTS_A1) -o $(A1) -lm

obj/A1.o: src/A1.c ./include/sort_algorithms.h ./include/array_utilities.h
	$(CC) $(CFLAGS) src/A1.c -o obj/A1.o

obj/sort_algorithms.o: src/sort_algorithms.c ./include/sort_algorithms.h
	$(CC) $(CFLAGS) src/sort_algorithms.c -o obj/sort_algorithms.o

obj/array_utilities.o: src/array_utilities.c ./include/array_utilities.h
	$(CC) $(CFLAGS) src/array_utilities.c -o obj/array_utilities.o
	
.PHONY: clean

clean:
	rm $(OBJECTS_A1) $(A1)
