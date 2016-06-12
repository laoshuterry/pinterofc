CC=gcc
CFLAGS=-ansi -Wall -DLINUX -D_GNU_SOURCE -g
PROGS =	intro_ptr array_interpretation dimension_array_pointer var_length_array allocateArray \
funcpointer strMem strStdOper strPassing diffStrlenSizeof strReturn strFuncPtr structBasic
INC=./include
all: $(PROGS)

%:	%.c
	$(CC) $(CFLAGS) -I$(INC) $@.c -o $@ 

clean:
	rm -f $(PROGS) *.o a.out
