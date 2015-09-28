all: problem.o
	gcc -g -o problem problem.o
    
problem.o: problem.c LinkedList.h
	gcc -g -c -o problem.o problem.c

clean:
	rm -rf *.o problem
