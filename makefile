GCC = gcc
SOURCES = $(wildcard *.c)
BINAIRES = $(patsubst %.c,%.o,${SOURCES})


all: main

main: ${BINAIRES}
	${GCC} $^ -o $@

%.o: %.c utils.h
%.o: %.c cesar.h
%.o: %.c vigenere.h

	${GCC} -c $<
	
clean:
	rm *.o
	rm main