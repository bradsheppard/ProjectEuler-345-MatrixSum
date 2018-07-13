//
// Created by brad on 28/02/18.
//

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
        unsigned int size;
        int **values;
} matrix;

unsigned int get_size(FILE *matrix_file) {
        unsigned int rows = 0;
        unsigned int columns = 0;
        unsigned int min_columns = UINT_MAX;

        char c;
        int number_found = 0;

        for (c = (char) getc(matrix_file); c != EOF; c = (char) getc(matrix_file)) {
                if (c == '\n') {
                        rows++;
                        if (columns < min_columns)
                                min_columns = columns;
                        columns = 0;
                        number_found = 0;
                } else if (c != ' ' && !number_found) {
                        columns++;
                        number_found = 1;
                } else if (c == ' ' && number_found)
                        number_found = 0;
        }

        if (rows != min_columns)
                return 0;

        return rows;
}

matrix *get_matrix(FILE *matrix_file) {
        unsigned int size = get_size(matrix_file);

        rewind(matrix_file);

        int **values = calloc(size, sizeof(int *));

        for (int i = 0; i < size; i++) {
                values[i] = calloc(size, sizeof(int));
                for (int j = 0; j < size; j++) {
                        fscanf(matrix_file, "%d", &values[i][j]);
                }
        }

        matrix *matrix_struct = malloc(sizeof(matrix));
        matrix_struct->values = values;
        matrix_struct->size = size;

        return matrix_struct;
}

static int *columns_used;
static int *row_coords;
static int current_sum;

static int *max_remaining;

static int *max_coords;
static int max_sum;

void traverse_row_coords(matrix *matrix_struct, int column_num) {
        unsigned int size = matrix_struct->size;
        int **values = matrix_struct->values;

        for (int i = 0; i < size; i++) {

                if (columns_used[i])
                        continue;
                if (max_remaining[column_num] + current_sum < max_sum)
                        continue;

                columns_used[i] = 1;
                row_coords[column_num] = i;
                current_sum += values[row_coords[column_num]][column_num];

                if (column_num == size - 1 && current_sum > max_sum) {
                        max_sum = current_sum;
                        memcpy(max_coords, row_coords, size * sizeof(int));
                } else
                        traverse_row_coords(matrix_struct, column_num + 1);

                columns_used[i] = 0;
                current_sum -= values[row_coords[column_num]][column_num];
        }
}

void calc_max_remaining(matrix *matrix_struct) {
        unsigned int size = matrix_struct->size;
        int **values = matrix_struct->values;

        max_remaining = calloc(size, sizeof(int));
        int *max_for_column = calloc(size, sizeof(int));

        for (int i = 0; i < size; i++) {
                int current_max = 0;
                for (int j = 0; j < size; j++) {
                        int value = values[j][i];
                        if (value > current_max)
                                current_max = value;
                }
                max_for_column[i] = current_max;
        }

        for (int i = 0; i < size; i++) {
                int sum = 0;
                for (int j = i; j < size; j++) {
                        sum += max_for_column[j];
                }
                max_remaining[i] = sum;
        }

        free(max_for_column);
}

int get_max_sum(matrix *matrix_struct) {
        calc_max_remaining(matrix_struct);

        unsigned int size = matrix_struct->size;

        row_coords = calloc(size, sizeof(int));
        max_coords = calloc(size, sizeof(int));
        columns_used = calloc(size, sizeof(int));

        traverse_row_coords(matrix_struct, 0);


        free(row_coords);
        free(max_coords);
        free(columns_used);

        return max_sum;
}