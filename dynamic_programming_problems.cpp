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


void minimum_sum_decent(int arr[], int num_levels) {
    // Total number of elements
    int arr_size = 0;

    // THE PYRAMID
    int **arr_triangle = nullptr;

    // THE Optimal moves for each index
    int **optimal_moves = nullptr;

    // Getting total number of elements in array
    for (int i = num_levels; i > 0; --i) {
        arr_size += i;
    }

    // Allocating inital tiers
    arr_triangle = new int *[num_levels + 1];
    optimal_moves = new int *[num_levels + 1];


    // Allocating elements in each level
    for (int level = 1; level <= num_levels; ++level) {
        arr_triangle[level] = new int[level + 1];
        optimal_moves[level] = new int[level + 1];
    }

    // Initial Index for looping though array of numbers
    int current_index = 0;

    // Setting each index
    for (int level = 1; level <= num_levels; ++level) {
        for (int index = 1; index <= level; ++index) {
            // Populate real triangle
            arr_triangle[level][index] = arr[current_index];

            // Populate optimal move array to 0
            optimal_moves[level][index] = -1;


            ++current_index;
        }
    }

    // Displaying pyramid
    for (int level = 1; level <= num_levels; ++level) {
        printf("Level %d: ", level);
        for (int index = 1; index <= level; ++index) {
            printf("%d ", arr_triangle[level][index]);
        }
        printf("\n");
    }





    //========Doing actual calculations now ===========


    // Ours moves, moving right it a 0, moving left is a 1
    unsigned moves = 0;



    // Setting base case
    optimal_moves[1][1] = arr_triangle[1][1];

//    printf("ASLD %d", optimal_moves[1][1]);

    for (int level = 1; level < num_levels; ++level) {

        // Possible routes
        for (int index = 1; index <= level; index++) {
            int sub_index_left = level;
            int sub_index_right = level + 1;

            int move_left;
            int move_right;

            if (optimal_moves[level][index] != -1) {
                move_left = optimal_moves[level][index] + arr_triangle[level + 1][sub_index_left];
                move_right = optimal_moves[level][index] + arr_triangle[level + 1][sub_index_right];

                move_left > move_right ? optimal_moves[level][index] = move_right: optimal_moves[level][index] = move_left;
            } else {
                move_left = arr_triangle[level][index] + arr_triangle[level + 1][sub_index_left];
                move_right = arr_triangle[level][index] + arr_triangle[level + 1][sub_index_right];

                move_left > move_right ? optimal_moves[level][index] = move_right : optimal_moves[level][index] = move_left;
            }
            printf("Tier %d costs: \nMove left cost: %d\nMove right code: %d\n\n", level, move_left, move_right);
        }
    }

    // Now time to traverse through the lists again to find optimal path

    for (int level = 1; level <= num_levels; ++level) {





    }

}


int main(int argc, char **argv) {

    int rod_size[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int rod_price[] = {0, 1, 5, 8, 9, 10, 17, 16, 20, 14, 12};
    int arr_size = 11;

    //  rod_cutting_problem(rod_size, rod_price, arr_size);




    int num_levels = 4;

    int triangle_nums[] = {2,
                           5, 4,
                           1, 4, 7,
                           8, 6, 9, 6};

    minimum_sum_decent(triangle_nums, num_levels);


    exit(EXIT_SUCCESS);
}


