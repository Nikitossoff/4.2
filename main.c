#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include "dynamic_m.h"
int main()
{
    setlocale(LC_ALL, "Russian");
    setlocale(LC_NUMERIC, "C");\
    FILE *in = fopen("input.txt","r");
    int n, m;
    fscanf(in, "%i %i", &n, &m);
    int **A = (int **)malloc(n * sizeof(int *));
    Vvod(in,&A,n,m);


    int min_stb = 0.0;
    float min = 0;
    for (int j = 0; j < m; j++) {
        float current_sr = sr_stb(&A,n,j);
        if (j == 0 || current_sr < min) {
            min = current_sr;
            min_stb = j;
        }
    }
    FILE *out = fopen("output.txt", "w");
    fprintf(out, "Номер столбца, где минимальное ср. арифмитическое: %i\n", min_stb);
    Vivod(out,&A,n,m);
    fclose(in);
    fclose(out);
    printf("Реузльтат успешно записан в output.txt!");
    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);
    return 0;
}
