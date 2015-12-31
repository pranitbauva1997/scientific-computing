# Set compiler to GCC
CC = gcc

# Enable all compiler warnings
CFLAGS = -Wall
CFLAGS += -c -g

objects = simple_euler.o midpoint_euler.o four_order_simple_rk.o modified_midpoint.o main.o

all : main

main : $(objects)
	$(CC) $(objects) -o main

main.o : main.c ode.h
	$(CC) $(CFLAGS) main.c

simple_euler.o : simple_euler.c ode.h
	$(CC) $(CFLAGS) simple_euler.c

midpoint_euler.o : midpoint_euler.c ode.h
	$(CC) $(CFLAGS) midpoint_euler.c

four_order_simple_rk.o : four_order_simple_rk.c ode.h
	$(CC) $(CFLAGS) four_order_simple_rk.c

modified_midpoint.o : modified_midpoint.c ode.h
	$(CC) $(CFLAGS) modified_midpoint.c
.PHONY : clean

clean : 
	rm *.o main 
