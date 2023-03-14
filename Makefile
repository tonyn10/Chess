CC=gcc
CFLAGS=-I.
DEPS = position.h piece.h board_state.h square.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# flag for GTK configuration
GTK = `pkg-config --libs --cflags gtk+-3.0`

text: text.o position.o piece.o board_state.o square.o
	$(CC) -o text text.o position.o piece.o board_state.o square.o

window: window.o
	$(CC) -o window window.o $(GTK)

