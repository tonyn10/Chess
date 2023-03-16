#include "square.h"
#include <stdbool.h>

#ifndef BOARD_STATE
#define BOARD_STATE

typedef enum {White, Black, None} Winner;

typedef struct Player {
	char *name;
	SquareEntity *boardSquares;
	struct Player *nextPlayer;	
} Player;

typedef struct {
	Winner winner;	
	int moves;
	Player *currentPlayer;
} BoardState;


BoardState *initialize_board();

void print_board(BoardState *);

void free_board_state(BoardState *);

#endif
