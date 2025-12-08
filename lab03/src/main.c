#include <stdio.h>

int main() {
    int N;
    char input[20];

    while (1) {
        printf("Введіть трицифрове число (або натисніть F2 + Enter для виходу): ");
        fgets(input, sizeof(input), stdin);

        if (input[0] == 27 && input[1] == 'O' && input[2] == 'Q') {
            break;
        }

        if (sscanf(input, "%d", &N) != 1) {
            printf("Помилка: потрібно вводити тільки ціле число!\n");
            continue;
        }

        if ((N > -100 && N < 100) || N > 999 || N < -999) {
            printf("Помилка: введене число не є трицифровим!\n");
            continue;
        }

        int absN = (N < 0) ? -N : N;
        int a = absN / 100;
        int b = (absN / 10) % 10;
        int c = absN % 10;
        int reversed = (c * 100 + b * 10 + a) * ((N < 0) ? -1 : 1);

        printf("Число у зворотному порядку: %d\n", reversed);
    }

    printf("Завершення програми.\n");
    return 0;
}


