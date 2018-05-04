/**
 ============================================================================
 @name        : Main.c
 @author      : Samuel
 @version     : 1
 @copyright   : public
 @details     : The main method, Ansi-style
 ============================================================================
 */

/**
 * @include <stdio.h>
 * @include <stdbool.h>
 * @include <stdlib.h>
 * @include <string.h>
 * @include "Matrix.h"
 * @include "Boggle.h"
 * @include "Verification.h"
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Matrix.h"
#include "Verification.h"
#include "Boggle.h"

/**
 * Defines ROW 4, COLUMN 4.
 */
#define ROW 4
#define COLUMN 4

/**
 * The main method.
 * first input the matrix.
 * Then, read it.
 * Finally begin the boggle.
 */
int main() {
	char A[ROW][COLUMN];
	inputMatrix(A);
	puts("The matrix :");
	readMatrix(A);
	puts("###############################################");
	puts("We begin the boogle :");
	printf("###############################################\nThe number of words is : %d.", sendWords(A)); //Print the number of words (24).
	return 0;
}
