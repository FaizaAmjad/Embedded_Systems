// (C) Faiza Amjad, Tehreem Asif Group: 11 __ (2023)
// Work package 2
// Exercise 2
// Submission code: 777464 (provided by your TA-s)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#### Constants #####
#define MAX 5

// ##### typedefs ####
typedef struct q{
    int number; // holds the value of the node
    struct q *next; // is the node which points to next node
    struct q *prev; // is the node which points to the previous one
} REGTYPE;

// ##### Function declarations #####
REGTYPE* random_list(void); // pointer to a node is returned
REGTYPE* add_first(REGTYPE* temp, int data); // adds data to the node and returns it

//###### Main program #######
int main(int argc, char *argv[]) {
    int nr = 0; // initialising a counter for the number of nodes
    REGTYPE *act_post, *head = NULL; // initializing pointers for first(header) and current nodes(act_post)
    srand(time(0)); // Random seed
    head = random_list(); // set head to the first node of the linked list

    // Add a new record to the beginning of the list
    head = add_first(head, 99); // Adding a new record with 'number' value 99

    act_post = head; // set current pointer to the first node

    // Traverse the list and print the values
    while (act_post != NULL) {
        // Print the value of the current node with the post nr
        printf("\n Post nr %d : %d\n", nr, act_post->number);
        nr++;
        act_post = act_post->next; // move to the next node
    }

    // Free the allocated memory
    while ((act_post = head) != NULL) {
        head = act_post->next; // move head to the next node
        free(act_post); // free memory of the current node
    }
    return 0; // exit with code of 0 for successful execution
}

// Function to create a linked list with a NUMBER of records of type REGTYPE,
// where the value of the variable 'number' is given a random number between 0 and 100.
REGTYPE* random_list(void ){
    int nr, i = 0; // initialising number of nodes counter and for loop counter variable respectively
    REGTYPE *top = NULL, *old = NULL, *item = NULL; // declaring the nodes regtype for top node, previous node (meaning next in list) and current pointed node
    nr = MAX; // equating nr to max so that the number of elements do not exceed max amount
    for (i = 0; i < MAX; i++) { // for loop runs through each element of the list unless it's max-5
        item = (REGTYPE*)malloc(sizeof(REGTYPE)); // allocating memory to item regtype
        if (item == NULL) { // if the node is not already allocated memory it fails
            fprintf(stderr, "Memory allocation failed.\n"); // print error in the error stream
            exit(EXIT_FAILURE); // exits the program with error
        }
        // Assigning a random number to 'number' field
        item->number = rand() % 101; // return data for the item pointer add value for it
        item->prev = old; // set prev to old node
        item->next = NULL; // next is null because of the end node
        if (old != NULL) {
            old->next = item; // if old exists then we set a next for old to the current item
        }
        old = item; // equate item to old for the next values
        // If top is not pointing to any node (i.e., it's NULL), assign it to the current node
        if(i == 0 && top == NULL) {
            top = item;
        }
    }
    return top; // Return the pointer to the first node
}

// Function to add a new record to the first position of the list and assign the field 'number' the value of 'data'.
REGTYPE* add_first(REGTYPE* temp, int data) {
    REGTYPE *new_node = (REGTYPE*)malloc(sizeof(REGTYPE)); // allocate memory for the new node
    if (new_node == NULL) { // check if memory allocation failed
        fprintf(stderr, "Memory allocation failed.\n"); // print error message
        exit(EXIT_FAILURE); // exit the program
    }
    // Assigning 'data' to the 'number' field
    new_node->number = data; // set the number of the new node
    new_node->prev = NULL; // set the previous pointer of the new node to NULL
    new_node->next = temp; // set the next pointer of the new node to point to the previous first node
    if (temp != NULL) {
        temp->prev = new_node; // set the previous pointer of the previous first node to point to the new node
    }
    return new_node; // Return the pointer to the new first node
}
