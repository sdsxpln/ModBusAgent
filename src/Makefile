CC = gcc
CFLAGS  = -ggdb3 -Wall
TARGET = ModBusAgent

objects = iniparser.o dictionary.o frontserver.o main.o

default: ModBusAgent

ModBusAgent:  $(objects)
	$(CC) $(CFLAGS) -o $(TARGET) $(objects)

iniparser.o: iniparser.h
dictionary.o: dictionary.h
frontserver.o: frontserver.h

.PHONY : clean
clean:
	$(RM) ModBusAgent *.o *~
