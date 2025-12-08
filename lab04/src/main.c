#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char input[50];
    double x;
    int integerPart;
    double result;

    printf("Програма працює. Для виходу натисніть 'X'\n\n");

    while (1) {
        printf("Введіть значення x (дріб): ");
        fgets(input, sizeof(input), stdin);

        if (input[0] == 'X' || input[0] == 'x') {
            printf("Вихід з програми.\n");
            break;
        }

        // --- Перевірка на недопустимі символи ---
        int valid = 1;
        for (int i = 0; input[i] != '\0'; i++) {
            if (!(isdigit(input[i]) || input[i] == '.' || input[i] == ',' ||
                  input[i] == '+' || input[i] == '-' || input[i] == '\n')) {
                valid = 0;
                break;
            }
        }

        if (!valid) {
            printf("Помилка: введено недопустимі символи! Вводьте лише цифри, '.', ',', '+', '-'.\n\n");
            continue;
        }

        // --- Замінюємо кому на крапку, щоб atof() правильно спрацював ---
        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] == ',')
                input[i] = '.';
        }

        x = atof(input);
        integerPart = (int)x;

        char *dot = strchr(input, '.');
        if (!dot) {
            printf("Число не має дробової частини, введіть інше.\n\n");
            continue;
        }

        int digits = 0;
        char *p = dot + 1;
        while (*p >= '0' && *p <= '9') {
            digits++;
            p++;
        }

        if (digits == 0) {
            printf("Число не має дробової частини, введіть інше.\n\n");
            continue;
        }

        if (integerPart == 0) {
            printf("Помилка: ділення на 0 неможливе.\n\n");
            continue;
        }

        double fractionalPart = x - integerPart;
        int frac_scaled = (int)(fractionalPart * pow(10, digits) + 0.5);

        result = (double)frac_scaled / integerPart;
        double result_cut = floor(result * 100) / 100.0;

        printf("Ціла частина: %d\n", integerPart);
        printf("Дробова частина (у вигляді цілого): %d\n", frac_scaled);
        printf("Результат без обрізання: %.6f\n", result);
        printf("Результат обрізаний до 2 знаків: %.2f\n\n", result_cut);
    }

    return 0;
}
