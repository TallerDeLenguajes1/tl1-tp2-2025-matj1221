#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

struct compu {
    int velocidad;         // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio;              // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos;  // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu;        // Tipo de procesador (apuntador a cadena de caracteres)
};

typedef struct compu compu;

compu pcs[N];

char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

void listarPCS(compu pcs[]);
void mostrarMasVieja(compu pcs[]);

int main() {
    srand(time(NULL));

    int i;

    for (i = 0; i < N; i++) {
        pcs[i].velocidad = 1 + rand() % 3;
        pcs[i].anio = rand() % (2024 - 2015 + 1) + 2015;
        pcs[i].cantidad_nucleos = 1 + rand() % 8;
        pcs[i].tipo_cpu = tipos[rand() % 6];
    }

    // muestro la info
    listarPCS(pcs);

    // muestro la pc mas vieja
    mostrarMasVieja(pcs);

    return 0;
}

void listarPCS(compu pcs[]) {
    int i;
    for (i = 0; i < N; i++) {
        printf("PC: %i\n", i + 1);
        printf("Velocidad: %i GHz\n", pcs[i].velocidad);
        printf("Anio: %i\n", pcs[i].anio);
        printf("Cantidad de nucleos: %i\n", pcs[i].cantidad_nucleos);
        printf("Tipo de CPU: %s\n", pcs[i].tipo_cpu);
        printf("-----------------------------\n");
    }
}

void mostrarMasVieja(compu pcs[]) {
    int i, min = 2025, indexVieja = 0;

    for (i = 0; i < N; i++) {
        if (pcs[i].anio < min) {
            min = pcs[i].anio;
            indexVieja = i;  // me guarda la posicion de la pc mas vieja
        }
    }

    printf("\n\n\nLa PC mas vieja es: \n");
    printf("PC: %i\n", indexVieja + 1);
    printf("Velocidad: %i GHz\n", pcs[indexVieja].velocidad);
    printf("Anio: %i\n", pcs[indexVieja].anio);
    printf("Cantidad de nucleos: %i\n", pcs[indexVieja].cantidad_nucleos);
    printf("Tipo de CPU: %s\n", pcs[indexVieja].tipo_cpu);
}
