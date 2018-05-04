/*
 ============================================================================
 Name        : Question2.c
 Author      : Samuel
 Version     :
 Copyright   : public
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/**
 * Includes.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "Stack.h"

/**
 * This method return 1 if the string is balanced or 0 if not.
 * To do this, this function use a Stack :
 * When the parenthezis is open, the function add it to the stack.
 * When the parenthezis is close, the function do pop to the stack and it must return the inverse of the parenthezis.
 */
bool isStringBalanced(char** sentence, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < strlen(sentence[i]); j++) {
			switch(sentence[i][j]) {
			case '(' :
				push(sentence[i][j]);
				break;
			case '{' :
				push(sentence[i][j]);
				break;
			case '[' :
				push(sentence[i][j]);
				break;
			case ')' :
				if (pop() != '(')
					return 0;
				break;
			case '}' :
				if (pop() != '{')
					return 0;
				break;
			case ']' :
				if (pop() != '[')
					return 0;
				break;
			default:
				break;
			}
		}
	}
	if (sizeStack() != 0)
		return 0;
	return 1;
}

/**
 * The main class for the test.
 */
int main() {
	puts("Welcome !");
	int size = 3;
	char** sentence = calloc(size, sizeof(char*));
	sentence[0] = "hdvbvwchw{";
	sentence[1] = "a}(){}{hi";
	sentence[2] = "()njkncdchwv}()";
	puts("The function return 1 if it's true, 0, if it's false !");
	printf("%d", isStringBalanced(sentence, size));
	return 0;

}
