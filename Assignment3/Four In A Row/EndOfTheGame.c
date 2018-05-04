/*
 * EndOfTheGame.c
 *
 *  Created on: Dec 20, 2017
 *      Author: samuel
 */

/**
 * Includes.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "EndOfTheGame.h"
#include "PLayingField.h"
#include "Stack.h"

/**
 * Defines.
 */
#define ROW 6
#define COLUMN 7
#define FOUR 4

/**
 * Stack structure.
 */
struct Stack {
	char array[ROW];
	int top;
};

/**
 * Count typedef structure.
 */
typedef struct Count {
	int sum;
	bool flag;
} count;

/**
 * Global field. (Array of stacks).
 */
struct Stack field[COLUMN];

/**
 * This method should check if the game is over.
 * To do this, the method use a structure calling count (defined in the top).
 * In this structure, there are a counter, and a flag.
 * The counter count how much chip there is in a row.
 * The flag begin true, and if the chip is not of the player, become false.
 * Then, the method calculate the sum of all the counter in the structure.
 * If one of this sum is equal to 4, we got a for in a row, then, the game  is over.
 * @param stack.
 * @param column.
 * @param row.
 */
void isEndOfTheGame(struct Stack* stack, int column, int row) {
	char player = field[column].array[row];
	int countDown = 1;
	count rigth = { 1, true };
	count left = { 0, true };
	count diagonalLeftDown = { 1, true };
	count diagonalLeftUp = { 1, true };
	count diagonalRightDown = { 0, true };
	count diagonalRightUp = { 0, true };
	for (int side = 1; side < FOUR; ++side) {
		if (isPlayer(stack, column, row - side, player) == 1) countDown++;
		if (isPlayer(stack, column + side, row, player) == 1 && rigth.flag == 1) rigth.sum++;
		else rigth.flag = false;
		if (isPlayer(stack, column - side, row, player) == 1 && left.flag == 1) left.sum++;
		else left.flag = false;
		if (isPlayer(stack, column - side, row - side, player) == 1 && diagonalLeftDown.flag == 1) diagonalLeftDown.sum++;
		else diagonalLeftDown.flag = false;
		if (isPlayer(stack, column - side, row + side, player) == 1 && diagonalLeftUp.flag == 1) diagonalLeftUp.sum++;
		else diagonalLeftUp.flag = false;
		if (isPlayer(stack, column + side, row - side, player) == 1 && diagonalRightDown.flag == 1) diagonalRightDown.sum++;
		else diagonalRightDown.flag = false;
		if (isPlayer(stack, column + side, row + side, player) == 1 && diagonalRightUp.flag == 1) diagonalRightUp.sum++;
		else diagonalRightUp.flag = false;
	}
	int sumSide = rigth.sum + left.sum;
	int sumFirstDiagonal = diagonalLeftDown.sum + diagonalRightUp.sum;
	int sumSecondDiagonal = diagonalLeftUp.sum + diagonalRightDown.sum;
	if (countDown  == 4 || sumSide == 4 || sumFirstDiagonal == 4 || sumSecondDiagonal == 4) end(player);
}

/**
 * @param stack.
 * @param column.
 * @param row.
 * This method @returns true is the chip is one chip of the player, and @return false if not.
 */
bool isPlayer(struct Stack* stack, int column, int row, char player) {
	if (column < 0 || column > COLUMN || row < 0 || row > ROW) return false;
	if (player == field[column].array[row])
		return true;
	return false;
}

/**
 * This method diplays the message of the end of the game, and exit the game.
 * @param player.
 */
void end(char player) {
	printField();
	printf("Player %c wins!", player);
	exit(0);
}
