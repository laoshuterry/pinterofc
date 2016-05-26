CC=gcc
CFLAGS=-ansi -Wall -DLINUX -D_GNU_SOURCE -g
PROGS =	intro_ptr array_interpretation dimension_array_pointer var_length_array
all: $(PROGS)

%:	%.c
	$(CC) $(CFLAGS) $@.c -o $@ 

clean:
	rm -f $(PROGS) *.o
