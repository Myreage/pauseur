make <br />
./hello <br />

HOW TO COMPILE TEST <br />

colors : gcc tests/colorsTest.c colors.c datastruct.c -o colorsTest -lcunit
datastructs : gcc tests/datastructTests.c datastruct.c -o datastructTests -lcunit

