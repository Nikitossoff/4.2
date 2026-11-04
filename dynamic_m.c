#include "dynamic_m.h"
#include <malloc.h>
void Vvod(FILE *in, int ***x, int n, int m) {
    for (int i = 0; i < n; i++) {
        (*x)[i] = (int *)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++){
            fscanf(in, "%i", &(*x)[i][j]);
        }
    }
}
float sr_stb(int ***x,int n, int index){
   float sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += (*x)[i][index];
    }
    return sum / n;
}
void Vivod(FILE *out, int ***x, int n, int m) {
    fprintf(out, "==================================\n");
    fprintf(out, "Исходный массив:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(out, "%3i ", (*x)[i][j]);
        }
        fprintf(out, "\n");
    }
    fprintf(out, "\n");
    return;
}
