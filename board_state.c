#include "board_state.h"
#include <stdlib.h>
#include <stdio.h>

BoardState *initialize_board() {
	BoardState *boardState = (BoardState *) malloc(sizeof(BoardState));
	boardState->winner = None;
	boardState->moves = 0;

	Player *white = (Player *) malloc(sizeof(Player));
	Player *black = (Player *) malloc(sizeof(Player));

	white->name = "White";
	black->name = "Black";

	white->boardSquares = initialize_clean_squares();
	place_white_pieces(white->boardSquares);
	white->nextPlayer = black;

	black->boardSquares = initialize_clean_squares();
	place_black_pieces(black->boardSquares);
	black->nextPlayer = white;

	boardState->currentPlayer = white;

	return boardState;
}

void printBoard(BoardState *boardState) {
	for (int i = 0; i < 64; ++i) {
		if (i && !(i % 8)) {
			printf("\n\n");
		}

		SquareEntity chosenSquare;
		if (boardState->currentPlayer->boardSquares[i].piece.type != Empty) {
			chosenSquare = boardState->currentPlayer->boardSquares[i];
		} else {
			chosenSquare = boardState->currentPlayer->nextPlayer->boardSquares[i];
		}		

		char *buffer = get_square_info(chosenSquare);
		printf("%-18s", buffer);
		free(buffer);
	}
	printf("\n\n");
}

void free_board_state(BoardState *boardState) {
	Player *player1 = boardState->currentPlayer;
	Player *player2 = boardState->currentPlayer->nextPlayer;
	free(player1->boardSquares);
	free(player2->boardSquares);
	free(player1);	
	free(player2);	
	free(boardState);
}

