/*
 ============================================================================
 Name        : Matrix.c
 Author      : Samuel
 Version     : 1
 Copyright   : public
 Description : Search into a matrix in C, Ansi-style
 ============================================================================
 */

//include
#include <stdio.h>
#include "Matrix.h"

/**
* \param matrix A.
* Method to fulfill a matrix.
*/
int inputMatrix(char A[4][4]) {
    A[0][0] = 'c';
    A[0][1] = 'a';
    A[0][2] = 'r';
    A[0][3] = 't';
    A[1][0] = 'e';
    A[1][1] = 't';
    A[1][2] = 'a';
    A[1][3] = 'k';
    A[2][0] = 'e';
    A[2][1] = 's';
    A[2][2] = 'm';
    A[2][3] = 'e';
    A[3][0] = 'l';
    A[3][1] = 'l';
    A[3][2] = 'p';
    A[3][3] = 'n';
    return 0;
}

/**
* \param matrix A.
* Method to read array.
*/
int readMatrix(char A[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j ++) {
            printf("%c  ", A[i][j]);
        }
        puts("");
    }
    return 0;
}
