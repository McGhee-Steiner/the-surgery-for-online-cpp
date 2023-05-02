// CSCI 1300 Spring 2023
// Author: McGhee Steiner
// Recitation: 201 – Ruvane
// Project 3 - Insurance.cpp

#include "Insurance.h"

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

// Default constructor
Insurance::Insurance()
{
    insurance_name_ = ""; // sets insurance name to an empty string
    int coverage_ = 0; // sets coverage variable to 0
}

// parameterized constructor
Insurance::Insurance(string insurance_name_parameter, int coverage_parameter)
{
    insurance_name_ = insurance_name_parameter;
    coverage_ = coverage_parameter;
}

// getters and setters
string Insurance::getInsuranceName()
{
    return insurance_name_;
}

void Insurance::setInsuranceName(string insurance_name)
{
    insurance_name_ = insurance_name;
}

int Insurance::getCoverage()
{
    return coverage_;
}

void Insurance::setCoverage(int coverage)
{
    if (coverage_ >= 0 && coverage_ <= 100) // coverage is a percentage, so must be between 0 and 100 (inclusive)
    {
        coverage_ = coverage;  
    }
}
