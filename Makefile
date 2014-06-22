CFLAGS=-Wall -g -DNDBUG -O0
LDFLAGS = -lm

all: 	tokenize.c
	gcc $(CFLAGS)  -o tokenize tokenize.c  $(LDFLAGS)   
	markdown README.md >README.html

clean:
	rm -f *.o
	rm -f test
	rm -f pca
	rm -f al
	rm -f tmp.*
	rm -f temp.*   
	rm -f *~


