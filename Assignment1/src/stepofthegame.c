/**
 ============================================================================
 Name        : stepofthegame.c
 Author      : @author Samuel
 Version     : 1
 Copyright   : public
 Description : Jnim C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdbool.h>
#include "stepofthegame.h"
#include "gameover.h"
#include "initialisation.h"
#include "turnof.h"

/**
 * Rules of the game
 */
void rules() {
	printf("The rules of the game are simple.\n"
			"You have to choose three positives numbers, and alternatly,\n"
			"we will choose one of the three numbers, and swap it into a shorter number.\n"
			"The first that happens to some packets size 0 0 0 loose.\n"
			"Be carefull, your input need to be like this :\n"
			"\"The number you want to change\" to \"the number you want\"\n"
			"exemple : 2 to 0\n"
			"Good luck !!\n");
}

/**
 * The method follows the steps of the game
 * @return 0
 */
int stepOfTheGame() {
	rules();
	fflush(stdout);
	int array[3];
	bool turnOf = beginingOfTheGame(array);
	if (endOfTheGame(array, turnOf) == 1) stepOfTheGame();
	while(1) {
		if (turnOf == 1) {
			computerPlay(array);
			if (endOfTheGame(array, turnOf) == 1) stepOfTheGame();
			turnOf = false;
		}
		else {
			bool flag = true;
			if (userPlay(array) == 0) flag = false;
			if (endOfTheGame(array, turnOf) == 1) stepOfTheGame();
			if (flag == 1) turnOf = true;
		}
	}
	return 0;
}

/**
 * The main method
 * @return 0
 */
int main() {
	stepOfTheGame();
	return 0;
}
