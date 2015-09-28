all: problem.o
	gcc -O2 -o problem problem.o
    
problem.o: problem.c LinkedList.h
	gcc -c -Wall -Werror -o problem.o problem.c

clean:
	rm -rf *.o problem
