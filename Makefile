CC=g++

FLAGS=-Wall -Werror -pedantic -std=c++11

all: main.o piece.o
	${CC} ${FLAGS} main.o piece.o -o exe

main.o: main.cpp
	${CC} ${FLAGS} -c main.cpp

piece.o: piece.cpp
	${CC} ${FLAGS} -c piece.cpp
