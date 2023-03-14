#include "square.h"

typedef enum {White, Black, None} Winner;

typedef struct {
	Winner winner;	
	int moves;
	SquareEntity *boardSquares;
} BoardState;


BoardState *initialize_board();

void printBoard(BoardState *);

void free_board_state(BoardState *);

