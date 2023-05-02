// CSCI 1300 Spring 2023
// Author: McGhee Steiner
// Recitation: 201 – Ruvane
// Project 3 - Medical.h

#ifndef MED_H
#define MED_H

// .h files
#include "Insurance.h"
#include "Surgeon.h"

// libraries
#include <iostream>

using namespace std;

class Medical
{
private:
    static const int surgeons_size_ = 10; // size of surgeons array
    Surgeon surgeons[surgeons_size_];     // array of Surgeon objects
    int num_surgeons_;                    // Number of surgeons stored in the database at a given instance
    bool surgeons_arr_full_;              // whether or not the surgeons array is full

public:
    Medical(); // default constructor

    // no parameterized constructor needed

    // Getters and setters
    int getSurgeonsSize();

    int getNumSurgeons();

    bool isSurgArrFull();

    void setSurgArrFull(bool surgeons_arr_full_parameter);

    Surgeon getSurgeon(string surgeon_name_); // takes in a surgeon's name and returns that whole Surgeon object

    void searchSurgeons(Insurance user_insurance); // outputs a list of surgeon names that take the user's insurance and populates surgeons array
};
#endif