IDIR=../../include/
CC=gcc
CFLAGS = -std=c99 -I$(IDIR) -Wall -Werror --pedantic -lncurses
LIBFLAGS = -L../../lib/ -lmy

all:
	$(CC) nsminishell.c $(CFLAGS) $(LIBFLAGS) -o nsminishell

clean:
	rm -f *.o

fclean: clean
	rm -f nsminishell

re: fclean all
