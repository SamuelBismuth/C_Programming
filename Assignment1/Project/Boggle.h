/**
 ============================================================================
 @name        : Boggle.h
 @author      : Samuel
 @version     : 1
 @copyright   : public
 @details     : The boggle, Ansi-style
 ============================================================================
 */

/**
 * @include <stdbool.h>
 */
#include <stdbool.h>

/**
 * Defines ROW 4, COLUMN 4.
 */
#define ROW 4
#define COLUMN 4

int printWords(char A[ROW][COLUMN], char* word, bool ABool[ROW][COLUMN]);
int sendWords(char A[ROW][COLUMN]);
