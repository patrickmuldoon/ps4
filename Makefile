CC = g++ -std=c++0x
CFLAGS = -Wall -Werror -pedantic -g

all: ED

ED: EditDistance.o ED.o
	$(CC) $(CFLAGS) -o ED EditDistance.o ED.o -lsfml-system

EditDistance.o: EditDistance.cpp ED.cpp
	$(CC) $(CFLAGS) -ansi -c EditDistance.cpp

ED.o: ED.cpp 
	$(CC) $(CFLAGS) -ansi -c ED.cpp

clean:
	rm -rf ED *.o *.~