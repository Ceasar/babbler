CC=g++
CFLAGS=-Wall
SRCS=main.cpp ngrams.cpp test.cpp random.cpp
OBJS=main.o ngrams.o random.o
TEST=test.o ngrams.o random.o

main: $(OBJS)

test: $(TEST)

clean:
	rm -f *.o test
