/**
 ============================================================================
 @name        : Matrix.c
 @author      : Samuel
 @version     : 1
 @copyright   : public
 @details     : Matrix input and read in C, Ansi-style
 ============================================================================
 */

/**
 * @include <stdio.h>
 * @include <stdbool.h>
 * @include <string.h>
 * @include "Matrix.h"
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "Matrix.h"

/**
 * Defines ROW 4, COLUMN 4.
 */
#define ROW 4
#define COLUMN 4

/**
 * @param matrix A.
 * Method to fulfill a matrix.
 */
int inputMatrix(char A[ROW][COLUMN]) {
	strncpy(A[0], "CART", 4);
	strncpy(A[1], "ETAK", 4);
	strncpy(A[2], "ESME", 4);
	strncpy(A[3], "LLPN", 4);
	return 0;
}

/**
 * @param matrix A.
 * Method to read a matrix.
 */
int readMatrix(char A[ROW][COLUMN]) {
	for (int row = 0; row < ROW; row++) {
		for (int column = 0; column < COLUMN; column++) {
			printf("%c  ", A[row][column]);
		}
		puts("");
	}
	return 0;
}
