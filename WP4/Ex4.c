// (C) Faiza Amjad, Tehreem Asif Group: 11 __ (2024)
// Work package 4
// Exercise 4
// Submission code: 453182 (provided by your TA-s)

#include <stdio.h>
// function to find a number in an array
// takes a number, array and size of array as parameters
int search_number(int number, int tab[], int size) {
    // loop to check a number in an array
    for (int i = 0; i < size; i++) {
        if (tab[i] == number) {
            return i; // Return the index of the first occurrence of the number
        }
    }
    return -1; // Return -1 if the number is not found in the array
}


void sort(int number, int tab[]) {
    for (int i = 0; i < number - 1; i++) {
        for (int j = i + 1; j < number; j++) {
            //find minimum value in the lists
            if (tab[j] < tab[i]) {
                // Swap the elements if they are in the wrong order
                int temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
}

int main() {
    // declaration of an array
    int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};
    // divide the size of an array in bytes by the one element in bytes to get the total elements
    int size = sizeof(test) / sizeof(test[0]);

    // Test the search_number function
    int number_to_search = 23; // hard coded number to search

    // store the return index from the search method
    int index = search_number(number_to_search, test, size);

    // print if number exists 
    if (index != -1) {
        printf("Number %d found at index %d.\n", number_to_search, index);
    } else {
        printf("Number %d not found in the array.\n", number_to_search);
    }

    // Test the sort function
    sort(size, test);// given the array size and the array to sort

    // Print the sorted array
    printf("Sorted array: ");
    // print each element of sorted array
    for (int i = 0; i < size; i++) {
        printf("%d ", test[i]);
    }
    printf("\n");

    return 0; // exit with the code 0 for successful execution
}
