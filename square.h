#include <position.h>
#include <piece.h>

typedef struct {
	Position position;
	Piece piece;
} SquareEntity;

SquareEntity *initialize_board_squares();

char *get_square_info(SquareEntity);
