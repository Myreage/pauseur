APPLI=Colorflood
CSRC=src/datastruct.c src/colors.c src/main.c
CT1SRC=src/datastruct.c src/tests/datastructTests.c
CT2SRC=src/datastruct.c src/colors.c src/tests/colorsTest.c

GUISRC= src/datastruct.c src/colors.c src/mainsdl.c src/gui.c
CC = gcc

CFLAGS = -Wall -Wextra -g

COBJ=$(CSRC:.c=.o)
CT1OBJ=$(CT1SRC:.c=.o)
CT2OBJ=$(CT2SRC:.c=.o)
GUIOBJ=$(GUISRC:.c=.o)


.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<


$(APPLI):	$(COBJ)
	$(CC) -o $(APPLI) $(COBJ) -lm

clean:
	-rm *.o ./src/*.o *[~%] core *.bak

testDatastruct:		$(CT1OBJ)
	$(CC) -o TestDatastruct $(CT1OBJ) -lm -lcunit

testColors:		$(CT2OBJ)
	$(CC) -o TestColors $(CT2OBJ) -lm -lcunit

gui:    $(GUIOBJ)
	$(CC) -o guiColorflood $(GUIOBJ) -lSDL -lSDL_ttf -lSDL_image
