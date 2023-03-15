#include "position.h"
#include <stdlib.h>
#include <string.h>

int position_hashcode(Position p) {
	return p.xy[0] * 8 + p.xy[1];	
}

void number_to_coordinate(Position *p) {
	p->letterNumber[0] = p->xy[0] + 'A';
	p->letterNumber[1] = p->xy[1] + '0';
}

void coordinate_to_number(Position *p) {
	int firstNumber = p->letterNumber[0] - 'A';
	p->xy[1] = p->letterNumber[1] - '0';
	p->xy[0] = firstNumber;
}

char *position_to_string(Position p) {
	// (x, y)
	char *buffer = (char *) malloc(3 * sizeof(char));
	number_to_coordinate(&p);
	strncat(buffer, (char *) &p, 2);
	buffer[2] = '\0';
	return buffer;
}
