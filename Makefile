CC = g++
Flags = -c -Wall

all: main.o
	$(CC) $^

main.o: main.cpp
	$(CC) $(Flags) $^
