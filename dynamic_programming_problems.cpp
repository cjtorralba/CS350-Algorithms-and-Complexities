//
// Created by cjtorralba on 5/20/2023.
//

#include <iostream>
#include <stdlib.h>
#include <cstring>


using namespace std;


void modified_change_problem(int num_coins) {





}





void rod_cutting_problem(int rod_sizes[], int rod_price[], int arr_size ) {


    int* max_price_arr = new int[arr_size];
    memset(max_price_arr, 0, arr_size * sizeof(int));



    printf("Rod size & price: \n");
    // Displaying rods and the prices
    for( int i = 1; i < arr_size; ++i) {
        printf("%d - $%d\n", rod_sizes[i], rod_price[i]);
    }


    //Caululate mx price for each rod going through the array

    for(int i = 1; i < arr_size; ++i) {
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
    int arr_size = 0;

    int** arr_triangle = nullptr;

    // Getting total number of elements in array
    for(int i = num_levels; i > 0; --i) {
        arr_size += i;
    }

    // Allocating inital levels
    arr_triangle = new int*[num_levels+ 1];

    // Allocating each sublevel
    for(int i = 1; i <= num_levels; ++i) {
        arr_triangle[i] = new int[i];
    }

    int current_index = 0;

    // Setting those
    for(int i = 1; i <= num_levels; ++i) {
        for (int j = 0; j < i; ++j) {
            arr_triangle[i][j] = arr[current_index];
            printf("Setting index [%d][%d] to %d\n", i, j, arr[current_index]);
            ++current_index;


        }
    }


    for(int i = 1; i <= num_levels; ++i) {
        printf("Level %d: ", i);
        for (int j = 0; j < i; ++j) {
            printf("%d ", arr_triangle[i][j]);
        }
        printf("\n");
    }



    printf("Number of elements in triangle: %d\n", arr_size);

}




int main (int argc, char** argv) {

    int rod_size[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int rod_price[] =  {0, 1, 5, 8, 9, 10, 17, 16, 20, 14, 12};
    int arr_size = 11;

  //  rod_cutting_problem(rod_size, rod_price, arr_size);




    int num_levels = 4;

    int triangle_nums[] = {          2,
                                  5, 4,
                               1, 4, 7,
                            8, 6, 9, 6 };

    minimum_sum_decent(triangle_nums, num_levels);



    exit(EXIT_SUCCESS);
}


