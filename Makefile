APPLI=Colorflood
CSRC= datastruct.c colors.c main.c
CC = gcc

CFLAGS = -Wall -Wextra -g

COBJ=$(CSRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $*.c

$(APPLI):	$(COBJ)
	$(CC) -o $(APPLI) $(COBJ) -lm

clean:
	-rm *.o *[~%] core *.bak
