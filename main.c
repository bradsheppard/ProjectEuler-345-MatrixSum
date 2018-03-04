#include <stdio.h>
#include "matrix.h"

int main(int c, char **argv) {
    if(c < 2) {
        printf("Must supply values file\n");
        return 0;
    }

    char *matrix_file_name = argv[1];

    FILE *matrix_file = fopen(matrix_file_name, "r");

    if(!matrix_file) {
        printf("Cannot find specified file\n");
        return 0;
    }

    matrix *matrix_struct = get_matrix(matrix_file);
    int max_sum = get_max_sum(matrix_struct);

    printf("Max sum is %d\n", max_sum);

    return 0;
}

