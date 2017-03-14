PROGRAMS = array_address pointer_variable null_pointer swap malloc_ex

CFLAGS = -g -Wall -O0


all: ${PROGRAMS}

%.o: %.c
	${CC} ${CFLAGS} -c $<

${PROGRAMS}: %: %.o
	${CC} ${CFLAGS} -o $@ $<

clean:
	rm -r ${PROGRAMS} *.o 
