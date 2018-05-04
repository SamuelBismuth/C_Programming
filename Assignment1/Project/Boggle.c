/**
 ============================================================================
 @name        : Boggle.c
 @author      : Samuel
 @version     : 1
 @copyright   : public
 @details     : The boggle, Ansi-style
 ============================================================================
 */

/**
 * @include <stdio.h>
 * @include <stdbool.h>
 * @include <string.h>
 * @include "Boggle.h"
 * @include "Verification.h"
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "Boggle.h"
#include "Verification.h"

/**
 * Defines ROW 4, COLUMN 4.
 */
#define ROW 4
#define COLUMN 4

/**
 * Those statics integer represent the row and the columns of the matrix.
 */
static int row, column;

/**
 * @param A matrix 4 on 4.
 * @param word.
 * @param Abool a matrix of boolean.
 * The method receive all the coordinates of the matrix and with recursion browse all the possible way,
 * without come back into the same coordinates.
 * For all the coordinates, there are for options to go, North, South, East, West.
 * That determine our recursion.
 */
int printWords(char A[ROW][COLUMN], char* word, bool ABool[ROW][COLUMN]) {
	static int count;
	ABool[row][column] = true;
	word[strlen(word)] = A[row][column];
	if (isWord(word))  {
		puts(word);
		count++;
	}
	if ((row + 1) < ROW) { //North.
		row++;
		if (ABool[row][column] == false) printWords(A, word, ABool);
		row--;
	}
	if ((row - 1) >= 0) { //South.
		row--;
		if (ABool[row][column] == false) printWords(A, word, ABool);
		row++;
	}
	if ((column - 1) >= 0) { //East.
		column--;
		if (ABool[row][column] == false) printWords(A, word, ABool);
		column ++;
	}
	if ((column + 1) < COLUMN){ //West.
		column++;
		if (ABool[row][column] == false) printWords(A, word, ABool);
		column--;
	}
	ABool[row][column] = false;
	word[strlen(word) - 1] = '\0';
	return count;
}

/**
 * @param A matrix 4 on 4.
 * @return the number of words we find, by browsing into the matrix, without come back.
 * The algorithm to get all the words is the next one :
 * First of all, the method reads one by one the letter of the matrix (because the words may begin with all the letters of the matrix) :
 * use of a for into another for.
 * This method send to @see printWord all the coordinates of the matrix.
 * Then, @see printWords use recursion to browsing all the way into the matrix.
 */
int sendWords(char A[ROW][COLUMN]) {
	char word[100];
	memset(&word, 0, sizeof(word));
	int count = 0;
	for (row = 0; row < ROW; row++)
		for (column = 0; column < COLUMN; column++) {
			bool ABool[ROW][COLUMN] = {{false}};
			count = printWords(A, word, ABool);
		}
	return count;
}
