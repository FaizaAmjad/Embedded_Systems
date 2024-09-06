// (C) Faiza Amjad, Tehreem Asif Group: 11 __ (2023)
// Work package 1
// Exercise 1
// Submission code: 173324 (provided by your TA-s)

#include <stdio.h>
#include <string.h>

// Main function in the program, reads in an integer number between 1 and 5 from the keyboard
// Prints out one of existing five unique sentences on the console depending on the number entered
int main() {
    // Declare an integer variable to store user input
    int userInput;
    // Continue to run program
    while (1) {
        // Print a string to prompt user input
        printf("Choose a number from 1 to 5: ");
        // If user enters a non-integer value
        if (scanf("%d", &userInput) != 1) {
            // Print a string to show error
            printf("Invalid input. Please enter a valid integer.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }
        // Print a unique sentence based on the entered number
        if ( userInput == 1 ) {
            // Print a unique sentence
            printf("Hi! You choose option %d. Good to see You.\n", userInput);
        }else  if ( userInput == 2 ) {
            // Print a unique sentence
            printf("You choose option %d. Hope you had a good day today.\n", userInput);
        }else  if ( userInput == 3 ) {
            // Print a unique sentence
            printf("You choose option %d. Always beleive in yourself.\n", userInput);
        }else  if ( userInput == 4 ) {
            // Print a unique sentence
            printf("You choose option %d. Learning is a life long journey.\n", userInput);
        }else  if ( userInput == 5 ) {
            // Print a unique sentence
            printf("You choose option %d. Wishing you a very Good Luck!\n", userInput);
        }else {
            // Exit the program if number is not in the interval 1 to 5
            // Print a sentence
            printf("You choose option %d. It's not between 1 & 5. Hope to see you again. Bye!\n", userInput);
            return 0;
        }
    }

    return 0;
}
