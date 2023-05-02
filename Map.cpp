// CSCI 1300 Spring 2023
// Author: McGhee Steiner
// Recitation: 201 – Ruvane
// Project 3 - Map.cpp

// .h files
#include "Map.h"

// libraries
#include <iomanip> // for setw()
#include <iostream>
#include <string>

using namespace std;

Map::Map() // default constructor
{
    // populate array items with day numbers
    // i represents the number value of a given day (minus 1)
    for (int i = 0; i < num_days_; i++) // num_days_ = 150
    {
        // row index = i / 30; (ie) when i < 30, row is 0. 30 < i < 60 --> row is 1; which is why the number on the map is i + 1
        int r = (i / num_columns); // i / 30 <-- this makes r the first digit (if a two digit number) and first two digits (if a three digit number)
        int c = (i % num_columns); // i % 30 (modulo (%) finds the remainder) <-- this makes c = the last digit of any pos integer (i)
        // idea for the above algorithm comes from my digitsSuperSumRecursive() algorithm (HW 8)

        map_[r][c] = to_string(i + 1); // convert integer to string with to_string() function as the map is an array of strings, not integers

        // initialize player position / current day to first day / first index in array
        map_[0][0] = current_day;
    }
}

void Map::printMap() // print 2D array
{
    cout << "-----------------------------------------------------" << map_name << "-----------------------------------------------------" << endl; // title / header

    for (int r = 0; r < num_rows; r++) // loop through each row of 2D array
    {
        for (int c = 0; c < num_columns; c++) // loop through each column within each row
        {
            cout << setw(4) << map_[r][c]; // print each array item with proper spacing (using setw())
        }

        if (r != 4) // aesthetic spacing
        {
            cout << endl
                 << endl;
        }

        else
        {
            cout << endl;
        }
    }
    cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
}

void Map::moveForward() // increments player position by one
{
    bool moved = false; // create bool variable to ensure action is only completed once

    // find where the current day is in the map
    for (int r = 0, n = 0; r < num_rows; r++) // loop through each row of 2D array; n represents the number at a given index, incremented whenever column is incremented
    {
        for (int c = 0; c < num_columns; c++, n++) // loop through each column within each row
        {
            if (map_[r][c] == current_day && map_[r][c] != map_[5][30]) // once the current day is found, as long as it's not the very last item in the array
            {
                if (c != (num_columns - 1) && moved == false) // if it's not the end of the row
                {
                    map_[r][c] = to_string(n + 1); // return previous current day to its designated number
                    map_[r][c + 1] = current_day;  // set next immediate index to the new current day (aka "X" as opposed to its number)
                    moved = true;                  // set moved bool equal to true so the step is only completed once
                }

                else if (c == (num_columns - 1) && moved == false) // if it's the end of the row and move has not yet been executed
                {
                    map_[r][c] = to_string(n + 1); // return previous current day to its designated number
                    map_[r + 1][0] = current_day;  // place the current day on the new row at index 0 of the column
                    moved = true;                  // set moved bool equal to true so the step is only completed once
                }
            }
        }
    }
}

int Map::getCurrentDay() // returns the current day as an integer (ie finds the position in the array marked with an 'X')
{
    int current_day_ = 0; // make integer variable for function to return and initialize to 0

    for (int r = 0; r < num_rows; r++) // loop through each row of 2D array
    {
        for (int c = 0; c < num_columns; c++) // loop through each column within each row
        {
            if (map_[r][c] == current_day) // once current day is found
            {
                // if it's the first day, I can not use the below algorithm because there is no preceding value in the array
                if (r == 0 && c == 0)
                {
                    current_day_ = 1; // so just set current day to 1
                }

                // the element at the index of current day is "X", so I need to get the stoi() of the previous element and add one
                else if (c != 0) // as long as it's not the first item in a given row (aka column index can not be 0)
                {
                    current_day_ = (stoi(map_[r][c - 1]) + 1); // use stoi() to convert string of current day value in array to integer
                }

                else if (c == 0 && r != 0) // if the element is the first item in a given row, but not at [0][0]
                {
                    current_day_ = (stoi(map_[r - 1][29]) + 1); // this adds one to the value in the array of the last element of the last line
                }
            }
        }
    }
    return current_day_; // return current day as an integer!
}