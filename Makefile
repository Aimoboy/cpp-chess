CC=g++

FLAGS=-Wall -Werror -pedantic -std=c++14

all: main.o board.o piece.o
	${CC} ${FLAGS} main.o board.o piece.o -o exe

main.o: main.cpp
	${CC} ${FLAGS} -c main.cpp

board.o: board.cpp
	${CC} ${FLAGS} -c board.cpp

clean:
	rm -rf *.o exe
