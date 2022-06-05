#pragma once

#include <iostream>
#include <ctime>

using namespace std;

void write_rand_repeat(int *mas, int n);

bool repeat(int *mas, int end, int value);

void write_rand_norepeat(int *mas, int n);

void write_order(int *mas, int n);

void write_order_opposite(int *mas, int n);

void out_mas(int *mas, int n);

void sort_bubble(int *mas, int n, long long int &comparison, long long int &permutation);

void sort_comb(int *mas, int n, long long int &comparison, long long int &permutation);