CFLAGS=-Wall -g -DNDBUG -O0
LDFLAGS = -lm

all: 	tokenize.c libstring.o
	gcc $(CFLAGS)  -c tokenize.c  $(LDFLAGS)   
	gcc $(CFLAGS)  tokenize.o libstring.o -o tokenize  $(LDFLAGS)   

libstring.o:	libstring.c
	gcc $(CFLAGS)  -c libstring.c

clean:
	markdown README.md > README.html
	rm -f *.o
	rm -f test
	rm -f pca
	rm -f al
	rm -f tmp.*
	rm -f temp.*   
	rm -f *~


