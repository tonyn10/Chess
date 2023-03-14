#include "square.h"
#include <stdlib.h>
#include <string.h>

SquareEntity *initialize_board_squares() {
	SquareEntity *squares = (SquareEntity *) malloc(64 * sizeof(SquareEntity));
	for (int i = 0; i < 64; ++i) {
		squares[i].position.y = i / 8;
		squares[i].position.x = i % 8;
		squares[i].piece.type = Empty;
	}

	// place initial pieces

	// black's first row
	squares[0].piece.type = squares[7].piece.type = Rook;
	squares[1].piece.type = squares[6].piece.type = Knight;
	squares[2].piece.type = squares[5].piece.type = Bishop;
	squares[3].piece.type = Queen;
	squares[4].piece.type = King;

	// black pawns on 2nd row
	for (int i = 8; i < 16; ++i) {
		squares[i].piece.type = Pawn;	
	}

	// white pawns on 2nd to last row
	for (int i = 48; i < 56; ++i) {
		squares[i].piece.type = Pawn;	
	}

	// white's second row
	squares[56].piece.type = squares[63].piece.type = Rook;
	squares[57].piece.type = squares[62].piece.type = Knight;
	squares[58].piece.type = squares[61].piece.type = Bishop;
	squares[59].piece.type = Queen;
	squares[60].piece.type = King;
		
	return squares;
}

char *get_square_info(SquareEntity square) {
	char *buffer = (char *) malloc(100 * sizeof(char));
	char *label[] = {"Pawn", "Knight", "Bishop", "Rook", "Queen", "King", ""};
	strcat(buffer, position_to_string(square.position));
	strcat(buffer, ": ");
	strcat(buffer, label[square.piece.type]);

	int needToConcat = 15 - strlen(buffer);
	strncat(buffer, "          ", needToConcat);
	return buffer;
}
