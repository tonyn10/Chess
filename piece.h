
#ifndef PIECE
#define PIECE

typedef enum {Pawn, Knight, Bishop, Rook, Queen, King, Empty} PieceType;

typedef struct {
	PieceType type;	
} Piece;

#endif
