/**
 * @file main.c
 * @brief Лабораторна робота №7. Робота з функціями. Мінімальна кількість купюр та інкрементальне середнє.
 * @author Кулік Артур
 * @date 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/**
 * @brief Обчислює мінімальну кількість купюр номіналами 10, 5, 2, 1 грн.
 * 
 * @param amount Загальна сума для розрахунку.
 * @param c10 Кількість купюр по 10 грн (вихід).
 * @param c5 Кількість купюр по 5 грн (вихід).
 * @param c2 Кількість купюр по 2 грн (вихід).
 * @param c1 Кількість купюр по 1 грн (вихід).
 * @return Загальна кількість купюр, або -1 якщо сума <= 0.
 */
int calculate_bills(int amount, int* c10, int* c5, int* c2, int* c1) {
    if (amount <= 0) return -1;
    *c10 = amount / 10; amount %= 10;
    *c5 = amount / 5;  amount %= 5;
    *c2 = amount / 2;  amount %= 2;
    *c1 = amount;
    return *c10 + *c5 + *c2 + *c1;
}

/**
 * @brief Обчислює інкрементальне середнє для масиву чисел.
 * 
 * @param arr Вказівник на масив чисел.
 * @param size Кількість елементів у масиві.
 * @return Обчислене середнє значення.
 */
double incremental_mean(const double* arr, int size) {
    double mean = 0.0;
    for (int i = 0; i < size; ++i) {
        mean += (arr[i] - mean) / (i + 1);
    }
    return mean;
}

/**
 * @brief Перевіряє, чи рядок є числом (містить лише цифри).
 * 
 * @param str Рядок для перевірки.
 * @return true, якщо всі символи — цифри; інакше false.
 */
bool is_number(const char* str) {
    for (int i = 0; str[i]; ++i) {
        if (!isdigit(str[i])) return false;
    }
    return true;
}

/**
 * @brief Основна функція: обробляє вибір користувача та виконує обрану задачу.
 * 
 * @return 0 при успішному завершенні.
 */
int main(void) {
    printf("--- Lab07: Функції ---\n");
    printf("Оберіть функцію:\n1 — мінімальна кількість купюр\n2 — інкрементальне середнє\nВведіть 1 або 2: ");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        int amount;
        printf("Введіть суму (ціле число): ");
        scanf("%d", &amount);
        int c10 = 0, c5 = 0, c2 = 0, c1 = 0;
        int total_bills = calculate_bills(amount, &c10, &c5, &c2, &c1);
        if (total_bills >= 0) {
            printf("\nСума: %d грн\nМінімальна кількість купюр: %d (10:%d 5:%d 2:%d 1:%d)\n",
                   amount, total_bills, c10, c5, c2, c1);
        } else {
            printf("\nНекоректна сума.\n");
        }
    } else if (choice == 2) {
        int N;
        printf("Введіть кількість елементів: ");
        scanf("%d", &N);
        if (N <= 0) {
            printf("Кількість має бути додатною.\n");
            return 1;
        }
        double* data = malloc(sizeof(double) * (size_t)N);
        for (int i = 0; i < N; ++i) {
            printf("Елемент #%d: ", i + 1);
            scanf("%lf", &data[i]);
        }
        double mean = incremental_mean(data, N);
        printf("\nІнкрементальне середнє: %.3f\n", mean);
        free(data);
    } else {
        printf("Некоректний вибір.\n");
    }
    return 0;
}
