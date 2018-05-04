/**
 ============================================================================
 Name        : wronginput.c
 Author      : @author Samuel
 Version     : 1
 Copyright   : public
 Description : Jnim C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdbool.h>
#include "wronginput.h"
#include "stepofthegame.h"
#include "turnof.h"

/**
 * @param numberToSwap
 * @param numberWanted
 * @param array
 * @return true if the input is good
 * @return false if the user made a wrong input, before that the method call @see emptyBuffer
 */
bool input(int numberToSwap, int numberWanted, int array[3]) {
	int var;
	bool flag = false;
	for (var = 0; var < 3; ++var) if(numberToSwap == array[var]) flag = true;
	if(numberToSwap > numberWanted && numberWanted >= 0 && flag) return true;
	else {
		printf("Wrong input, try again... \n");
		emptyBuffer();
		return false;
	}
}

/**
 * If the user made a wrong input, the method call @see emptyBuffer then, @see stepOfTheGame for try again
 * @return 0
 */
int badInput() {
	printf("Wrong input, try again... \n");
	emptyBuffer();
	stepOfTheGame();
	return 0;
}

/**
 * Empty the buffer by read one by one the character present on it
 * @return 0
 */
int emptyBuffer() {
	int c;
	do c = getchar();
	while (c != '\n' && c != EOF);
	return 0;
}
