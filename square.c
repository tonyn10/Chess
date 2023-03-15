#include "square.h"
#include <stdlib.h>
#include <string.h>

SquareEntity *initialize_clean_squares() {
	SquareEntity *squares = (SquareEntity *) malloc(64 * sizeof(SquareEntity));
	for (int i = 0; i < 64; ++i) {
		int numberPosition[] = {i / 8, i % 8};
		squares[i].position.xy[0] = numberPosition[0];
		squares[i].position.xy[1] = numberPosition[1];
		squares[i].piece.type = Empty;
	}

	return squares;
}

void place_black_pieces(SquareEntity *squares) {
	squares[0].piece.type = squares[7].piece.type = Rook;
	squares[1].piece.type = squares[6].piece.type = Knight;
	squares[2].piece.type = squares[5].piece.type = Bishop;
	squares[3].piece.type = Queen;
	squares[4].piece.type = King;

	for (int i = 8; i < 16; ++i) {
		squares[i].piece.type = Pawn;	
	}
}

void place_white_pieces(SquareEntity *squares) {
	for (int i = 48; i < 56; ++i) {
		squares[i].piece.type = Pawn;	
	}

	squares[56].piece.type = squares[63].piece.type = Rook;
	squares[57].piece.type = squares[62].piece.type = Knight;
	squares[58].piece.type = squares[61].piece.type = Bishop;
	squares[59].piece.type = Queen;
	squares[60].piece.type = King;
}

// returns the piece captured
Piece empty_square(SquareEntity *s) {
	Piece p = s->piece;
	s->piece.type = Empty;
	return p;
}

void put_square(SquareEntity *s, PieceType newPieceType) {
	s->piece.type = newPieceType;
}

SquareEntity *get_square(SquareEntity *boardSquares, Position target) {
	return &boardSquares[position_hashcode(target)];
}

char *get_square_info(SquareEntity square) {
	char *buffer = (char *) malloc(50 * sizeof(char));
	char *label[] = {"Pawn", "Knight", "Bishop", "Rook", "Queen", "King", ""};
	strcat(buffer, position_to_string(square.position));
	strcat(buffer, ": ");
	strcat(buffer, label[square.piece.type]);
	return buffer;
}
