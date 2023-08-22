CC = gcc
CFLAGS = -Wall -Werror -Wmissing-prototypes
#OBJS = dlist.o main.o
FILE_MAIN = main.o

all:
	make itrargs.o argapi_dlist.o argapi.o 
	$(CC) $(CFLAGS) -o ./obj/main.o ./obj/argapi.o ./obj/argapi_dlist.o ./obj/itrargs.o ./testing/main.c

argapi.o: ./src/argapi.c ./include/argapi.h 
	$(CC) $(CFLAGS) -c ./src/argapi.c -o ./obj/argapi.o 

argapi_dlist.o: ./modules/double-list/include/argapi_dlist.h ./modules/double-list/src/argapi_dlist.c
	$(CC) $(CFLAGS) -c ./modules/double-list/src/argapi_dlist.c -o ./obj/argapi_dlist.o 

itrargs.o:  ./modules/itargs/itrargs.h ./modules/itargs/itrargs.c 
	$(CC) $(CFLAGS) -c ./modules/itargs/itrargs.c -o ./obj/itrargs.o

run:
	./obj/main.o
clean:
	rm -rf ./obj/*.o