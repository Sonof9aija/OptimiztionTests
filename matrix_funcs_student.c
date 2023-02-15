#include "matrix.h"

void get_every_fifth_student(const matrix_t *matrix, long results[RESULTS_LEN]) {
   long sum1=0,sum2=0,sum3=0,sum4=0,sum5=0;
   int cols;
   for (int rows = 0; rows < matrix->nrows; rows++) {
        for (cols = 0; cols < matrix->ncols - 5; cols += 5){
            sum1 += matrix->data[matrix->ncols * rows + cols];
            sum2 += matrix->data[matrix->ncols * rows + cols + 1];
            sum3 += matrix->data[matrix->ncols * rows + cols + 2];
            sum4 += matrix->data[matrix->ncols * rows + cols + 3];
            sum5 += matrix->data[matrix->ncols * rows + cols + 4];
        }
        for (; cols < matrix->ncols; cols++) {
            int q = cols % RESULTS_LEN;
            results[q] += matrix->data[matrix->ncols*rows+cols];
        }
    }
    results[0] += sum1;
    results[1] += sum2;
    results[2] += sum3;
    results[3] += sum4;
    results[4] += sum5;
}

long get_every_student(const matrix_t *matrix) {
    long ans = 0;
     for (int i = 0; i < matrix->nrows * matrix->ncols; i+=5) {
             ans += matrix->data[i];
             ans += matrix->data[i+1];
             ans += matrix->data[i+2];
             ans += matrix->data[i+3];
             ans += matrix->data[i+4];
     }
    return ans;
}
