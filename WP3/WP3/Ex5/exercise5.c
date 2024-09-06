// (C) Faiza Amjad, Tehreem Asif Group: 11 __ (2024)
// Work package 3
// Exercise 5
// Submission code: 809093 (provided by your TA-s)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//is the user supposed to enter the max or we define it??
int main() {
    int MAX=5;//initialises max to be 5
    int randomArray[MAX];//array created with space for 5 integers
    int numberCreated= -1;//initialising random number created variable with -1 as it is not possible
    int i; //counter
    srand(time(0)); // Random seed
    for(i=0; i<MAX; i++){//loop runs until the whole array is iterated over
        numberCreated= rand() % (100-1) + 98;//creates random number between 1-99
        randomArray[i]=numberCreated;//adds random integer to array
    }
    //printing results after the loop has gone through each element
    //%p to print MEMORY ADDRESSES, gives result in hexadecimal (hopefully)
    //void * is a generic pointer type that can hold the address of any data type.
    printf("The value of the address of the array (pointer) is: %p \n", (void *)&randomArray);//pointer to the array
    printf("First integer in the array is: %d \n",(randomArray[0]));//first element at index 0
    printf("The last integer in the array is: %d \n", randomArray[MAX-1] ); //last element at index max-1
    //%zu- u means unsigned(positive) and z means of time size-t
    printf("The size of an integer (number of bytes) is: %zu \n", sizeof(int));//sizeof returns size of integer type in bytes
    printf("The size of the whole array in bytes is: %zu \n", sizeof(randomArray));//sizeof returns size of the whole array in bytes

    //printing each integer value and its double with help of a pointer(array)
    for(i=0;i<MAX; i++){
        printf("%d.Integer value: %d, Doubled value: %d \n",i+1 ,randomArray[i], randomArray[i] * 2);//array is a pointer so with its help we're printing
    }

    return 0;
}

//GOOD TO KNOW
//IN C when we use the array name it naturally is a pointer to the first element in the array eg printf("%p,array"); this will print first element address
//if you want the whole address of the array(pointer) then use '&'array
//size_t is an unsigned integer data type used to represent sizes of objects in bytes