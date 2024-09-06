// (C) Faiza Amjad, Tehreem Asif Group: 11 __ (2023)
// Work package 2
// Exercise 4-code
// Submission code: 777464 (provided by your TA-s)

#include <stdio.h>
#include <stdlib.h>

// Main fubction with command line arguments
int main (int argc, char *argv[]){
    // check if correct number of command line arguments are provided
    if (argc != 6){
        // print error if command line arguments are not equal to six
        fprintf(stderr, "Error: Invalid number of arguments.");
        printf("Please provide %s <engine_on> <gear_pos> <key_pos> <brake1> <brake2>\n", argv[0]);
        return 2; // exit if invalid input with error code 2
    }

    // convert command line arguments into integers
    int engion_on = atoi(argv[1]);
    int gear_pos = atoi(argv[2]);
    int key_pos = atoi(argv[3]);
    int brake1 = atoi(argv[4]);
    int brake2 = atoi(argv[5]);

    // check if input values are in correct range
    if (engion_on < 0 || engion_on > 1 || // if engion_rang is less than o or greater than 1
        gear_pos < 0 || gear_pos > 7 || // if gear_pos is less than 0 or greater than 7
        key_pos < 0 || key_pos > 2 || // if key_pos is less than 0 or greater than 2
        brake1 < 0 || brake1 > 1 || // if brake1 is less than 0 or greater than 1
        brake2 < 0 || brake2 > 1 // if brake 2 is less than 0 or grater than 1
    ){
        fprintf(stderr, "Error: Invalid input values.\n");
        return 2; // exit if invalid input with error code 2
    }

    // create an unsigned char variable to store packed bits 
    unsigned char packed_bit = 0;
    // Use bitwise OR operations to pack the bits into a single byte
    packed_bit |= (engion_on << 7) | (gear_pos << 4) | (key_pos << 2) | (brake1 << 1) | brake2;
    // Print the result in hexadecimal format
    printf("%02X\n", packed_bit);

    return 0; // exit successfully with code 0 
}