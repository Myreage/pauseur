APPLI=Colorflood
CSRC= datastruct.c colors.c main.c
CTSRC=test/colorTest.c tests/datastructTests.c $(CSRC)
CC = gcc

CFLAGS = -Wall -Wextra -g

COBJ=$(CSRC:.c=.o)
CTOBJ=$(CTSRC:.c=.o)


.c.o:
	$(CC) $(CFLAGS) -c $*.c

$(APPLI):	$(COBJ)
	$(CC) -o $(APPLI) $(COBJ) -lm

clean:
	-rm *.o *[~%] core *.bak

test:
    $(CC) -o Test-$(APPLI) $(CTOBJ) -lcunit
