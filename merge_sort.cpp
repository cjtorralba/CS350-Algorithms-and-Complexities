/**
  * Merge sort algorithm for CS350, Spring 2023, Portland State university
  * @author Christian Torralba
  * @version 1.0
  * @since 1.0
  */

#include <stdio.h>


/**
 * This function combines the arrays created from splitting the original one
 * @param arr Array to repopulate with sorted data
 * @param left Lower index of arr
 * @param middle Middle index of arr
 * @param right Right index of arr
 */
void combineArrays(double arr[], int left, int middle, int right) {

    int leftArrSize = middle - left + 1;
    int rightArrSize = right - middle;


    // Create temp arrays
    double tempArrLeft[leftArrSize];
    double tempArrRight[rightArrSize];

    // Populate temp arrays
    for (int i = 0; i < leftArrSize; ++i) {
        tempArrLeft[i] = arr[left + i];
    }
    for (int i = 0; i < rightArrSize; ++i) {
        tempArrRight[i] = arr[i + middle + 1];
    }

    int l = 0; //Index of left array
    int r = 0; // Index of right array
    int j = 0;
    for (j = left; j <= right; ++j) {

        if (l == leftArrSize) {                         // Check to see if left array is full
            arr[j] = tempArrRight[r];
	    ++r;
        } 
	
	else if (r == rightArrSize) {                   // Check to see if right array is full
            arr[j] = tempArrLeft[l];
	    ++l;
        } 
	
	else if (tempArrLeft[l] <= tempArrRight[r]) {   //Compare element in left array to one in right
            arr[j] = tempArrLeft[l];
	    ++l;
        } 
	
	else {                                          // If we reached this it means that element in the right array is smaller, or we went horribly wrong with our logic somewhere
            arr[j] = tempArrRight[r];
	    ++r;
        }
    }
}


/**
 * This function splits apart a larger array into half, until we get to individual elements
 * @param arr Array to be sorted
 * @param left Left index of current Array, since this function is recursive
 * @param right Right index of current array
 */
void mergeSort(double arr[], int left, int right) {

	if (left >= right) {
		return;
	}
	int middle = left + (right - left) / 2; // Locate middle of array

	mergeSort(arr, left, middle);  // Recursive call on bottom half of array
	mergeSort(arr, middle + 1, right); // Recursive call on top half of array

	combineArrays(arr, left, middle, right); //Combines/sorts array
}






int main() {

	int n;

	double x[1000], data;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lf", &data);
		x[i] = data;
	}

	// Printing unsorted data
	printf("Unsorted:\n");
	for (int i = 0; i < n; ++i) {
		printf("%d: %lf\n", i, x[i]);
	}

	// Sorting array
	mergeSort(x, 0, n);

	// Printing sorted data
	printf("\nSorted:\n");
	for (int i = 0; i < n; ++i) {
		printf("%d: %lf\n", i + 1, x[i]);
	}


	return 0;
}
