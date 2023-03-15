#include "move_pieces.h"

void move(Player *currentPlayer, Position src, Position dest) {
	Player *nextPlayer = currentPlayer->nextPlayer;
	PieceType attackingPieceType = (get_square(currentPlayer->boardSquares, src))->piece.type;
	// replace the square of the opponent's with the attacking piece
	put_square(get_square(nextPlayer->boardSquares, dest), attackingPieceType);
	Piece pieceCaptured = empty_square(get_square(currentPlayer->boardSquares, src));
}
