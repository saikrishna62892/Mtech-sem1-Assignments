INCLUDE=headers/
CFLAGS += -Wall
LDLIBS += -lm
CC=gcc
DEPS1=list
DEPS2=queue

SRC_PGM=main.c


compile: main.o $(DEPS1).o $(DEPS2).o
	$(CC) main.o $(DEPS1).o $(DEPS2).o -o project

$(DEPS1).o: list.c
	$(CC) -I $(INCLUDE) -c $(DEPS1).c -o $(DEPS1).o

$(DEPS2).o: queue.c
	$(CC) -I $(INCLUDE) -c $(DEPS2).c -o $(DEPS2).o

main.o: $(SRC) 
	$(CC) -I $(INCLUDE) -c $(SRC_PGM) 
	
clean:
	rm -rf *.o
	rm project




