rsvp.out: course.o rsvp.o vector.o student.o
	gcc -Wall -g -o rsvp.out course.o rsvp.o vector.o student.o

rsvp.o: rsvp.c course.h vector.h student.h
	gcc -Wall -g -c rsvp.c

course.o: course.c course.h vector.h 
	gcc -Wall -g -c course.c

student.o: student.c student.h vector.h 
	gcc -Wall -g -c student.c

vector.o: vector.c vector.h course.h 
	gcc -Wall -g -c vector.c

clean:
	rm -f rsvp.out course.o rsvp.o vector.o student.o 
