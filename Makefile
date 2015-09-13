CC=gcc
CFLAGS=-c -Wall

SOURCES_A1=src/A1.c src/sort_algorithms.c src/array_utilities.c
OBJECTS_A1=$(addprefix obj/, $(notdir $(SOURCES_A1:.c=.o) ) )

A1=A1.out

all: $(A1)

$(A1): $(OBJECTS_A1)  
	$(CC) $(OBJECTS_A1) -o $(A1)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) $< -o $@

obj/A1.o: ./include/sort_algorithms.h ./include/array_utilities.h
	$(CC) $(CFLAGS) src/A1.c -o obj/A1.o

obj/sort_algorithms.o: ./include/sort_algorithms.h
	$(CC) $(CFLAGS) src/sort_algorithms.c -o obj/sort_algorithms.o

obj/array_utilities.o: ./include/array_utilities.h
	$(CC) $(CFLAGS) src/array_utilities.c -o obj/array_utilities.o
	
.PHONY: clean

clean:
	rm $(OBJECTS_A1) $(A1)