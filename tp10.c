#include <stdio.h>
#include <stdlib.h>
#define N_MAX 10
#define M_MAX 10
struct matrix {
    int filas;
    int columnas;
    float mat[N_MAX][M_MAX];
};
typedef struct matrix matrix_t;
void cargar_matriz(matrix_t *p, char *file);
void sumar_matrices(matrix_t A, matrix_t B, matrix_t *pC);
void imprimir_matriz(matrix_t m);
void guardar_matriz(matrix_t m, char *file);
int main(void) {
    matrix_t A = {0}, B = {0};
    matrix_t C = {0};
    printf("Iniciando carga de matrices...\n");
    cargar_matriz(&A, "mat_A.txt");
    cargar_matriz(&B, "mat_B.txt");
    printf("\n--- Matriz A (Leida) ---\n");
    imprimir_matriz(A);
    printf("\n--- Matriz B (Leida) ---\n");
    imprimir_matriz(B);   
    sumar_matrices(A, B, &C);   
    printf("\n--- Matriz Resultado (A + B) ---\n");
    imprimir_matriz(C);   
    guardar_matriz(C, "mat_C.txt");
    printf("\nExito: Resultado guardado en 'mat_C.txt'.\n");
    return 0;
}
void cargar_matriz(matrix_t *p, char *file) {
    FILE *f = fopen(file, "r");    
    if (f == NULL) {
        fprintf(stderr, "Error fatal: no se pudo abrir el archivo '%s'.\nVerifique que el archivo este en la misma carpeta que el ejecutable.\n", file);
        exit(EXIT_FAILURE); 
    }   
    fscanf(f, "%d %d", &p->filas, &p->columnas);  
    for (int i = 0; i < p->filas; i++) {
        for (int j = 0; j < p->columnas; j++) {
            fscanf(f, "%f", &p->mat[i][j]);
        }
    }
    fclose(f);
}
void sumar_matrices(matrix_t A, matrix_t B, matrix_t *pC) {
    if (A.filas != B.filas || A.columnas != B.columnas) {
        fprintf(stderr, "Error: Dimensiones incompatibles para suma (%dx%d vs %dx%d)\n",
                A.filas, A.columnas, B.filas, B.columnas);
        exit(EXIT_FAILURE);
    }
    pC->filas = A.filas;
    pC->columnas = A.columnas;
    for (int i = 0; i < A.filas; i++) {
        for (int j = 0; j < A.columnas; j++) {
            pC->mat[i][j] = A.mat[i][j] + B.mat[i][j];
        }
    }
}
void guardar_matriz(matrix_t m, char *file) {
    FILE *f = fopen(file, "w");  
    if (f == NULL) {
        fprintf(stderr, "Error: no se pudo crear el archivo %s\n", file);
        exit(EXIT_FAILURE);
    }
    fprintf(f, "%d %d\n", m.filas, m.columnas);
    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++) {
            fprintf(f, "%.2f%c", m.mat[i][j], (j == m.columnas - 1) ? '\n' : ' ');
        }
    }
    fclose(f);
}
void imprimir_matriz(matrix_t m) {
    for (int i = 0; i < m.filas; i++) {
        for (int j = 0; j < m.columnas; j++) {
            printf("%9.2f", m.mat[i][j]);
        }
        printf("\n");
    }
}
