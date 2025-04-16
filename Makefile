CC = gcc
CFLAGS = -Wall -O2
OBJS = main.o neurnet.o utils.o
all: xor_nn
xor_nn: $(OBJS)
	$(CC) $(CFLAGS) -o xor_nn $(OBJS) -lm
main.o: main.c neurnet.h utils.h
	$(CC) $(CFLAGS) -c main.c
neurnet.o: neurnet.c neurnet.h utils.h
	$(CC) $(CFLAGS) -c neurnet.c
utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c
clean:
	rm -f *.o xor_nn