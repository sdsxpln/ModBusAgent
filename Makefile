CC = gcc
CFLAGS  = -ggdb3 -Wall
TARGET = ModBusAgent

objects = conf.o main.o

default: ModBusAgent

ModBusAgent:  $(objects)
	$(CC) $(CFLAGS) -o $(TARGET) $(objects)

conf.o: conf.h

.PHONY : clean
clean:
	$(RM) ModBusAgent *.o *~
