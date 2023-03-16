
typedef struct {
	char *name1;
	int score1;
	int piecesCount1[6];

	char *name2;
	int score2;
	int piecesCount2[6];
} ScoreBoard;

void update_new_piece_captured(Player *, PieceType);

