IDIR=../../include/
CC=gcc
CFLAGS = -std=c99 -I$(IDIR) -Wall -Werror --pedantic -lncurses
LIBFLAGS = -L../../lib/ -lmy -llist

all:
	$(CC) myselect.c $(CFLAGS) $(LIBFLAGS) -o myselect

clean:
	rm -f *.o

fclean: clean
	rm -f myselect

re: fclean all
