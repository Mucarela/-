#ifndef LIB_H
#define LIB_H

int calculate_bills(int amount, int* c10, int* c5, int* c2, int* c1);

/**
 * Обчислює інкрементальне середнє для масиву дійсних чисел.
 * @param arr  вказівник на масив
 * @param size кількість елементів
 * @return середнє значення; якщо size <= 0, результат не визначений
 */
double incremental_mean(const double* arr, int size);

#endif 
