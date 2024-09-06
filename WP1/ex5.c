// (C) Faiza Amjad, Tehreem Asif Group: 11 __ (2023)
// Work package 1
// Exercise 5
// Submission code: 173324 (provided by your TA-s)

// Include section
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100      // Defines the array of maximum number in the table
#define MAXNUMBER 20 // Defines the maximum value for random numbers

// This function generates a set of random numbers and fills the table *tab with these numbers
void create_random(int *tab)
{
    srand(time(NULL)); // Seed to generate random number
    for (int i = 0; i <= MAX - 1; i++) // loop form 0 to 99 to generate 100 random numbers
    {
        int randNum = (rand() % (MAXNUMBER + 1)); // creates random number between 0 and 20 (including 20)
        tab[i] = randNum;                         // populate the table with random number
    }
}
// creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq)
{
    int i; // counter for outer loop
    int j; // counter for inner loop

    for (i = 0; i < (MAXNUMBER + 1); i++) // iterate over each possible element 0 and MAXNUMBER
    {
        freq[i] = 0;              // Sets counter of specific element to 0
        for (j = 0; j < MAX; j++) // Iterates over the MAX element length array
        {
            if (tab[j] == i) // if the element in array tab matches to the element 0-20
            {
                freq[i]++; // Increases the value of the number
            }
        }
    }
}
// This function draws a histogram of the values in that frequency table
void draw_histogram(int *freq)
{
    for (int i = 0; i < (MAXNUMBER + 1); i++) // iterates over the array of elements 0-20
    {
        if (freq[i] != 0) // skips if it matches 0
        {
            printf("%d\t", i);
            for (int j = 0; j < freq[i]; j++) // prints amount of "x"s equal to the frequency
            {
                printf("x");
            }
            printf("\n");
        }
    }
}

// main function
int main(void)
{
    int i;
    int table[MAX], n;                 // declares an array with max elements
    int frequency[MAXNUMBER];          // declares an array of elements with max numbers
    create_random(table);              // creates a table with an array of 100 random munbers
    count_frequency(table, frequency); // counts elements frequency in the array
    printf("Frequency histogram is as follows:\n");
    draw_histogram(frequency); // prints frequency histogram
}