#include "move_pieces.h"

void move(Player *currentPlayer, Position src, Position dest) {
	Player *nextPlayer = currentPlayer->nextPlayer;
	// remove currentPlayer's piece at src
	PieceType attackingPieceType = empty_square(get_square(currentPlayer->boardSquares, src));
	// move it to dest
	put_square(get_square(currentPlayer->boardSquares, dest), attackingPieceType);
	// remove the piece on opponent's board
	PieceType pieceCaptured = empty_square(get_square(nextPlayer->boardSquares, dest));
}
