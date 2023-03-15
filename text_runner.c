#include <stdio.h>
#include "board_state.h"

BoardState *boardState;

void initialize_game() {
	boardState = initialize_board(boardState);	
}

int main() {
	puts("Chess game on command line");

	initialize_game();
	printBoard(boardState);

	free_board_state(boardState);
	return 0;
}


