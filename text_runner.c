#include <stdio.h>
#include "board_state.h"
#include "text_io.h"
#include "move_pieces.h"

BoardState *boardState;

void initialize_game() {
	boardState = initialize_board(boardState);	
}

void play_game() {
	while (ask_play_game()) {
		print_board(boardState);
		while (boardState->winner == None) {
			
			printf("%s's turn.\n", boardState->currentPlayer->name);

			puts("Pick the square where of the piece you want to move.");
			Position src = receive_square_input();

			puts("Pick the square where you want your piece to go.");
			Position dest = receive_square_input();

			move(boardState->currentPlayer, src, dest);
			print_board(boardState);

			boardState->currentPlayer = boardState->currentPlayer->nextPlayer;
		}
	}
}

int main() {
	puts("Chess game on command line");

	initialize_game();
	play_game();

	free_board_state(boardState);
	return 0;
}


