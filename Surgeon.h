// CSCI 1300 Spring 2023
// Author: McGhee Steiner
// Recitation: 201 – Ruvane
// Project 3 - Surgeon.h

// header guards
#ifndef SURGEON_H
#define SURGEON_H

// .h files
#include "Insurance.h"

// libraries
#include <vector>
#include <iostream>

using namespace std;

class Surgeon

{
private:
    string surgeon_name_;                                     // surgeon's name
    static const int num_insurances_accepted_ = 2;            // num insurances in the surgeon's insurance array
    Insurance insurances_accepted_[num_insurances_accepted_]; // array of insurances that the surgeon accepts
    int years_experience_;                                    // years of experience
    int consultation_wait_;                                   // surgeon's wait time (understood to user simply as wait_time_ *** this variable does not reference any actual consultation in the game)

public:
    // default constructor
    Surgeon();

    // parameterized constructor
    Surgeon(string surgeon_name_parameter, int years_experience_parameter, int consultation_wait_parameter);

    // parameterized constructor for player default surgeon
    Surgeon(string surgeon_name_parameter);

    // Getters and Setters
    string getSurgeonName();

    void setSurgeonName(string surgeon_name_parameter);

    void getInsurancesAccepted(); // prints insurances accepted

    int getYearsExperience();

    void setYearsExperience(int years_experience_parameter);

    int getConsultationWait();

    void setConsultationWait(int consultation_wait_parameter);

    // Other Functions
    int readInsurances(int i); // randomly assigns two insurances to surgeon's insurance array (populates insurance array)

    bool acceptsInsurance(Insurance player_insurance); // determines if a given surgeon accepts the user's insurance
};

#endif