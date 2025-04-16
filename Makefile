CC = gcc
CFLAGS = -Wall -O2
OBJS = main.o network.o utils.o
all: xor_nn
xor_nn: $(OBJS)
	$(CC) $(CFLAGS) -o xor_nn $(OBJS) -lm
main.o: main.c network.h utils.h
	$(CC) $(CFLAGS) -c main.c
network.o: network.c network.h utils.h
	$(CC) $(CFLAGS) -c network.c
utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c
clean:
	rm -f *.o xor_nn