// (C) Faiza Amjad, Tehreem Asif Group: 11 __ (2023)
// Work package 2
// Exercise 3
// Submission code: 777464 (provided by your TA-s)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// Define the filename as a global constant
const char* FILENAME = "createdFile.txt";
// -----typedefs -------
typedef struct {
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON; // person type should have a firstname, last name of max 20 characters and a 12-digit personal number

// --------Function declarations----------
PERSON input_record(void); // Reads a person’s record.
void write_new_file(PERSON *inrecord); // Creates a file and writes the first record
void append_file(PERSON *inrecord); // Appends a new person to the file
void printfile(void); // Prints out all persons in the file
void search_by_firstname(char *name); // Prints out the person if in the list
int file_exists(const char *filename); // Return 0 if the file exists
int isFileEmpty(const char *filename); // Return 0 if the file is not empty

int main(void) {

    PERSON ppost; // declaring a variable for type person to be used throughout - dummy person
    int option = 0; // declaring and initializing the option number that the user chose
    char tempName[20]; // Declare an array to store the first name for when searching for a person

    while (1) { // a while loop helps to repeat the program and returns to the menu for new choices unless the user wishes to leave.

        printf("What would you like to do? Please choose an option and enter the corresponding integer:\n");
        printf("1. Create a new and delete the old file.\n");
        printf("2. Add a new person to the file.\n");
        printf("3. Search for a person in the file\n");
        printf("4. Print out all in the file.\n");
        printf("5. Exit the program.\n");

        // takes input from the user as an option
        if (scanf(" %d", &option) != 1) {  // if input is not a number or not in the correct format (not 1 returned),
            // the user is prompted with an error message
            printf("Invalid Input! Please enter an integer only.\n");
            break; // exits user as they entered other characters exit themselves
        }

        // if out of range chosen or if not int chosen
        if (option < 1 || option > 5) {       // If the integer entered is not within the range 1-5
            printf("Invalid Input! Only integers between 1-5 are allowed.");
            continue; // lets the loop start again, and the user can enter the options again until they exit themselves
        }

        // execution of the chosen option's tasks if they're within the range depending on the option
        switch (option) {
            case 1:  // 1. Create a new and delete the old file.
                // creating a dummy record for a person
                // strcpy to copy the string content into the character arrays from string.h library
                strcpy(ppost.firstname, "Dum");
                strcpy(ppost.famname, "Rec");
                strcpy(ppost.pers_number, "20020201234a");
                // sending this person pointer as an argument to write a new file method
                write_new_file(&ppost);
                // this method creates a new file, writes this dummy data and then close it.
                break;
            case 2:  // 2. Add a new person to the file.
                // declares a temporary person to add data to the file
                if(file_exists("createdFile.txt")==1){
                      printf("File doesn't exist.");
                }
                else{
                    ppost = input_record(); // calls the input record method for the user to put data for a new person
                // Adds this record at the end of the file.
                    append_file(&ppost);}
                break;
            case 3:  // 3. Search for a person in the file.
                if (isFileEmpty("createdFile.txt") == 0 && file_exists("createdFile.txt")==0 ) {// if the file is not empty
                    printf("Enter their first name to search for the person: \n"); // prompts the user to enter the first name to search
                    scanf("%19s", tempName);  // takes input of the name from the user
                    search_by_firstname(tempName); // and gives it as an argument to the method for searching
                } else {
                    printf("File is empty.\n");
                }
                break;
            case 4: // 4. Print out all in the file.
                if (isFileEmpty("createdFile.txt") == 0 && file_exists("createdFile.txt")==0 ) {// if the file is not empty and exists
                    printfile(); // Calls the print method to print
                } else {
                    printf("File is empty or doesn't exists.\n");
                }
                break;
            case 5:       // 5. Exit the program.
                return 0; // Just exits the program
        }
    }
}

// Creates a file and writes the first record
void write_new_file(PERSON *inrecord) {
    FILE *fileptr;    // a file pointer declared and defines
    // Delete the olf file
    if (remove("createdFile.txt") == 0) {
        printf("Old file deleted successfully.\n"); //successful deletion
    } else {
        printf("Error deleting the old file.\n"); //unsuccessful deletion
    }
    fileptr = fopen("createdFile.txt", "wb"); // creates or opens a new file named createdFile
    // and let the pointer point to it for writing in binary mode

    // Checking if the file was opened successfully
    if (fileptr == NULL) { // null means the pointer is pointing to nothing
        printf("Error in opening a new file. \n");
    }
        // writes a first dummy record to the file if the file is created
    else {
        // writes data to the file (file pointer, "format", values)
        fwrite(inrecord, sizeof(PERSON), 1, fileptr); // Write the PERSON struct to the file
        printf("New file created.\n");

        // closing the file to clear the buffer and for resource management.
        fclose(fileptr);
    }
}

// Reads a person’s record and saves it as a temporary record.
PERSON input_record(void) {

    PERSON temp;
    printf("Please enter the data of the new person (FirstName FamilyName PersonalNumber): ");
    // Read input and check for successful conversions
    if (scanf("%19s %19s %12s", temp.firstname, temp.famname, temp.pers_number) != 3) {
        printf("Error: Invalid input format.\n");
        // Clear input buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        // Set default values or handle the error as appropriate
        strcpy(temp.firstname, "");
        strcpy(temp.famname, "");
        strcpy(temp.pers_number, "");
    } else {
        // Clear input buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        // Append a newline character to separate records
        temp.pers_number[12] = '\n';
    }
    return temp;//returns updated person
}



// appends a new person to the end of file
void append_file(PERSON *inrecord) {
    FILE *fileptr; // Declare a file pointer
    // Open the file for appending in binary mode
    fileptr = fopen("createdFile.txt", "ab");
    if (fileptr == NULL) {
        printf("Error in opening the file for appending.\n");
        return;
    }
    // Append the new record to the file
    // Set the newline character at the end of pers_number array
    inrecord->pers_number[12] = '\n';
    fwrite(inrecord, sizeof(PERSON), 1, fileptr);
    printf("New person added with first name: %s\n", inrecord->firstname);
    fclose(fileptr);// Close the file
}


// Prints out the person if in the list
void search_by_firstname(char *name) {
    FILE *fileptr; // a file pointer declared and defined
    fileptr = fopen("createdFile.txt", "rb"); // opens the file in reading binary mode

    if (file_exists("createdFile.txt") == 0) { // checks if the file exists
        if (isFileEmpty("createdFile.txt") == 0) { // check if the file is not empty
            // Checking if the file was opened successfully
            if (fileptr == NULL) {
                printf("Error in opening a file for reading.");
            } else {
                PERSON tempPerson;
                int found = 0; // Flag to indicate whether at least one person is found

                while (fread(&tempPerson, sizeof(PERSON), 1, fileptr) == 1) {
                    if (strcmp(tempPerson.firstname, name) == 0) { // 0 means matches
                        // Print the details of the person if the first name matches
                        printf("First name:%s, Family name:%s, Personal number:%s\n", tempPerson.firstname,
                               tempPerson.famname, tempPerson.pers_number);
                        found++; // Increment the counter for found persons
                    }
                }

                if (found == 0) {
                    // Print a message if no person is found with the specified first name
                    printf("No person found with the specified first name.\n");
                }

                // Closing the file to clear the buffer and for resource management
                fclose(fileptr);
            }
        } else {
            printf("File is empty.\n");
        }
    } else {
        printf("File does not exist.\n");
    }
}


// Prints out all persons in the file
void printfile(void) {
    if (file_exists("createdFile.txt") == 0) { // checks if the file exists
        FILE *fileptr; // a file pointer declared and defined
        fileptr = fopen("createdFile.txt", "rb"); // opens the file in reading binary mode
        PERSON tempPerson; // using temp person for collecting and printing person data

        // Checking if the file was opened successfully
        if (fileptr == NULL) {
            printf("Error in opening a file for reading.\n");
        } else {
            // iterating through the file
            while (fread(&tempPerson, sizeof(PERSON), 1, fileptr) == 1) {
                // Prints the details of the person
                printf("First name:%s, Family name:%s, Personal number:%s\n",
                       tempPerson.firstname, tempPerson.famname, tempPerson.pers_number);
            }
            // Closing the file to clear the buffer and for resource management
            fclose(fileptr);
        }
    } else {
        printf("File does not exist or is empty.\n");
    }
}

// tells if the file exists or not
int file_exists(const char *filename) {
    FILE *fileptr = fopen(filename, "r");
    if (fileptr) {
        fclose(fileptr); // if exists, close immediately
        return 0; // shows it exists
    }
    return 1; // shows it doesn't exist
}

int isFileEmpty(const char *filename) { // checks if the file is empty or not
    FILE *fileptr = fopen(filename, "r");//opening file for reading
    if (fileptr) {//if file successfully opened
        fseek(fileptr, 0, SEEK_END);// move file pointer to the end of the file
        long size = ftell(fileptr);//tells in int form where is the current pointer meaning end of file
        fclose(fileptr);
        if(size==0){ return 1;} //if file is empty
        else{return 0;}//if file is not empty good
    }
    return 1;//error if file not even opened
}