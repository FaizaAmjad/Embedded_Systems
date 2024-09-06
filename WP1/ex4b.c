// (C) Faiza Amjad, Tehreem Asif Group: 11 __ (2023)
// Work package 1
// Exercise 4
// Submission code: 173324 (provided by your TA-s)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// main function
int main(int argc, char *argv[]) {
    char binaryInput[100]; // Assuming a maximum input size of 100 characters
    if (scanf("%s", binaryInput) != 1) {
        fprintf(stderr, "Error: Failed to read binary input\n");
        return EXIT_FAILURE;
    }
    printf("Here is the output of dec2bin: %s\n", binaryInput);

    // checks if the second argument is equal to -h or-H and prints help information
    if (binaryInput[0] == '-' && (binaryInput[1] == 'h' || binaryInput[1] == 'H')) {
        printf("Binary number as an input is required: %s <binary_number>\n", argv[0]);
        printf("It will convert a binary number to hexadecimal.\n");
        return 0; // exit with code of 0 for successful execution
    }

    size_t length = strlen(binaryInput); // calculates the length of the string from command-line argument

    // Validate binary input
    // loops through the string
    for (size_t i = 0; i < length; i++) {
        // checks if each value is equal to 0 or 1
        if (binaryInput[i] != '0' && binaryInput[i] != '1') {
            // prints error if it's not a binary number
            fprintf(stderr, "Error: Invalid binary number\n");
            return 2; // exit with code of 2 to inform invalid input
        }
    }

    // Calculate the number of hex digits needed
    size_t hexDigits = (length + 3) / 4;

    // allocate the memory to store the hexadecimal value of the binary number
    char *hexadecimal = (char *)malloc(hexDigits + 1); // +1 is to accommodate the null terminator \0 at the end of the string
    // checks if it successfully allocated memory or not
    if (hexadecimal == NULL) {
        // prints error for failure
        fprintf(stderr, "Error: Memory allocation failed\n");
        return 1; // exit with code of 1 to inform error
    }

    // Convert binary to hexadecimal
    for (size_t i = 0; i < hexDigits; i++) { // where i represents the current position or 4 bit group in whole binary number
        int convertedValue = 0; // intialize variable to hold the value of conversion
        for (size_t j = 0; j < 4; j++) { // where j represents the individual position of bit in current group of 4 numbers
            size_t bitPosition = i * 4 + j; // multiple by 4 to shift position to next group and add value of j to get the exact position of bit
            if (bitPosition < length) {// checks if bit position is within the length of string
            // left-shift operation to 
                convertedValue = (convertedValue << 1) | (binaryInput[length - bitPosition - 1] - '0');
            }
        }
        hexadecimal[hexDigits - i - 1] = (value < 10) ? (char)(value + '0') : (char)(value - 10 + 'A');
    }

    hexadecimal[hexDigits] = '\0';

    // Print the result
    printf("%s\n", hexadecimal);

    // Free allocated memory
    free(hexadecimal);

    return 0;
}
