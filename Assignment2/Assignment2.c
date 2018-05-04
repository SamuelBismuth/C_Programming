/*
 ============================================================================
 Name        : Assignment2.c
 Author      : Samuel
 Version     : 1
 Copyright   : public
 Description : Search into a matrix in C, Ansi-style
 ============================================================================
 */

//includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Assignment2.h"
#include "Matrix.h"

/**
* This static int represent the number of the words into the matrix.
*/
static int lenWords = 0;

 /**
 * \param A matrix 4 on 4.
 * \param i the row of the coordinate.
 * \param j the column of the coordinate.
 * \return a char that the function build from the matrix.
 * The method must return an array of char* with all the possibles words beginning by the letter at the coordinate [i][j].
 * To do this, the method use a recursion.
 * For all the coordinates, there is or 2 ways (if (i && j = 0 || 3), or 3 ways (if i || j = 0 || 3 && i != j), or 4 ways (anything else) to connect another letter.
 */
char* sendWords(char A[4][4], int i, int j, char* word, char words[500][100], bool ABool[4][4]) {
     word[strlen(word)] = A[i][j];
     strcpy(words[lenWords++], word);
     ABool[i][j] = false;
     if (i < 4 && j < 4 && i > -1 && j > -1) {
            if (i - 1 > -1 && ABool[i - 1][j] == true) sendWords(A, i - 1, j, word, words, ABool);
            if (i + 1 < 4 && ABool[i + 1][j] == true) sendWords(A, i + 1, j, word, words, ABool);
            if (j - 1 > -1 && ABool[i][j - 1] == true) sendWords(A, i, j - 1, word, words, ABool);
            if (j + 1 < 4 && ABool[i][j + 1] == true) sendWords(A, i, j + 1, word, words, ABool);
     }
     else return "finish";
 }

 /**
 * \param matrix of boolean.
 * This method reinitialize a matrix of boolean by defining all the points as true.
 */
 int reinitialize(bool ABool[4][4]) {
     for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            ABool[i][j] = true;
     return 0;
 }

 /**
 * \param A matrix 4 on 4.
 * \return all the possibilities of words, by browsing into the matrix, without come back.
 * The algorithm to get all the words is the next one :
 * First of all, the method reads one by one the letter of the matrix (because the words may begin with all the letters of the matrix) :
 *use of a for into another for.
 * This method send to \see sendWord all the coordinates of the matrix.
 * Then, \see sendWords should create an array with all the words.
 * The method print all the char* returned by sendWords.
 */
 int printWords(char A[4][4]) {
    char words[500][100];
    char word[100];
    bool ABool[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            memset(word, 0, sizeof(word));
            reinitialize(ABool);
            sendWords(A, i, j, word, words, ABool);
        }
    }
    for (int i = 0; i < lenWords; i++) {
            printf("%d : ", i);
            puts(words[i]);
            fflush(stdout);
    }
    return 0;
 }




/**
* \todo : finish the recursion method.
* \todo : organize with functions and files.
* The main method.
*/
int main() {
	char A[4][4];
    inputMatrix(A);
    readMatrix(A);
	printWords(A);
	return 0;
}
