// CSCI 1300 Spring 2023
// Author: McGhee Steiner
// Recitation: 201 – Ruvane
// Project 3 - Player.h

// header guards
#ifndef PLAYER_H
#define PLAYER_H

// .h files
#include "Insurance.h"
#include "Surgeon.h"

// libraries
#include <iostream>

using namespace std;

class Player

{
private:
    int money_;                  // money ($)
    int energy_;                 // energy (E)
    string username_;            // username
    int days_remaining_;         // days left before day of reckoning
    Insurance player_insurance_; // player's insurance
    Surgeon player_surgeon_;     // player's chosen surgeon
    int num_steps_completed_;    // how many steps player has completed
    bool transphobic_fam_;       // whether or not player's family is transphobic (/how they react to coming out letter)
    bool has_met_therapist_;     // whether or not the player has met with the therapist yet
    int surgery_cost_;           // cost of player's surgery (changes based on insurance coverage)
    bool only_fans_started_;     // whether or not the player has started an onlyfans account
    string of_username_;         // onlyfans username
    string fursona_name_;        // player's fursona name
    bool fursona_made_;          // whether or not the player has made their fursona

public:
    // default constructor
    Player();

    // parameterized constructor not needed
    // getters and setters:
    int getMoney();

    void setMoney(int money_parameter);

    int getEnergy();

    void setEnergy(int energy_parameter);

    string getUsername();

    void setUsername(string username_parameter);

    int getDaysRemaining();

    void setDaysRemaining(int days_remaining_parameter);

    Insurance getPlayerInsurance();

    Surgeon getSurgeon();

    void setSurgeon(Surgeon player_surgeon_parameter);

    int getNumStepsCompleted();

    void setNumStepsCompleted(int num_steps_completed_parameter);

    bool getHasMetTherapist();

    void setHasMetTherapist(bool has_met_therapist_parameter);

    int getSurgeryCost();

    void setSurgeryCost(int surgery_cost_parameter);

    bool isOnlyFansStarted();

    void setOnlyFansStarted(bool only_fans_started_parameter);

    string getOfUsername();

    void setOfUsername(string of_username_parameter);

    string getFursonaName();

    void setFursonaName(string fursona_name_parameter);

    bool getFursonaMade();

    void setFursonaMade(bool fursona_made_parameter);

    bool getTransphobicFam(); // returns true for transphobic family, false for not

    void setTransphobicFam(bool transphobic_fam_parameter);

    // Other functions
    void engagePlayer(); // gets player to press enter to continue the game

    void setRandomPlayerInsurance(vector<Insurance> insurances, int num_insurances_stored); // assigns the player a random insurance

    void printStats(); // prints player's stats

    void completeStep(); // increments num_steps_completed_ by 1

    void previousStepIncomplete(Player player_parameter); // checks if the player has completed all previous steps or not

    void stepAlreadyComplete(Player player_parameter); // checks if player has already completed a given step or not

    void calculateSurgeryCost(Player player_parameter); // calculates the cost of surgery based on insurance coverage
};

#endif