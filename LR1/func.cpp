#include "func.h"

void write_rand_repeat(int *mas, int n) {
    for (int i = 0; i < n; ++i) {
        mas[i] = rand() % n + 1;
    }
}

bool repeat(int *mas, int end, int value){
    for (int i = 0; i < end; ++i) {
        if(mas[i] == value){
            return false;
        }
    }
    return true;
}

void write_rand_norepeat(int *mas, int n) {
    for (int i = 0; i < n; ++i) {
        int value = rand() % n + 1;
        if (repeat(mas, i, value))
            mas[i] = value;
        else
            i--;
    }
}

void write_order(int *mas, int n) {
    for (int i = 0; i < n; ++i) {
        mas[i] = i + 1;
    }
}

void write_order_opposite(int *mas, int n) {
    for (int i = n - 1; i >= 0; --i) {
        mas[n - i - 1] = i + 1;
    }
}

void out_mas(int *mas, int n) {
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << mas[i] << " ";
    }
    cout << endl;
}

void sort_bubble(int *mas, int n, long long int &comparison, long long int &permutation) {
    for (int i = 1; i < n; ++i) {
        long long int last_perm = permutation;
        for (int j = 0; j < n - i; ++j) {
            comparison++;
            if (mas[j] > mas[j + 1]) {
                permutation++;
                swap(mas[j], mas[j + 1]);
            }
        }
        if (last_perm == permutation){
            break;
        }
    }
}

void sort_comb(int *mas, int n, long long int &comparison, long long int &permutation) {

    double factor = 1.2473309;
    int step = n;
    bool swapped = true;

    while (step > 1 || swapped) {
        step /= factor;
        swapped = false;
        for (int i = 0; i  < n - step; ++i) {
            comparison++;
            if (mas[i] > mas[i + step]) {
                swapped = true;
                permutation++;
                swap(mas[i], mas[i + step]);
            }
        }
        cout << comparison << endl;
    }
}


