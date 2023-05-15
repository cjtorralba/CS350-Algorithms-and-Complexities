//
// Created by cjtorralba on 5/15/23.
//

#include <iostream>

using namespace std;

#define COIN_AMOUNT 12

int memo_table[COIN_AMOUNT + 1];

//Naive
/**
 * gets exact minimum amount of coins
 * @param n
 * @return
 */
int naive_f(int n) {
    if (n == 1 || n == 3 || n == 4) {
        return 1;
    } else if (n == 2) {
        return 2;
    }

    int a = naive_f(n - 1);
    int b = naive_f(n - 3);
    int c = naive_f(n - 4);

    int min = a;

    b < min ? min = b : min;

    c < min ? min = c : min;


    return 1 + min;


}


// Memoization
int memo_f(int n) {

    if (memo_table[n] != -1) {
        return memo_table[n];
    }


    int a = naive_f(n - 4);
    int b = naive_f(n - 3);
    int c = naive_f(n - 1);

    int min = a;

    b < min ? min = b : min;

    c < min ? min = c : min;



    memo_table[n] = 1 + min;
    cout << "Updating: memo_table[" << n << "] with value " << 1 + min;
    return memo_table[n];
}


// Using tabulation with n=9;
int tabular_f(int n) {
    for (int k = 5; k <= n; ++k) {
        int a = memo_table[k - 1];
        int b = memo_table[k - 3];
        int c = memo_table[k - 4];

        // Find minimum
        int min = a;
        if (b < min)
            min = b;
        if (c < min)
            min = c;

        memo_table[k] = 1 + min;
    }
    return memo_table[n];
}


/**
 * In class problem, "pebble collector"
 * Imagine a field in a 4x5 grid, we could use a 2d array
 * int field[4][5]
 * In some locations on the field there may be a pebble.
 */











int main(int argc, char **argv) {

    cout << "===Naive===" << endl;
    cout << "Coins: " << COIN_AMOUNT << endl;
    cout << "Exact change: " << naive_f(COIN_AMOUNT) << endl;
    cout << "===========" << endl;

    for (int i = 0; i < COIN_AMOUNT + 1; ++i) {
        memo_table[i] = -1;
        cout << "t[" << i << "] = " << memo_table[i] << endl;
    }

    // Set base cases
    memo_table[1] = 1;
    memo_table[2] = 2;
    memo_table[3] = 1;
    memo_table[4] = 1;

    cout << "===Memoization===" << endl;
    cout << "Coins: " << COIN_AMOUNT << endl;
    cout << "Exact change: " << memo_f(COIN_AMOUNT) << endl;
    cout << "=================" << endl;

//    cout << endl << "Tabulation: " << tabular_f(COIN_AMOUNT) << endl;

    for (int i = 0; i < COIN_AMOUNT + 1; ++i) {
        cout << "t[" << i << "] = " << memo_table[i] << endl;
    }
    exit(EXIT_SUCCESS);
}
