#include "lib.h"

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
