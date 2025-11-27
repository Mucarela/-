#include <stdio.h>


void clear_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int main(void) {
    int N;

    printf("Введіть N (кількість елементів масиву) > 0:\n");

  
    while (scanf("%d", &N) != 1 || N <= 0) {
        printf("Помилка! Введіть ціле число > 0:\n");
        clear_input();
    }

    double mean = 0.0;
    double x;

    printf("Введіть %d речових чисел:\n", N);

    for (int i = 0; i < N; ++i) {
        printf("Елемент #%d: ", i + 1);

        
        while (scanf("%lf", &x) != 1) {
            printf("Помилка! Потрібно ввести число. Повторіть:\n");
            clear_input();
        }

        int k = i + 1;
        mean = mean + (x - mean) / k;
    }

    printf("Середнє значення: %.6f\n", mean);

    return 0;
}


