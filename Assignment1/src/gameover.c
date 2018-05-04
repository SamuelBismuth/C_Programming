/**
 ============================================================================
 Name        : gameover.c
 Author      : @author Samuel
 Version     : 1
 Copyright   : public
 Description : Jnim C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "gameover.h"

/**
 * @return true if the user want to continue
 * @return false if the user want to stop
 */
bool tryAgain() {
	int tryAgain;
	printf("input 1 if you want to try again ? \n");
	fflush(stdout);
	scanf("%d", &tryAgain);
	switch(tryAgain) {
	case 1 :
		return true;
		break;
	default :
		exit(EXIT_SUCCESS);
	}
}

/**
 * If the game is over, we print who lost and ask if try again ?
 * @param array
 * @param turnOf
 * @return true if the game is over
 * @return 0 if not
 */
bool endOfTheGame(int array[3], bool turnOf) {
	if(array[2] == 0) { // here, the player who has play lost
		if (turnOf == 1) printf("Game over - I lost !!\n");
		else printf("Game over - You lost !!\n");
		return tryAgain();
	}
	else if(array[1] == 0 && array[2] == 1) { // here, the player who is going to play play lost
		if (turnOf == 1) printf("Game over - You lost !!\n");
		else printf("Game over - I lost !!\n");
		return tryAgain();
	}
	return false;
}
