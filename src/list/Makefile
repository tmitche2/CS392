IDIR=../../include/
SRCS=$(wildcard *.c)
CC=gcc
CFLAGS = -std=c99 -I$(IDIR) -Wall -Werror --pedantic
all:
	$(CC) $(CFLAGS) -c *.c
	ar -rc liblist.a *.o
	ranlib liblist.a
	mv liblist.a ../../lib
clean:
	rm -f *.o
fclean: clean
	rm -f test
re: fclean all
test: ../../test/testlist.c all
	$(CC) ../../test/testlist.c $(CFLAGS) $(OBJS) -o test -L../../lib -llist -lmy
