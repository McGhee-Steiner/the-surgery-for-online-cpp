// CSCI 1300 Spring 2023
// Author: McGhee Steiner
// Recitation: 201 – Ruvane
// Project 3 - Insurance.h

// header guards
#ifndef INSURANCE_H
#define INSURANCE_H

// libraries
#include <iostream>

using namespace std;

class Insurance
{
private:
    string insurance_name_; // name of insurance
    int coverage_;          // percent (integer 0-100)

public:
    // default constructor
    Insurance();

    // parameterized constructor
    Insurance(string insurance_name_parameter, int coverage_parameter);

    // getters and setters
    string getInsuranceName();

    void setInsuranceName(string insurance_name);

    int getCoverage();

    void setCoverage(int coverage);
};

#endif