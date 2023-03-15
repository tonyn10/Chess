#include <position.h>
#include <piece.h>

typedef struct {
	Position position;
	Piece piece;
} SquareEntity;

SquareEntity *initialize_clean_squares();

void place_black_pieces(SquareEntity *);

void place_white_pieces(SquareEntity *);

char *get_square_info(SquareEntity);
