INCLUDE=headers/
CFLAGS += -Wall
LDLIBS += -lm
CC=gcc
DEPS=distance

SRC_PGM=main.c

compile: main.o $(DEPS).o
	$(CC) main.o $(DEPS).o $(LDLIBS) -o pgm

$(DEPS).o: sources/distance.c
	$(CC) -I $(INCLUDE) -c sources/$(DEPS).c -o $(DEPS).o

main.o: $(SRC) 
	$(CC) -I $(INCLUDE) -c $(SRC_PGM) 
	
clean:
	rm -rf *.o
	rm pgm
