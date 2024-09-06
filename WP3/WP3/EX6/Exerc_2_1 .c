// (C) Faiza Amjad, Tehreem Asif Group: 11 __ (2024)
// Work package 3
// Exercise 6
// Submission code: 809093 (provided by your TA-s)

#include <stdio.h>
#include <string.h>

// define maximum length of an array
#define MAX 20

// Function to copy string without using library function
void copyString(char copy[], char input[]) {
    int i;
    // loop through the array until end of line reaches and max character has beed read
    for (i = 0; input[i] != '\0' && i < MAX; i++) {
        // copy character from input array
        copy[i] = input[i];
    }
    // add the end of line character to copied array
    copy[i] = '\0';
}

int main(int argc, char argv[]) {
    // add 1 for end of line character '\0'
    char inputString[MAX + 1];
    char copiedString[MAX + 1];
    // Check if a filename is provided as a command-line argument
    if (argc > 1 ) {
        // Open the file to read
        FILE file = fopen(argv[1], "r");

        // Read input from the file
        fgets(inputString, sizeof(inputString), file);
        // Close the file
        fclose(file);
        // Check if file exists

    }  else {
        // Print a message if no filename is provided
        printf("Enter a string up to %d characters: ", MAX);
        // Take input from the console and store it in inputString
        fgets(inputString, sizeof(inputString), stdin);
    }


    // using strcpy to copy string
    strcpy(copiedString, inputString);
    // printing copied string to the console
    printf("\nCopied string using strcpy: %s\n", copiedString);
    // using copyString method to copy the string
    copyString(copiedString, inputString);
    // printing copied string to the console
    printf("\nCopied string using custom function: %s\n", copiedString);

    return 0;
}