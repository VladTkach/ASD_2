#include <iostream>
#include "func.h"

using namespace std;


int main() {
    srand(time(NULL));
    int n;
    cout << "Enter size:";
    cin >> n;
    int *mas = new int[n];
    cout << endl << "Your mas:";

//    write_rand_repeat(mas, n);

//    write_rand_norepeat(mas, n);

    write_order(mas, n);

//    write_order_opposite(mas, n);


    out_mas(mas, n);

    long long int comparison = 0;
    long long int permutation = 0;
//    sort_bubble(mas, n, comparison, permutation);

    sort_comb(mas, n, comparison, permutation);
    cout << endl << "comparison - " << comparison << endl << "permutation - " << permutation << endl;

    cout << endl << "Sort mas:";
    out_mas(mas, n);

    delete[]mas;
}
