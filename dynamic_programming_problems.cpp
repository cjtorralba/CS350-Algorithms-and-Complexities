/**
 * This program if for CS350 - Algorithms and Complexities, Spring 2023, David Ely
 * The purpose of this program is to practice dynamic problem solving. The two problems we are solving here are the
 * Rod-cutting problem, where we try to maximize profits by splitting up each rod into smaller, more expensive pieces,
 * and the minimum-sum-descent problem, where we attempt to find the lowest cost solution to get to the bottom of a pyramid of triangles.
 *
 * @author Christian Torralba
 */


#include <iostream>
#include <cstdlib>
#include <cstring>


using namespace std;

/**
 * This function finds the maximum possible cost for each size of rod by splitting it up into smaller rods.
 * The time complexity of this is function is O(n^2), as we essentially have to loop through the array twice.
 * The time complexity of this specific solution is n^2, as we need two arrays of size n, one to hold the rod sizes, one
 * to hold the rod prices.
 * @param rod_sizes List of the sizes of each Rod
 * @param rod_price List of prices of each rod size, corresponding to the index in the rod_sizes argument
 * @param arr_size  Size of the list
 */
void rod_cutting_problem(int rod_sizes[], int rod_price[], int arr_size) {


    int *max_price_arr = new int[arr_size];
    memset(max_price_arr, 0, arr_size * sizeof(int));


    printf("Rod size & price: \n");
    // Displaying rods and the prices
    for (int i = 1; i < arr_size; ++i) {
        printf("%d - $%d\n", rod_sizes[i], rod_price[i]);
    }


    //Caululate mx price for each rod going through the array

    for (int i = 1; i < arr_size; ++i) {
        int current_price = rod_price[i];
        int current_max_price = current_price;
        // Setting deafult for one right now because I don't want to think about it
        if (i == 1) {
            max_price_arr[i] = current_price;
        }

            // Checking previous array

        else {
            for (int bot = 1, top = i - 1; bot < i && top > 0; ++bot, --top) {
                int combo_price = max_price_arr[bot] + max_price_arr[top];

                if (combo_price > current_max_price) {
                    current_max_price = combo_price;
                }
            }
        }

        max_price_arr[i] = current_max_price;
    }

    for (int i = 1; i < arr_size; ++i) {
        printf("Max price for rod of size %d: %d\n", i, max_price_arr[i]);
    }


}







/**
 * This function is a dynamic solution to the minimum sum descent problem. The time complexity of this is O(n), since
 * We only loop through the numbers N times. Spacial complexity is going to be n*m, where n is the number of levels in the pyramid, and m
 * is the number of elements in the bottom most row.
 * @param pyramid 2D array or integers constructing your triagnle, index starts at [1][1] and ends at [n][n]
 * @param num_levels Number of levels in the pyramid
 * @return
 */
int minimum_sum_decent(int** pyramid, int num_levels) {

   int minimum_sum = INT16_MAX;

    for (int level = num_levels; level > 0; --level) {

        for (int level_index = 1; level_index <= level; ++level_index) {

                // At lowest level, aka our base cases
                if (level == num_levels) {
                    continue;
                }

                else {

                    // Check lower sums

                    int left = pyramid[level+1][level_index];
                    int right = pyramid[level+1][level_index + 1];

                    if (left < right) { // Left is cheaper
                       pyramid[level][level_index] += left;
                    } else { // Right is cheaper
                        pyramid[level][level_index] += right;
                    }

                }
        }

    }

    // Displaying pyramid after setting all the locations
    // Setting each index
    for (int level = 1; level <= num_levels; ++level) {
        printf("Level %d: ", level);
        for (int index = 1; index <= level; ++index) {
            // Populate real triangle
            printf( "%d ", pyramid[level][index]);
        }
        printf("\n");
    }

    return pyramid[1][1];

}


/**
 * This function finds the number of permutations between n and k. The spacial complexity of this function is N*K, and the time complexity of this is O(n^2)
 * @return Number of permutations between N and K
 */
int n_choose_k(int n, int k) {

    // Cannot have k > n
    if (k > n) {
        return -1;
    }

    // Creating 2D array
    int table[n+1][k+1];
    memset(table, 0, sizeof (table));

    // Finding base cases
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= i; ++j) {
            if (j == 1) {
                table[i][j] = i;
            } else if (j == i) {
                table[i][j] = 1;
            }
        }
    }

    // Start form the bottom?
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= i; ++j) {
            if(table[i][j] == 0) {
               table[i][j] = table[i-1][j] + table[i-1][j-1];
            }
        }
    }
    return table[n][k];
}






int main(int argc, char **argv) {

    // Arrays for rod-cutting problem
    int rod_size[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int rod_price[] = {0, 1, 5, 8, 9, 10, 17, 16, 20, 14, 12};
    int arr_size = 11;

    rod_cutting_problem(rod_size, rod_price, arr_size);



    int num_levels = 5;
    int triangle_nums[] = {2,
                           5, 4,
                           1, 4, 7,
                           8, 6, 9, 6,
                           50, 40, 30, 20, 1};

    int** pyramid = NULL;
    // Total number of elements
    arr_size = 0;

    // Getting total number of elements in array
    for (int i = num_levels; i > 0; --i) {
        arr_size += i;
    }

    // Allocating inital tiers
    pyramid = new int *[num_levels + 1];

    // Allocating elements in each level
    for (int level = 1; level <= num_levels; ++level) {
        pyramid[level] = new int[level + 1];
    }

    // Initial Index for looping though array of numbers
    int current_index = 0;

    // Setting each index
    for (int level = 1; level <= num_levels; ++level) {
        for (int index = 1; index <= level; ++index) {
            // Populate real triangle
            pyramid[level][index] = triangle_nums[current_index];
            ++current_index;
        }
    }

    int min_sum = minimum_sum_decent(pyramid, num_levels);
    printf("Minimum sum: %d\n", min_sum);



    int n = 5;
    int k = 3;
    printf("Number of permutations for (%d|%d): %d\n", n, k, n_choose_k(n, k));


    exit(EXIT_SUCCESS);
}


