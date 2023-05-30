//
// Created by cjtorralba on 5/20/2023.
//

#include <iostream>
#include <cstdlib>
#include <cstring>


using namespace std;


void modified_change_problem(int num_coins) {


}


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


int main(int argc, char **argv) {

    int rod_size[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int rod_price[] = {0, 1, 5, 8, 9, 10, 17, 16, 20, 14, 12};
    int arr_size = 11;

    //  rod_cutting_problem(rod_size, rod_price, arr_size);




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
            printf("Inserting %d into pyramid[%d][%d]\n", triangle_nums[current_index], level, index);
            pyramid[level][index] = triangle_nums[current_index];
            ++current_index;
        }
    }


    int min_sum = minimum_sum_decent(pyramid, num_levels);

    printf("Minimum sum: %d", min_sum);


    exit(EXIT_SUCCESS);
}


