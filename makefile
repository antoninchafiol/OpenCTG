CC=g++
CFLAGS=-Wall
EX_NAME=crypt

all: main

basics_arithmetics.o: basics_arithmetics.cpp  basics_arithmetics.hpp
	$(CC) $(CFLAGS) basics_arithmetics.cpp basics_arithmetics.hpp -c

main: main.cpp basics_arithmetics.o
	$(CC) $(CFLAGS) main.cpp basics_arithmetics.o -o $(EX_NAME)