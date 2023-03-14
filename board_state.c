#include "board_state.h"
#include <stdlib.h>
#include <stdio.h>

BoardState *initialize_board() {
	BoardState *boardState = (BoardState *) malloc(sizeof(BoardState));
	boardState->winner = None;
	boardState->moves = 0;
	boardState->boardSquares = initialize_board_squares();
	return boardState;
}

void printBoard(BoardState *boardState) {
	SquareEntity *squares = boardState->boardSquares;
	for (int i = 0; i < 64; ++i) {
		if (i && !(i % 8)) {
			printf("\n\n");
		}

		char *buffer = get_square_info(squares[i]);
		printf("%s  ", buffer);
		free(buffer);
	}
	printf("\n");
}

void free_board_state(BoardState *boardState) {
	free(boardState->boardSquares);	
	free(boardState);
}

