/*
 * InputException.c
 *
 *  Created on: Dec 22, 2017
 *      Author: samuel
 */

/**
 * Includes.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "InputException.h"
#include "PLayingField.h"

/**
 * This method checks if the input is good.
 * The input need to be between 0 and 7.
 * @param input.
 * @return the input or 8 if the input is wrong.
 */
int isGoodInput(char input) {
	if (input < '0' || input > '9') {
		puts("‫‪Invalid‬‬ ‫‪input,‬‬ ‫!‪bye-bye‬‬");
		exit(0);
	}
	if (input > '7') {
		puts("‫‪Invalid‬‬ ‫‪input,‬‬ ‫‪the‬‬ ‫‪number‬‬ ‫‪must‬‬ ‫‪be‬‬ ‫‪between‬‬ ‫‪1‬‬ ‫‪to‬‬ ‫‪7:‬‬");
		printField();
		return 8;
	}
	return (input - '0');
}

