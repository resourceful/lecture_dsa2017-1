all: myapp

myapp: main.o foo.o bar.o
	gcc -o myapp main.o foo.o bar.o

main.o: main.c foo.h
	gcc -c main.c

foo.o: foo.c foo.h bar.h
	gcc -c foo.c

bar.o: bar.c bar.h baz.h
	gcc -c bar.c

clean: 
	rm *.o myapp
