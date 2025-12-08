#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char input[50];
    int S;

    printf("Програма визначає мінімальну кількість купюр (1, 2, 5, 10 грн)\n");
    printf("Для виходу натисніть X і Enter.\n\n");

    while (1) {
        printf("Введіть суму S (грн): ");
        fgets(input, sizeof(input), stdin);

        
        if (input[0] == 'X' || input[0] == 'x') {
            printf("Вихід з програми.\n");
            break;
        }

        
        int valid = 1;
        for (int i = 0; input[i] != '\0'; i++) {
            if (!(isdigit(input[i]) || input[i] == '\n')) {
                valid = 0;
                break;
            }
        }

        if (!valid) {
            printf("Помилка: введено недопустимі символи! Вводьте лише цифри.\n\n");
            continue;
        }

        S = atoi(input);

        if (S <= 0) {
            printf("Помилка: сума має бути додатною!\n\n");
            continue;
        }

       
        int c10 = S / 10; S %= 10;
        int c5  = S / 5;  S %= 5;
        int c2  = S / 2;  S %= 2;
        int c1  = S;

        int total = c10 + c5 + c2 + c1;

        printf("\nМінімальна кількість купюр: %d\n", total);
        printf("10 грн: %d\n", c10);
        printf("5 грн : %d\n", c5);
        printf("2 грн : %d\n", c2);
        printf("1 грн : %d\n\n", c1);
    }

    return 0;
}
