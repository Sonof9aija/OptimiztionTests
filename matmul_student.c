#include "matrix.h"

void matmul_student(const matrix_t *A, const matrix_t *B, matrix_t *C) {
    int i,j,k;
    for (i = 0; i < A->nrows; i++) {
        for (k = 0; k < A->ncols; k++) {
            for (j = 0; j < B->ncols; j++) {
                C->data[C->ncols * i + j] += A->data[A->ncols * i + k] * B->data[B->ncols * k + j];
            }
        }
    }
}
