// (C) Faiza Amjad, Tehreem Asif Group: 11 __ (2023)
// Work package 1
// Exercise 4
// Submission code: 173324 (provided by your TA-s)

// Part 1: Decimal to binary

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of command-line arguments is provided
    if (argc != 2) {
        printf("Please provide a decimal number: %s <decimal_number>\n", argv[0]);
        return 2; // Exit with code 2 to inform invalid input
    }

    // Check if the argument is a help request
    if (argv[1][0] == '-' && (argv[1][1] == 'h' || argv[1][1] == 'H')) {
        printf("Please enter a decimal number after the program names as %s <decimal_number>\n", argv[0]);
        printf("It will convert a decimal number to binary with a minimum of 8 bits.\n");
        return 0; // Exit with code 0 for successful execution
    }

    // Convert the command-line argument into a long integer for mathematical operations
    long decimal = strtol(argv[1], NULL, 10);

    // Check if the conversion to an integer from characters is equal to 0, indicating a failed conversion or starts with 0, in the case of characters or symbols
    if (decimal == 0 && argv[1][0] != '0') {
        // Print error message with standard error stream
        fprintf(stderr, "Error: Invalid decimal number\n");
        return 2; // Exit with code 2 to inform invalid input
    }

    // Ensure a minimum of 8 bits
    //checks if the variable decimal is greater than 0. If true, it sets the variable bits to 8; otherwise, it sets it to 1.
    int bits = (decimal > 0) ? 8 : 1;

    // Calculate the actual number of bits needed
    long temp = decimal; // Create a temporary variable to hold the value of decimal
    while (temp != 0) {  // Continue looping until temp becomes 0
        temp >>= 1;      // Right-shift temp by 1 bit (equivalent to dividing by 2)
        bits++;          // Increment bits, counting the number of iterations
    }

    // Binary representation variables
    if (decimal <= UINT8_MAX) {
        // Using uint8_t variable to store the binary representation
        uint8_t binary_number = 0;

        // Iterate through each bit position in the binary representation
        for (int i = bits - 1; i >= 0; i--) {
            // Shift the existing binary representation to the left by one position
            // Use bitwise OR to set the least significant bit based on the current bit of the decimal number
            binary_number = (binary_number << 1) | ((decimal >> i) & 1);
        }

        // Print the binary representation with a minimum of 8 bits

// Initialize the count of printed bits
        int printedBits = 0;

// Iterate through each bit position in the binary representation (from MSB to LSB)
        for (int i = 7; i >= 0; i--) {
            // Extract the current bit at position i
            int bit = (binary_number >> i) & 1;

            // Check if any bits have been printed or if the current bit is 1
            if (printedBits || bit) {
                // Print the current bit
                printf("%hhu", bit);

                // Increment the count of printed bits
                printedBits++;
            }
        }

        // If no bits were printed, print a single zero
        if (printedBits == 0) {
            printf("0");
        }

        printf("\n");
    } else if (decimal <= UINT16_MAX) {
        // Using uint16_t variable to store the binary representation
        uint16_t binary_number = 0;

        // Iterate through each bit position in the binary representation
        for (int i = bits - 1; i >= 0; i--) {
            binary_number = (binary_number << 1) | ((decimal >> i) & 1);
        }

        // Print the binary representation with a minimum of 8 bits
        int printedBits = 0;
        for (int i = 15; i >= 0; i--) {
            int bit = (binary_number >> i) & 1;
            if (printedBits || bit) {
                printf("%hu", bit);
                printedBits++;
            }
        }

        // If no bits were printed, print a single zero
        if (printedBits == 0) {
            printf("0");
        }

        printf("\n");
    } else if (decimal <= UINT32_MAX) {
        // Using uint32_t variable to store the binary representation
        uint32_t binary_number = 0;

        // Iterate through each bit position in the binary representation
        for (int i = bits - 1; i >= 0; i--) {
            binary_number = (binary_number << 1) | ((decimal >> i) & 1);
        }

        // Print the binary representation with a minimum of 8 bits
        int printedBits = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (binary_number >> i) & 1;
            if (printedBits || bit) {
                printf("%u", bit);
                printedBits++;
            }
        }

        // If no bits were printed, print a single zero
        if (printedBits == 0) {
            printf("0");
        }

        printf("\n");
    } else {
        // Using unsigned long variable to store the binary representation
        unsigned long binary_number = 0;

        // Iterate through each bit position in the binary representation
        for (int i = bits - 1; i >= 0; i--) {
            binary_number = (binary_number << 1) | ((decimal >> i) & 1);
        }

        // Print the binary representation with a minimum of 8 bits
        int printedBits = 0;
        for (int i = 63; i >= 0; i--) {
            int bit = (binary_number >> i) & 1;
            if (printedBits || bit) {
                printf("%u", bit);
                printedBits++;
            }
        }

        // If no bits were printed, print a single zero
        if (printedBits == 0) {
            printf("0");
        }

        printf("\n");
    }

    return 0; // Exit with code 0 for successful execution
}


