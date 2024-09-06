// (C) Faiza Amjad, Tehreem Asif Group: 11 __ (2023)
// Work package 2
// Exercise 1
// Submission code: 777464 (provided by your TA-s)
#include <stdio.h>
#include <string.h>

enum DIRECTION {N,E, S, W}; //enum defined for constants of DIRECTION {North,East,South,West};
typedef struct { //defining a struct for the robot including the x, y coordinates and travel direction
    int xpos;  //x-coordinate (E-w direction additions will add to it or subtract)
    int ypos;  //y-coordinate (N-s direction additions will add to it or subtract)
    enum DIRECTION dir; //direction variable enum
} ROBOT;
void turn(ROBOT *thisRobot);//declaring turn function
void move(ROBOT *thisRobot); //declaring move function
char nameDir(ROBOT *thisRobot); //DECLARING FUNCTION to make direction string

//the program takes no arguments
int main(void) {

    ROBOT myRobot; //initialising a ROBOT to use throughout the function
    //initialising the variables for myRobot ROBOT to set the initial values
    myRobot.xpos= 0;
    myRobot.ypos=0;
    myRobot.dir= N; //set to north as every time robot start direction is north

    //A while true loop so that the program continues until the user wishes to exit
    while(1){
        //The start direction is always north for the robot so it is specified clearly in case they want to continue giving instructions.
        myRobot.dir= N; //clears any previous saved location too

        //The program asks the user for the robot's starting position (x, y coordinates, 0-99)
        printf("Please enter the robot's starting position- x and y coordinates (ranging between 0-99) respectively. Separate them with comma.\n");

        //takes x, y coordinate as input from the user
        if(scanf("%d,%d", &myRobot.xpos, &myRobot.ypos) !=2){ //if it is not 2 that indicates error in obtaining 2 int input
            printf("Invalid input. Only enter two INTEGER values (0-99). See you later.\n"); //tells user to not enter invalid inputs like strings
            // Clear the input buffer
            int c; //initialising number of character count
            //normally get char reads and covers the value to ASCII code value
            //When used in a loop like while it effectively discards characters from the input stream.
            while ((c = getchar()) != '\n' && c != EOF);
            clearerr(stdin);  // Clears the EOF flag if set
            continue; //continues back to the beginning of the loop
        }

        //if coordinates are out of range, shows error and asks to come back later
        if(myRobot.xpos<0 || myRobot.ypos<0 || myRobot.xpos>99 || myRobot.ypos>99 ){
            printf("Invalid input. Only enter coordinates in the range 0-99. See you later.\n");
            continue;
        }

        // initialising an array to store movement instructions
        char instructions[100];//assuming a maximum of 100 instructions

        //program ask for a string of characters 'm' and 't' to instruct robot movements
        printf("Enter movement instructions as a string in the form of 'm' and 't' only. ");
        printf("Out of the range movements will be ignored.\n"); //shows user how much they can control
        printf("If you wish to exit type 'exit'. \n"); //shows user how to exit
        scanf("%s", instructions); //lets the user enter string of instructions

        // checks if input is longer then 100 character
        if (strlen(instructions) > 100) {//used to measure the length of instruction array input, if >100 then error message
            printf("Instruction string is too long. Please enter instructions with a maximum length of 100 characters.\n");
            continue;  // Continue to the next iteration if the instruction string is too long
        }

        // checks the input if it's equal to exit
        if (strcmp(instructions, "exit") == 0) { //equals to 0 means they are equal values
            break; // Exit the loop if the user enters 'exit'
        }

        //loop through each instruction step by step until you reach end of line '\0'
        for(int i=0; instructions[i] != '\0'; i++){
            if(instructions[i]=='m' || instructions[i]== 'M'){ //if user has asked to move call the move method with given instructions
                move(&myRobot); //calling move method on my robot}
            }
            else if(instructions[i]=='t' || instructions[i]== 'T'){//if user has asked to turn call the turn method with given instructions
                turn(&myRobot);  //calling turn method on my robot
            }
            //nothing is done if it is any other letter otherwise, it is ignored
        }

        //in C, enums are typically represented as integers
        //namDir function converts the direction from integer to char for printing
        //the robot stops so the program prints out the new position of the robot.
        printf("This is the new Position of the robot: %d:%d. This is their Direction: %c. \n", myRobot.xpos, myRobot.ypos,nameDir(&myRobot));
    }
    return 0;
}

//this function returns a char N,S,E,W depending on the direction of the robot
char nameDir(ROBOT *thisRobot){
    char Direction= ' ';// initialised direction char
    switch(thisRobot->dir) { //options depending on current direction
        case N: //if north
            Direction='N';
            break;
        case E:  //if east
            Direction='E';
            break;
        case S:  //if south
            Direction='S';
            break;
        case W:  //if west
            Direction='W';
            break;
    }

    return Direction; //returns char for direction
}

//turn: means that the robot turns 90 degrees clockwise.
//uses a pointer to myRobot as arguments to update the robot position
void turn(ROBOT *thisRobot){
    switch(thisRobot->dir) { //options depending on current direction
        case N: //if north
            thisRobot->dir = E;
            break;
        case E:  //if east
            thisRobot->dir = S;
            break;
        case S:  //if south
            thisRobot->dir = W;
            break;
        case W:  //if west
            thisRobot->dir = N;
            break;
    }
}

//move: means that the robot takes one step in the current direction.
//uses a pointer to myRobot as arguments to update the robot direction
//max= 99, min=0
void move(ROBOT *thisRobot){
    int oldPosX= thisRobot->xpos; //stores current x coordinate
    int oldPosY= thisRobot->ypos; //stores current y coordinate

    switch(thisRobot->dir) { //options depending on current direction
        case N: //if north
            if(oldPosY!=99){thisRobot->ypos++;} //goes up if already not maximum otherwise skipped move
            break;
        case E:  //if east
            if(oldPosX!=99){thisRobot->xpos++;} //goes right if already not maximum otherwise skipped move
            break;
        case S:  //if south if already not minimum otherwise skipped move
            if(oldPosY!=0){thisRobot->ypos--;} //goes down so subtract 1
            break;
        case W:  //if west  if already not minimum otherwise skipped move
            if(oldPosX!=0){thisRobot->xpos--;} //goes left so subtract 1
            break;
    }

}




/*The primary purpose of using enums is to improve code readability and maintainability by giving meaningful names to integral constants.
 * Instead of using hard-coded numeric values, you can use enum constants that make your code more self-explanatory.*/