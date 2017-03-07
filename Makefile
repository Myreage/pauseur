APPLI=Colorflood
CSRC= datastruct.c colors.c main.c
CTSRC=test/colorsTest.c tests/datastructTests.c $(CSRC)
GUISRC= datastruct.c colors.c mainsdl.c
CC = gcc

CFLAGS = -Wall -Wextra -g

COBJ=$(CSRC:.c=.o)
CTOBJ=$(CTSRC:.c=.o)
GUIOBJ=$(GUISRC:.c=.o)


.c.o:
	$(CC) $(CFLAGS) -c $*.c


$(APPLI):	$(COBJ)
	$(CC) -o $(APPLI) $(COBJ) -lm

clean:
	-rm *.o *[~%] core *.bak

test:   $(CTOBJ)
	$(CC) -o TestColorflood $(CTOBJ) -lm -lcunit

gui:    $(GUIOBJ)
	$(CC) -o guiColorflood $(GUIOBJ) -lSDL -lSDL_ttf