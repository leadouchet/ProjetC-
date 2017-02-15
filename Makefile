CFLAGS= -g -std=c++11
LDFLAGS=

all: main

main: main.o Environment.o Cell.o Ga.o Gb.o
	g++ main.o Environment.o Cell.o Ga.o Gb.o -o main

main.o: main.cpp Environment.h Cell.h Ga.h Gb.h
	g++ $(CFLAGS) -c main.cpp -o main.o

Environment.o: Environment.cpp Environment.h
	g++ $(CFLAGS) -c  Environment.cpp -o Environment.o

Cell.o: Cell.cpp Cell.h
	g++ $(CFLAGS) -c  Cell.cpp -o Cell.o

Ga.o: Ga.cpp Ga.h
	g++ $(CFLAGS) -c  Ga.cpp -o Ga.o

Gb.o: Gb.cpp Gb.h
	g++ $(CFLAGS) -c  Gb.cpp -o Gb.o

clean:
	rm -f *.o
