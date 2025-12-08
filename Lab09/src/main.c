#include <stdio.h>
#include "lib.h"

int main(void) {
    
    int c10 = 0, c5 = 0, c2 = 0, c1 = 0;
    int amount = 28;
    int total_bills = calculate_bills(amount, &c10, &c5, &c2, &c1);

    printf("Сума: %d грн\n", amount);
    printf("Купюри -> 10:%d  5:%d  2:%d  1:%d  (усього=%d)\n",
           c10, c5, c2, c1, total_bills);

    
    double data[] = { 1.0, 2.0, 3.0, 4.0 };
    int N = (int)(sizeof(data) / sizeof(data[0]));
    double mean = incremental_mean(data, N);
    printf("Інкрементальне середнє масиву {1,2,3,4} = %.3f\n", mean);

    return 0;
}

