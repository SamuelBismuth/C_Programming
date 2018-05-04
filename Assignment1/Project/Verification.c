/**
 ============================================================================
 @name        : Verification.c
 @author      : Samuel
 @version     : 1
 @copyright   : public
 @details     : Verification if the word is an English word,, Ansi-style
 ============================================================================
 */

/**
 * @include <stdio.h>
 * @include <stdbool.h>
 * @include <string.h>
 * @include "Verification.h"
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "Verification.h"

/**
 * @param char s.
 * @return true if the word exist.
 * @return false if not.
 * Copy past from the assignment.
 */
bool isWord(char* s) {
	return (!strcmp(s, "CAT") |
			!strcmp(s, "CATS") |
			!strcmp(s, "TRAM") |
			!strcmp(s, "TRAMS") |
			!strcmp(s, "TAME") |
			!strcmp(s, "CAR") |
			!strcmp(s, "CARS") |
			!strcmp(s, "RAT") |
			!strcmp(s, "RATS") |
			!strcmp(s, "RAMP") |
			!strcmp(s, "ART") |
			!strcmp(s, "CART") |
			!strcmp(s, "STAMP") |
			!strcmp(s, "TAKEN") |
			!strcmp(s, "MEN") |
			!strcmp(s, "MAKE") |
			!strcmp(s, "TAKE") |
			!strcmp(s, "ATE") |
			!strcmp(s, "SELL") |
			!strcmp(s, "STEEL") |
			!strcmp(s, "RAKE"));
}
