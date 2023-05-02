// CSCI 1300 Spring 2023
// Author: McGhee Steiner
// Recitation: 201 – Ruvane
// Project 3 - Map.h

// header guards
#ifndef MAP_H
#define MAP_H

// libraries
#include <iostream>
#include <iomanip>

using namespace std;

class Map
{
private:
    static const int num_rows = 5;             // 5 rows
    static const int num_columns = 30;         // 30 columns
    static const int num_days_ = 150;          // 150 total days / distinct indices in array
    string map_[num_rows][num_columns];        // 2D array
    const string current_day = "X";            // marks what day the player is on
    const string map_name = "Road to Surgery"; // name

public:
    Map(); // default constructor

    void printMap(); // prints the map_ array

    void moveForward(); // moves current_day forward one index in map_ array

    int getCurrentDay(); // returns the numbered value that the current day would have
};
#endif
