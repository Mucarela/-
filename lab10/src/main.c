#include <stdio.h>
#include <stdlib.h>


void sort_array(int* arr, size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}


int safe_int_input(const char* msg, int* out) {
    printf("%s", msg);

    if (scanf("%d", out) != 1) {
        printf("Помилка: введено не число!\n");
        return 0; // помилка вводу
    }
    return 1;
}


int safe_size_t_input(const char* msg, size_t* out) {
    printf("%s", msg);

    if (scanf("%zu", out) != 1) {
        printf("Помилка: введено не число!\n");
        return 0;
    }
    return 1;
}

int main(void) {
    size_t N;

    if (!safe_size_t_input("Введіть N: ", &N)) {
        return 1;
    }

    int** matrix = malloc(N * sizeof(*matrix));
    if (!matrix) {
        printf("Помилка виділення пам'яті!\n");
        return 1;
    }

    for (size_t i = 0; i < N; i++) {
        matrix[i] = malloc(N * sizeof(*matrix[i]));
        if (!matrix[i]) {
            printf("Помилка виділення пам'яті!\n");
            return 1;
        }
    }

    printf("Введіть елементи матриці %zu x %zu:\n", N, N);
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            char msg[64];
            snprintf(msg, sizeof(msg), "matrix[%zu][%zu] = ", i, j);

            if (!safe_int_input(msg, &matrix[i][j])) {
                return 1;
            }
        }
    }

    printf("\nВведена матриця:\n");
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }

    int* diag = malloc(N * sizeof(*diag));
    if (!diag) {
        printf("Помилка виділення пам'яті!\n");
        return 1;
    }

    for (size_t i = 0; i < N; i++) {
        diag[i] = matrix[i][i];
    }

    sort_array(diag, N);

    printf("\nГоловна діагональ після сортування: ");
    for (size_t i = 0; i < N; i++) {
        printf("%d ", diag[i]);
    }
    printf("\n");

    for (size_t i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(diag);

    return 0;
}
