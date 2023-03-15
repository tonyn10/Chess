#include "text_io.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

Position receive_square_input() {
	size_t inputSize = 3;
	char *input = NULL;		
	ssize_t charactersRead;

	printf("Enter a square (letter, number): ");
	do {
		if (input) {
			puts("Invalid square. Try again.");
		}
		charactersRead = getline(&input, &inputSize, stdin);
		// make sure only 3 characters were inputted (letter, number, line break)
	} while (charactersRead != 3 || !valid_first_char(&input[0]) || !valid_second_char(input[1]));

	Position p;
	p.letterNumber[0] = input[0];
	p.letterNumber[1] = input[1];
	flip_axis(&p);
	coordinate_to_number(&p);
	return p;
}

// returns true if the user wants to play a game
bool ask_play_game() {
	size_t inputSize = 2;
	char *input = NULL;		
	ssize_t charactersRead;

	printf("Do you want to play chess? (y/Y/n/N): ");	
	do {
		if (input) {
			puts("Didn't receive valid answer (y/Y/n/N). Try again.");
		}
		charactersRead = getline(&input, &inputSize, stdin);
		// make sure only 2 characters were inputted (letter, number, line break)
	} while (charactersRead != 2 || !valid_yes_no(input[0]));

	char answer = tolower(input[0]);
	free(input);
	return answer == 'y';
}

bool valid_yes_no(char c) {
	return c == 'y' || c == 'n' || c == 'Y' || c == 'N';
}

bool valid_first_char(char *c) {
	if (!isalpha(*c)) {
		return false;
	}

	*c = toupper(*c);
	// no need to check less than 'A' because there are no alpha letters in that range
	if (*c > 'H') {
		return false;
	}
	return true;
}

bool valid_second_char(char c) {
	if (!isdigit(c)) {
		return false;
	}
	if (c == '0' || c == '9') {
		return false;
	}
	return true;
}
