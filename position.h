typedef union {
	int xy[2];
	char letterNumber[2];
} Position;

int position_hashcode(Position);

void number_to_coordinate(Position *);

void coordinate_to_number(Position *);

char *position_to_string(Position);
