# C compiler and flags
CC     = gcc
CFLAGS = -std=c17 -Wall -pedantic -g

# Life Target

Life: main.c 
	${CC} ${CFLAGS}	-o $@ $^

# Life_Dynamic Target

Life_Dynamic: main_dynamic.c 
	${CC} ${CFLAGS}	-o $@ $^



