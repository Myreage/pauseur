hello:  main.o
	gcc -o hello main.o

main.o: main.c
	gcc -o main.o -c datastruct.c -W -Wall -ansi
