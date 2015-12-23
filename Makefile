# Set compiler to GCC
CC = gcc

# Enable all compiler warnings
CFLAGS = -Wall
CFLAGS += -c

objects = simple_euler.o midpoint_euler.o main.o

all : main

main : $(objects)
	$(CC) $(objects) -o main

main.o : main.c ode.h
	$(CC) $(CFLAGS) main.c

simple_euler.o : simple_euler.c ode.h
	$(CC) $(CFLAGS) simple_euler.c

midpoint_euler.o : midpoint_euler.c ode.h
	$(CC) $(CFLAGS) midpoint_euler.c

.PHONY : clean

clean : 
	rm *.o main 
