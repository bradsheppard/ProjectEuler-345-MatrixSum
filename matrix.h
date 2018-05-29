//
// Created by brad on 28/02/18.
//

#include <stdio.h>

#ifndef PROJECTEULER_MATRIXSUM_MATRIX_H
#define PROJECTEULER_MATRIXSUM_MATRIX_H

typedef struct {
    unsigned int size;
    int **values;
} matrix;

matrix *get_matrix(FILE *matrix_file);
int get_max_sum(matrix *matrix_struct);

#endif