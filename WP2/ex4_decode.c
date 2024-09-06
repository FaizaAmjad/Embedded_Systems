// (C) Faiza Amjad, Tehreem Asif Group: 11 __ (2023)
// Work package 2
// Exercise 4-decode
// Submission code: 777464 (provided by your TA-s)

#include <stdio.h>
#include <stdlib.h>
// main function
int main(int argc, char *argv[]) {
    if (argc != 2) { // if number of arguments are not equal to 2
        printf("Error: Invalid number of arguments. Usage: %s <hex_value>\n", argv[0]);
        return 1; // exit with error code 1
    }

    // Parse the hexadecimal value from the command line argument
    unsigned char hex_value; // variable to store input
    if (sscanf(argv[1], "%2hhx", &hex_value) != 1) { // reads and checks if first argument is hexadecimal value 
        printf("Error: Invalid hexadecimal value.\n");
        return 1; // exit with error code 1
    }

    // Unpack values from the byte
    // Compare the position of the value and shifts left to unpack
    int engine_on = (hex_value & 0x80) >> 7; 
    int gear_pos = (hex_value & 0x70) >> 4;
    int key_pos = (hex_value & 0x0C) >> 2;
    int brake1 = (hex_value & 0x02) >> 1;
    int brake2 = hex_value & 0x01;

    // Print the result
    printf("Name\t\tValue\n");
    printf("-----------------------------\n");
    printf("engine_on\t%d\n", engine_on);
    printf("gear_pos\t%d\n", gear_pos);
    printf("key_pos\t\t%d\n", key_pos);
    printf("brake1\t\t%d\n", brake1);
    printf("brake2\t\t%d\n", brake2);

    return 0; // exit with code 0
}
