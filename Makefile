CC=gcc
CFLAGS=-I. -lncurses
DEPS = soustraction_posee.c
OBJ = soustraction_posee.o
EXEC = soustraction_posee

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) $(EXEC)