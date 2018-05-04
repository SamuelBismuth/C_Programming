/*
 ============================================================================
 Name        : Main.c
 Author      : Samuel
 Version     :
 Copyright   : public
 Description : For in a row in C, Ansi-style
 ============================================================================
 */

/**
 * Includes
 */
#include <stdio.h>
#include <stdlib.h>

#include "PLayingField.h"
#include "StepOfTheGame.h"

/**
 * Main method.
 * Display the "welcome" message, and, into an infinite loop, call the function playerX and playerO.
 */
int main() {
	puts("Welcome!");
	initialisation();
	while (1) {
		playerX();
		playerO();
	}
	return EXIT_SUCCESS;
}



