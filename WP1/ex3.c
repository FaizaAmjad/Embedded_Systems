// (C) Faiza Amjad, Tehreem Asif Group: 11 __ (2023)
// Work package 1
// Exercise 3
// Submission code: 173324 (provided by your TA-s)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NUMBER 10 // Maximun number of gusses a user can make to guess the number

int main()
{
    int guess = -1;            // initialize user input with -1 to secure pre-execution
    int guessCount = 0;        // counts the number of guesses
    srand(time(0));           // seeds a random number generator based on the actual time
    int r = rand() % 100 + 1; // generates a random number between 1-100
    int roundOver = 0;        // check if the round is over or not

    // loop until the user has guessed the number or reached the maximum number of guesses
    while (guessCount < MAX_NUMBER && guess != r)
    {
        printf("Guess the number: "); // prompts user to guess a number
        scanf("%d", &guess);          // reads input and save in guess variable
        
        // checks if input is lower than the random number
        if (guess < r)
        {
            puts("Your guess is too low. Try again!\n");
        }
        // checks if input is higher than the random number
        else if (guess > r)
        {
            puts("Your guess is too high. Try again!\n");
        }
        // increment the counter for number of guesses
        guessCount++;

        // the user has used the maximum number of guesses
        if (guess == r || guessCount == MAX_NUMBER)
        {
            roundOver = 1; // Sets to 1 if the round is over
            // checks if input is equal to random number
            if (guess == r)
            {
                printf("Your guess is correct after guessing %d times.\n", guessCount);
            }else {
                printf("You have guessed the maximum number of times [%d]\n", guessCount);
            }
            // After the end of one round the user is asked for a new round or to finish
            while (roundOver == 1) {
                char option[2]; // create an array to store the user's input
                printf("Do you wnat to play again? [y/n]: ");
                scanf(" %s", option);

                // compares the input to option variable checking if the user wants to continue
                if (strcmp(option, "y") == 0 || strcmp(option, "Y") == 0)
                {
                    // reset all variables
                    roundOver = 0;
                    guessCount = 0;
                    guess = -1;
                    r = rand() % 100 + 1; // generates a new number
                }
                // compares the input to option variable checking ifs the user does not want to continue
                else if (strcmp(option, "n") == 0 || strcmp(option, "N") == 0)
                {
                    roundOver = 0;
                }
            }
        }
    }

    puts("\nSee you soon. Goodbye!");
    return 0;
}