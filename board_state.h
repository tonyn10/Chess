#include "square.h"
#include <stdbool.h>

typedef enum {White, Black, None} Winner;

typedef struct Player {
	SquareEntity *boardSquares;
	struct Player *nextPlayer;	
} Player;

typedef struct {
	Winner winner;	
	int moves;
	Player *currentPlayer;
} BoardState;


BoardState *initialize_board();

void printBoard(BoardState *);

void free_board_state(BoardState *);

// receive a string coordinate
bool receiveMove(char *, char *);

