CC=gcc
CFLAGS=-I.
DEPS = position.h piece.h board_state.h square.h text_io.h move_pieces.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# flag for GTK configuration
GTK = `pkg-config --libs --cflags gtk+-3.0`

text_runner: text_runner.o position.o piece.o board_state.o square.o text_io.o move_pieces.o
	$(CC) -o text_runner text_runner.o position.o piece.o board_state.o square.o text_io.o move_pieces.o
	

window_runner:
	$(CC) -o window_runner window_runner.c $(GTK)

clean:
	rm text_runner window_runner *.o

