// (C) Faiza Amjad, Tehreem Asif Group: 11 __ (2023)
// Work package 1
// Exercise 2
// Submission code: n (provided by your TA-s)

#include <stdio.h>
#include <ctype.h>

// This function shifts caracter in ASCII code table
void shift_char(char *ch, int shift) {
    if (isalpha(*ch)) {
        char base = islower(*ch) ? 'a' : 'A';
        *ch = ((*ch - base + shift) % 26 + 26) % 26 + base;
    }
}
// Checks if it is the end of line otherwise calls shift method to encrypt it
void encrypt_text(char *text, int shift) {
    while (*text != '\0') {
        shift_char(text, shift); // calls the shift-char method 
        putchar(*text); // Displays the character pointed by text
        text++; // increments the pointer 
    }
}
// simple encryption program that shifts characters in the ASCII-code table of a given input string
int main(int argc, char *argv[]) {
    // Checks if there is an argument in command lines
    if (argc != 2) {
        printf("Please specify a number for shifts after program name.\n"
        );
        return 1;
    }

    int shift;
    char buffer[256]; //declares a character array named buffer with a size of 256 element
    // takes command line argument and store in shift variable
    if (sscanf(argv[1], "%d", &shift) != 1) {
        printf("Invalid shift value. Please provide an integer.\n");
        return 1;
    }
    
     // Assuming a maximum line length of 255 characters
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        encrypt_text(buffer, shift);
    }

    return 0;
}



