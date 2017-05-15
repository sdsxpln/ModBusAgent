CC = gcc
CFLAGS  = -ggdb3 -Wall
TARGET = ModBusAgent

default: ModBusAgent

ModBusAgent:  main.o 
	$(CC) $(CFLAGS) -o $(TARGET)  main.o

main.o:  main.c 
	$(CC) $(CFLAGS) -c main.c

.PHONY : clean
clean:
	$(RM) ModBusAgent *.o *~
