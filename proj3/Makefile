## Proj3

scheduler:	scheduler.o	io.o
	gcc -o scheduler scheduler.o io.o

scheduler.o:	scheduler.c	io.h
	gcc -c scheduler.c io.h

io.o:	io.c	io.h
	gcc -c io.c io.h

clean:
	rm -f *.o scheduler