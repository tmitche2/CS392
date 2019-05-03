IDIR=../../include/
CC=gcc
CFLAGS = -std=c99 -I$(IDIR) -Wall -Werror --pedantic -lncurses
LIBFLAGS = -L../../lib/ -lmy -llist

all:
	$(CC) snek.c $(CFLAGS) $(LIBFLAGS) -o snek

clean:
	rm -f *.o

fclean: clean
	rm -f snek

re: fclean all
