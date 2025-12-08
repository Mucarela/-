# МІНІСТЕРСТВО ОСВІТИ І НАУКИ УКРАЇНИ  
# НАЦІОНАЛЬНИЙ ТЕХНІЧНИЙ УНІВЕРСИТЕТ «ХАРКІВСЬКИЙ ПОЛІТЕХНІЧНИЙ ІНСТИТУТ»

## Навчально-науковий інститут комп’ютерних наук та інформаційних технологій  
## Кафедра комп’ютерної інженерії та програмування

---

# ЗВІТ  
## Лабораторна робота №7  
### Функції

---

### Виконав: студент групи **КН-925б**  
**Кулік Артур Єдурдович**

### Перевірив:  
доцент кафедри КІП  
**Лисиця Дмитро Олександрович**

---

# Тема  
**Функції**

# Мета роботи  
Навчитися створювати користувацькі функції у мові С, передавати параметри, повертати значення, застосовувати інкрементальні обчислення та обробляти користувацьке введення.

---

# Завдання

1. Створити функцію для обчислення мінімальної кількості купюр для заданої суми.  
2. Створити функцію для обчислення інкрементального середнього з N чисел.  
3. Організувати вибір функції користувачем у меню.  
4. Реалізувати повну перевірку введення.  
5. Виводити результати роботи кожної функції.

---

# Код програми

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

int calculate_bills(int amount, int* c10, int* c5, int* c2, int* c1) {
    if (amount <= 0) return -1;
    *c10 = amount / 10; amount %= 10;
    *c5 = amount / 5;  amount %= 5;
    *c2 = amount / 2;  amount %= 2;
    *c1 = amount;
    return *c10 + *c5 + *c2 + *c1;
}

double incremental_mean(const double* arr, int size) {
    double mean = 0.0;
    for (int i = 0; i < size; ++i) {
        mean += (arr[i] - mean) / (i + 1);
    }
    return mean;
}

bool is_number(const char* str) {
    for (int i = 0; str[i]; ++i) {
        if (!isdigit(str[i])) return false;
    }
    return true;
}

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
            printf(
                "\nСума: %d грн\nМінімальна кількість купюр: %d (10:%d 5:%d 2:%d 1:%d)\n",
                amount, total_bills, c10, c5, c2, c1
            );
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
```
# Висновки

У ході виконання лабораторної роботи створено програму з меню вибору функцій. Одна функція обчислює мінімальну кількість купюр для заданої суми, інша — інкрементальне середнє. 
