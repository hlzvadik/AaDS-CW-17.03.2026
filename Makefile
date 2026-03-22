CC = g++
Flags = -c -Wall

main: main.cpp
	$(CC) $(Flags) $^
