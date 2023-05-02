// CSCI 1300 Spring 2023
// Author: McGhee Steiner
// Recitation: 201 – Ruvane
// Project 3 - Surgeon.cpp

// .h files
#include "Surgeon.h"
#include "Insurance.h"

// libraries
#include <vector>
#include <random>
#include <string>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <fstream>

using namespace std;

// default constructor
Surgeon::Surgeon()
{
    consultation_wait_ = 0; // set consultation wait to 0 days
    years_experience_ = 0;  // set years experience to 0 days
}

// parameterized constructor
Surgeon::Surgeon(string surgeon_name_parameter, int years_experience_parameter, int consultation_wait_parameter)
{
    surgeon_name_ = surgeon_name_parameter;
    years_experience_ = years_experience_parameter;
    consultation_wait_ = consultation_wait_parameter;
}

Surgeon::Surgeon(string surgeon_name_parameter)
{
    surgeon_name_ = surgeon_name_parameter;
}

string Surgeon::getSurgeonName()
{
    return surgeon_name_;
}

void Surgeon::setSurgeonName(string surgeon_name_parameter)
{
    surgeon_name_ = surgeon_name_parameter;
}

void Surgeon::getInsurancesAccepted() // outputs surgeon's accepted insurances
{
    // loop through insurances array
    for (int i = 0; i < 2; i++)
    {
        cout << insurances_accepted_[i].getInsuranceName() << endl; // print name of insurance in array as list
    }
}

int Surgeon::getYearsExperience()
{
    return years_experience_;
}

void Surgeon::setYearsExperience(int years_experience_parameter)
{
    years_experience_ = years_experience_parameter;
}

int Surgeon::getConsultationWait()
{
    return consultation_wait_;
}

void Surgeon::setConsultationWait(int consultation_wait_parameter)
{
    consultation_wait_ = consultation_wait_parameter;
}

/**
 * Name: split()
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

int split(string input_string, char separator, string arr[], int arr_size)
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
 * Name: readInsurances()
 * Algorithm: 
 * 1. Populates a vector of Insurance objects with the insurance name and coverage from insurances.txt file.
 * 2. Randomly assigns two insurances to surgeon's insurance array
 * ** Refer to comments for more detailed algorithm. **
 * Parameters: i (integer), used to seed the rand() function.
 * Returns: 0 (integer)
 * */
int Surgeon::readInsurances(int i)
{
    // declare size of insurances array
    insurances_accepted_[num_insurances_accepted_];

    // initialize number of insurances stored to 0
    int num_insurances_stored = 0;

    // initialize empty insurances vector
    vector<Insurance> insurances;

    // create the file from insurances text file and get file input stream
    ifstream file("insurances.txt");

    // if file opens, execute algorithm
    if (file.is_open())
    {
        // declare line variable
        string line;

        // create variable to hold output of split function and initialize to 0
        int num_splits = 0;

        // loop through lines of file
        for (int i = 0; getline(file, line); i++)
        {

            // declare variables for and call split function
            char separator = '|';

            const int size = 2; // we're only looking for 2 components in the line for an insurance object (name and coverage)

            string arr[2];

            // num_splits is the value returned by split
            num_splits = split(line, separator, arr, size);

            if (num_splits == 2) // the number of insurances found should only be incremented if the two attributes are found
            {
                num_insurances_stored++;

                // this verified insurance should now be stored as an object of the Insurance class in the insurances array
                // define the parts of the line in the text file as the parameters of a Insurances object
                // Insurance(insurance_name (string), coverage (int)) vv
                Insurance my_insurance = Insurance(arr[0], stoi(arr[1])); //stoi() converts string of arr[1] to integer value

                insurances.push_back(my_insurance); // add insurance to the end of the vector using vector function push_back()
            }
        }
    }

    // randomly assign the user an insurance from the array
    srand((unsigned int)(time(0) + i)); // incrementing by i ensures that as this function is called in a loop (which occurs so fast that it seeds the same time(0)), it outputs just as random insurances by changing the seed of the rand()

    // get two random insurances that are different
    int insurance_ID_1 = (8 * double(rand()) / double(RAND_MAX)); // random value 0-8 for random insurance in the insurance array

    // get new time to ensure that second insurance is not same as first insurance
    srand((unsigned int)(time(0) + i + 100));

    int insurance_ID_2 = (8 * double(rand()) / double(RAND_MAX));

    // populate surgeon's insurance array with two different pseudo-random insurances from insurances vector
    insurances_accepted_[0] = insurances.at(insurance_ID_1);
    insurances_accepted_[1] = insurances.at(insurance_ID_2);

    return 0;
}

bool Surgeon::acceptsInsurance(Insurance player_insurance) // returns true if the surgeon accepts the given insurance, false otherwise
{
    for (int i = 0; i < 2; i++)
    {
        // loop through surgeon's insurance array to compare accepted insurances to user's insurance
        if (player_insurance.getInsuranceName() == insurances_accepted_[i].getInsuranceName())
        {
            return true;
        }
    }

    return false;
}