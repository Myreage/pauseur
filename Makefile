APPLI=Colorflood
CSRC= src/datastruct.c src/colors.c src/main.c
CTSRC=src/tests/colorsTest.c src/tests/datastructTests.c $(CSRC)
GUISRC= src/datastruct.c src/colors.c src/mainsdl.c src/gui.c
CC = gcc

CFLAGS = -Wall -Wextra -g

COBJ=$(CSRC:.c=.o)
CTOBJ=$(CTSRC:.c=.o)
GUIOBJ=$(GUISRC:.c=.o)


.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<


$(APPLI):	$(COBJ)
	$(CC) -o $(APPLI) $(COBJ) -lm

clean:
	-rm *.o *[~%] core *.bak

test:   $(CTOBJ)
	$(CC) -o TestColorflood $(CTOBJ) -lm -lcunit

gui:    $(GUIOBJ)
	$(CC) -o guiColorflood $(GUIOBJ) -lSDL -lSDL_ttf -lSDL_image
