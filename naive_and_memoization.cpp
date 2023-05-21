//
// Created by cjtorralba on 5/15/23.
//

#include <iostream>

using namespace std;

#define COIN_AMOUNT 12

int memo_table[COIN_AMOUNT + 1];


int memo_table_pebble[4][5];

int field[4][5];

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


    int a = memo_f(n - 4);
    int b = memo_f(n - 3);
    int c = memo_f(n - 1);

    int min = a;

    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }

    memo_table[n] = 1 + min;
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


int pebble_collector(int row_dest, int col_dest) {

    if (row_dest < 0 || col_dest < 0) {
        return 0;
    }
    return field[row_dest][col_dest] + max(pebble_collector(row_dest - 1, col_dest), pebble_collector(row_dest, col_dest - 1));
}



/**
 * Memoization version of the pebble collecting robot
 * @param row_dest
 * @param col_dest
 * @return
 */
int pebble_collector_memo(int row_dest, int col_dest) {

    if (row_dest < 0 || col_dest < 0) {
        printf("Exiting since negative\n");
        return 0;
    } else if (memo_table_pebble[row_dest][col_dest] != -1) {
        printf("\nMemo table hit: %d\n", memo_table_pebble[row_dest][col_dest]);
        return memo_table_pebble[row_dest][col_dest];
    }

//    int max_pebble = max(pebble_collector_memo(row_dest - 1, col_dest), pebble_collector_memo(row_dest, col_dest - 1));

    int a = pebble_collector_memo(row_dest-1, col_dest);
    int b = pebble_collector_memo(row_dest, col_dest-1);

    int max_pebble = a > b ? a : b;

    printf("Max pebble for field[%d][%d]: %d\n", row_dest, col_dest, max_pebble);


    memo_table_pebble[row_dest][col_dest] = max_pebble + field[row_dest][col_dest];

    return memo_table_pebble[row_dest][col_dest];
}


/**
 * Tublar solution to the pebble collector problem
 * Tabular sultion uses an "outer ring" of extra spots of the size field, aka: an extra row and column
 * @param row
 * @param col
 * @return
 */
int pebble_collector_tabular(int row, int col) {



}






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



    // Initialize memo_table_pebble

    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 5; ++j) {
            memo_table_pebble[i][j] = -1;
        }
    }


   cout << "Initializing field" << endl;
    for(int row = 0; row < 4; ++row) {
        for(int col = 0; col < 5; ++col) {
           field[row][col] = 0;
        }
    }

    // Assigning pebbles
    field[0][1] = 1;
    field[0][2] = 1;
    field[1][2] = 1;
    field[1][0] = 1;
    field[1][4] = 1;
    field[1][3] = 1;
    field[3][3] = 1;
    field[2][2] = 1;
    field[3][2] = 1;
    field[3][4] = 1;

    cout << "Displaying Pebble Memo Table" << endl;
    for(int row = 0; row < 4; ++row) {
        for(int col = 0; col < 5; ++col) {
            cout << memo_table_pebble[row][col] << "  ";
        }
        cout << endl;
    }




    cout << "Displaying field" << endl;
    for(int row = 0; row < 4; ++row) {
       for(int col = 0; col < 5; ++col) {
           cout << field[row][col] << "  ";
       }
       cout << endl;
    }


    int max_pebbles = pebble_collector(4, 5);

    cout << "Max pebbles: " << max_pebbles << endl;

    cout << "Max memo pebbles: " << pebble_collector_memo(4,5) << endl;

    cout << "Displaying Pebble Memo Table After Memo Function Call" << endl;
    for(int row = 0; row < 4; ++row) {
        for(int col = 0; col < 5; ++col) {
            cout << memo_table_pebble[row][col] << "  ";
        }
        cout << endl;
    }


    exit(EXIT_SUCCESS);
}
