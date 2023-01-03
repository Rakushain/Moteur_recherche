CC = gcc
CFLAGS = -Wall -g

all: run

run: moteur

moteur: moteur.o main.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o *~ moteur
