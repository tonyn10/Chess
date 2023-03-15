#include <position.h>
#include <piece.h>
#include <stdbool.h>

#ifndef SQUARE
#define SQUARE

typedef struct {
	Position position;
	Piece piece;
} SquareEntity;

SquareEntity *initialize_clean_squares();

void place_black_pieces(SquareEntity *);

void place_white_pieces(SquareEntity *);

bool is_empty(SquareEntity);

Piece empty_square(SquareEntity *);

void put_square(SquareEntity *, PieceType);

SquareEntity *get_square(SquareEntity *, Position);

char *get_square_info(SquareEntity);


#endif
