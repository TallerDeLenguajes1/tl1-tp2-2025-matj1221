#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 7

int main() {
    srand(time(NULL));

    int **dir_mt;
    int i, j;

    dir_mt = (int **)malloc(N * sizeof(int *));

    if (dir_mt == NULL) {
        printf("Error al asignar memoria.\n");
        return -1;
    }

    for (i = 0; i < N; i++) {
        dir_mt[i] = (int *)malloc(M * sizeof(int));
        if (dir_mt[i] == NULL) {
            printf("Error al asignar memoria.\n");
            return -1;
        }
    }  // fin asignación de memoria

    // muestro la matriz generada
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            dir_mt[i][j] = 1 + rand() % 100;
            printf("%i\t", dir_mt[i][j]);
        }
        printf("\n");
    }

    // liberación de memoria

    for (i = 0; i < N; i++) {
        free(dir_mt[i]);
    }
    free(dir_mt);

    return 0;
}
