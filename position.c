#include "position.h"
#include <stdlib.h>

int position_hashcode(Position p) {
	return p.x * 8 + p.y;	
}

char *position_to_string(Position p) {
	// (x, y)
	char *buffer = (char *) malloc(6 * sizeof(char));
	buffer[0] = '(';
	buffer[1] = p.x + '0';
	buffer[2] = ',';
	buffer[3] = ' ';
	buffer[4] = p.y + '0';
	buffer[5] = ')';
	return buffer;
}
