// CSCI 1300 Spring 2023
// Author: McGhee Steiner
// Recitation: 201 – Ruvane
// Project 3 - Medical.cpp

// .h files
#include "Insurance.h"
#include "Surgeon.h"
#include "Medical.h"

// libraries
#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <fstream>

using namespace std;

Medical::Medical() // default constructor
{
    surgeons_arr_full_ = false; // sets surgeons_arr_full_ (bool) to false
}

// no parameterized constructor needed

// Getters and setters
int Medical::getSurgeonsSize()
{
    return surgeons_size_;
}

int Medical::getNumSurgeons()
{
    return num_surgeons_;
}

bool Medical::isSurgArrFull()
{
    return surgeons_arr_full_;
}

void Medical::setSurgArrFull(bool surgeons_arr_full_parameter)
{
    surgeons_arr_full_ = surgeons_arr_full_parameter;
}

/**
 * Function Name: getSurgeon()
 * Algorithm:
 * 1. Accepts a surgeon's name as a parameter and returns that whole surgeon
 * 2. Create empty surgeon to return if surgeon is not found in database
 * 3. Loop through surgeons array and compare names to parameter
 * 4. If surgeon name is found, return the whole surgeon at that index in the surgeons array
 * 5. If surgeon is not found, return the empty surgeon.
 * Parameters: string surgeon_name_
 * Returns: Surgeon object with matching name to parameter
 * */
Surgeon Medical::getSurgeon(string surgeon_name_) // accepts a surgeon's name as a parameter and returns that whole surgeon
{
    // create empty surgeon to return if surgeon is not found in database
    Surgeon empty_surgeon;

    // loop through surgeons array and compare names to parameter
    for (int i = 0; i < surgeons_size_; i++)
    {
        if (surgeons[i].getSurgeonName() == surgeon_name_) // if surgeon name is found
        {
            return surgeons[i]; // return the whole surgeon at that index in the surgeons array
        }
    }

    cout << "This surgeon is not in our database." << endl; // if surgeon is not found

    return empty_surgeon; // return the empty surgeon
}

/**
 * Name: split2()
 * Algorithm:
 * 1. If an empty string is provided then return 0.
 * 2. Create variable for number of pieces the input text string was split into
 * 3. Create variable to store character position (in input string) of last instance of delimiter
 * 4. Run for loop to check each character of input string for an instance of delimiter (condition is (length - 1) because the last character will not be a delimiter)
 * 5. Analyze every character of string (starting with char 0) for delimiter and take appropriate steps
 * 6. If delimiter is found, add value of one to number of pieces the input text string was split into and create variable to store substring between delimiters (treating the area before the beginning of the input string as a delimiter)
 * 7. Store string up until there and since the last instance of delimiter as a value in our array.
 * 8. Store array value string in array.
 * 9. Update variable that holds position of last delimiter for more recent found delimiter.
 * 10. Add one to num_splits to represent final value in array (that's not followed by a delimiter)
 * 11. Once all delimiters are found, declare the last substring after the last found delimiter as the last value in the array
 * 12. If the string is split into more pieces than the size of the array (the last parameter), then the function returns -1. The array should be filled with as many pieces of the split string as is possible.
 * 13. If the delimiter character is not found, then the function returns 1 and the entire string is placed in the array as the first element.
 * 14. Return size of array.

 * Parameters:
 * input_string string: The text string containing data separated by a delimiter
 * separator char: The delimiter marking the location where the string should be split up
 * arr string array: The array that will be used to store the input text string's individual string pieces
 * arr_size int: The number of elements that can be stored in the array
 * Return Value: int: The number of pieces the input text string was split into 
*/

int split2(string input_string, char separator, string arr[], int arr_size)
{

    // If an empty string is provided then return 0.
    if (input_string.length() == 0)
    {
        return 0;
    }

    // create variable for number of pieces the input text string was split into
    int num_splits = 0;

    // create variable to store character position (in input string) of last instance of delimiter
    int last_delimiter_position = -1;

    // run for loop to check each character of input string for an instance of delimiter
    for (int i = 0; i < input_string.length() - 1; i++) // condition is (length - 1) because the last character will not be a delimiter
    {

        // analyze every character of string (starting with char 0) for delimiter and take appropriate steps
        if (input_string[i] == separator) // if delimiter is found...
        {
            num_splits++; //...add value of one to number of pieces the input text string was split into and...

            // create variable to store substring between delimiters (treating the area before the beginning of the input string as a delimiter)
            // store string up until there and since the last instance of delimiter as a value in our array
            string array_value = input_string.substr(last_delimiter_position + 1, i - (last_delimiter_position + 1)); // starting value: position of last delimiter plus one, length = position of new delimiter (i) minus position of last delimiter]

            // store array value string in array
            arr[num_splits - 1] = array_value;

            // update variable that holds position of last delimiter for more recent found delimiter
            last_delimiter_position = i;
        }
    }

    // add one to num_splits to represent final value in array (that's not followed by a delimiter)
    num_splits++;

    // Once all delimiters are found, declare the last substring after the last found delimiter as the last value in the array
    arr[num_splits - 1] = input_string.substr((last_delimiter_position + 1), input_string.length());

    // If the string is split into more pieces than the size of the array (the last parameter), then the function returns -1. The array should be filled with as many pieces of the split string as is possible.
    if (num_splits > arr_size)
    {
        return -1;
    }

    // If the delimiter character is not found, then the function returns 1 and the entire string is placed in the array as the first element.
    else if (num_splits == 0)
    {
        arr[0] = input_string;
        return 1;
    }

    else
    {
        return num_splits; // returns size of array
    }
}

/**
 * Function Name: searchSurgeons()
 * General algorithm (see specifics in comments):
 * 1. Loop through array of surgeons from text file
 * 2. Create a surgeon from each line of the text file
 * 3. Assign two insurances for each surgeon (calling readInsurances())
 * 4. Check of that insurance matches the user's (use acceptsInsurance())
 * Parameters: Insurance user_insurance
 * Returns: nothing (void); outputs list of surgeon names that take the user's insurance
 * Populates an array of all surgeons in surgeons.txt
 * */
void Medical::searchSurgeons(Insurance user_insurance)
{
    int num_surgeons_stored = 0; // create and initialize to 0 variable for num surgeons stored in the surgeons array

    bool insurance_accepted = false; // create and initialize to false bool for whether any surgeon accepts user's insurance

    ifstream file("surgeons.txt"); // create the file variable from insurances text file and get file input stream

    if (file.is_open()) // if file opens, execute algorithm
    {
        string line; // declare line variable

        int num_splits = 0; // create variable to hold output of split function and initialize to 0

        for (int i = 0; getline(file, line); i++) // loop through lines of file
        {
            // create variables for and call split function
            char separator = '|';

            const int size = 3; // we're only looking for 3 components in the surgeons (name, years experience, and wait time)

            string arr[3];

            // num_splits is the value returned by split
            num_splits = split2(line, separator, arr, size);

            if (num_splits == 3) // the number of surgeons found should only be incremented if the three attributes are found
            {
                num_surgeons_stored++;

                // this verified surgeon should now be stored as an object of the Surgeon class in the surgeons array
                // define the parts of the line in the text file as the parameters of a Surgeon object
                // Surgeon(surgeon name (string), years experience (int), wait time (int))
                Surgeon my_surgeon = Surgeon(arr[0], stoi(arr[1]), stoi(arr[2])); //stoi() converts strings of arr[1] and arr[2] to their integer values

                my_surgeon.readInsurances(i); // call readInsurances() to assign random insurances to each surgeon

                surgeons[num_surgeons_stored - 1] = my_surgeon; // add surgeon to surgeons array

                // check of that insurance matches the user's (using acceptsInsurance() member function of Surgeon class)
                if (my_surgeon.acceptsInsurance(user_insurance) == true)
                {
                    // print "(name of surgeon) accepts (name of your insurance)!"
                    cout << my_surgeon.getSurgeonName() << " accepts your insurance!" << endl;

                    insurance_accepted = true; // set insurances_accepted bool equal to true to keep track of if no surgeon accepts the user's insurance
                }
            }
        }
    }

    // there is a (small) possibility that no surgeon takes the user's insurance, in which case they have to pay out of pocket
    if (insurance_accepted == false)
    {
        cout << "Unfortunately, no surgeon accepts your insurance. You will have to pay out of pocket." << endl;
    }
}
