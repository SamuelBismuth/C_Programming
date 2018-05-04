/*
 * EndOfTheGame.h
 *
 *  Created on: Dec 20, 2017
 *      Author: samuel
 */

/**
 * Include.
 */
#include <stdbool.h>

/**
 * Global stack.
 */
struct Stack stack;

void isEndOfTheGame(struct Stack* stack, int column, int row);
bool isPlayer(struct Stack* stack, int column, int row, char player);
void end(char player);
