// CSCI 1300 Spring 2023
// Author: McGhee Steiner
// Recitation: 201 – Ruvane
// Project 3 - driver.cpp

// .h files
#include "Map.h"
#include "Insurance.h"
#include "Surgeon.h"
#include "Player.h"
#include "Medical.h"

// libraries
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <random>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    Player player1;         // create default Player object
    string username;        // create variable to store player's username
    Map user_calendar;      // create default Map object
    string fursona_name;    // create variable to store fursona name if that option is selected later
    Medical player_medical; // create an instance of Medical class to store Surgeon array later
    string menu_selection;  // create variable for menu selection

    cout << "Enter a username: "; // prompt user for username

    getline(cin, username); // using getline to get user name and accept spaces

    bool valid_username = false; // create variable to ensure the username is valid (aka the username has something other than spaces)

    // Input validation: loop to see if username is not just spaces
    for (int c = 0; c < username.length(); c++) // c is the character index; loop through each character of username
    {
        if (username[c] != ' ') // if the username contains a non-space
        {
            valid_username = true; // the username is valid
        }
    }

    // make fun of player if they enter an empty string (aka just press enter), or just typed in a bunch of spaces
    if (valid_username == false) // if it's all spaces
    {
        username = "mysterious unnamed subject";                  // by setting the username to "mysterious unnamed subject"
        cout << "Don't want to out yourself? We get it." << endl; // playful bit
    }

    player1.setUsername(username); // set the Player's object username to their input

    // introduce the game structure with personalized line based on username
    cout << endl
         << "Congratulations, ~" << player1.getUsername() << "~! You are transgender and seeking \"The Surgery\"." << endl; // slash marks allow for quotes within cout string

    player1.engagePlayer(); // get user engagement to continue

    cout << "You have 150 days to complete the following steps, in order:" << endl // continue introduction with a preview of the steps
         << "* Come out" << endl
         << "* Get Insurance " << endl
         << "* Select a Surgeon " << endl
         << "* Get therapist approval" << endl;

    player1.engagePlayer(); // get user engagement to continue

    cout << "If you run out of money or energy, you automatically lose. Without insurance, surgery will cost $10000. Fortunately, you've already saved $8000!" << endl // continue instructions / game rules
         << "If you reach day 150 with sufficient funds, non-zero energy levels, and 4/4 steps complete, you win The Surgery!" << endl
         << endl;

    player1.engagePlayer(); // get user engagement to continue

    cout << "Today is day " << user_calendar.getCurrentDay() << ". Good luck!" << endl; // send player off with a good luck wish

    user_calendar.printMap(); // print calendar

    player1.printStats(); // print user stats

    // the menu should run on a loop until the user opts to quit, as long as user has non-zero money, energy, and it's not the last day (the day of reckoning)
    // the above is ensured by the printStats() function of the Player class
    while (menu_selection != "8") // until user chooses option 6
    {
        // print main menu to user
        cout << "========Main Menu=======" << endl
             << "1) Come out" << endl
             << "2) Get Insurance " << endl
             << "3) Select a Surgeon " << endl
             << "4) Get therapist approval" << endl
             << "5) Get Money / Energy" << endl
             << "6) Skip to final day" << endl
             << "7) Show my Stats" << endl
             << "8) Quit" << endl;

        getline(cin, menu_selection); // get menu selection from player

        // input validation: must be string 1,2,3,4,5 or 6
        while (menu_selection != "1" && menu_selection != "2" && menu_selection != "3" && menu_selection != "4" && menu_selection != "5" && menu_selection != "6" && menu_selection != "7" && menu_selection != "8")
        {
            cout << "Please enter a valid menu option (integer 1 through 8)." << endl; // input validation statement

            getline(cin, menu_selection); // get user input again
        }

        // Step one: Come out to your family
        if (menu_selection == "1")
        {
            cout << endl; // spacing

            // check that user has not already completed any steps (this must be the first step taken)
            if (player1.getNumStepsCompleted() > (stoi(menu_selection) - 1))
            {
                player1.stepAlreadyComplete(player1);
            }

            else // now come out to your family!
            {
                string user_letter; // create variable for user input

  
                    // ask for user input for writing letter, provide guidelines
                    cout << "**This process takes one week**" << endl
                         << "Step 1: Write a coming out letter to your family. " 
                         << "Use as many lines as you need. We will save and send it for you for just $1." << endl
                         << "To submit your letter, type \"eom\" on a new line and press return." << endl;

                    // allow for multiple lines of user input with while loop that accepts input until user enters "eom" on a new line (eom stands for end of message)
                    while (user_letter != "eom")
                    {
                        // get user input including spaces and lines
                        getline(cin, user_letter);
                    }
                

                player1.setMoney(player1.getMoney() - 1); // charge player $1 for sending the letter

                srand(time(0)); // there is a 50% chance of your family being transphobic
                                //  the randomness is generated from if the number is even or odd (~50% odds ;) get it?)

                player1.setTransphobicFam(rand() % 2); // this random number / chance (0 or 1) functions as the bool of whether or not family is transphobic, a private data member of the player class

                if (player1.getTransphobicFam() == 0) // if family is not transphobic
                {
                    cout << endl // print congratulatory message detailing statistic changes
                         << "Hooray! Your family loves and accepts you for who you are. "
                         << "They have decided to help you pay for The Surgery." << endl
                         << "You lost 10 E from the emotional labor, but gained $500!" << endl;

                    // your family gives you $500 to help with surgery
                    player1.setMoney(player1.getMoney() + 500);

                    // and you lose 10 energy points for that emotional labor regardless
                    player1.setEnergy(player1.getEnergy() - 10);
                }

                else // if your family is transphobic
                {
                    cout << endl // output message of disfortune detailing statistic changes
                         << "Unfortunately, your family did not react well and will not be helping you in any way." << endl
                         << "You have lost 30 E." << endl;

                    player1.setEnergy(player1.getEnergy() - 30); // you don't receive any money and you lose 30 energy points
                }

                player1.engagePlayer(); // engage player

                player1.completeStep(); // increment num steps completed

                for (int d = 0; d < 7; d++)
                {
                    user_calendar.moveForward(); // move forward 7 days
                }

                player1.setDaysRemaining(player1.getDaysRemaining() - 7); // lose 7 day in days remaining count of player object

                user_calendar.printMap(); // print updated calendar

                player1.printStats(); // display stats

                cout << endl; // spacing
            }
        }

        // Step 2: Get insurance
        if (menu_selection == "2")
        {
            cout << endl;

            // check that user has not already completed this step
            if (player1.getNumStepsCompleted() > (stoi(menu_selection) - 1))
            {
                player1.stepAlreadyComplete(player1);
            }

            else if (player1.getNumStepsCompleted() < (stoi(menu_selection) - 1)) // check that the user has completed all previous steps
            {
                player1.previousStepIncomplete(player1);
            }

            else
            {
                cout << "Let's get you some insurance, " << player1.getUsername() << "! "
                     << "**This process takes 2 weeks**" << endl; // initial message

                player1.engagePlayer(); // engage player

                // initialize empty insurance vector and insurances stored variable to call function setRandomPlayerInsurance()
                vector<Insurance> insurances;
                int num_insurances_stored = 0;

                player1.setRandomPlayerInsurance(insurances, num_insurances_stored); // call setRandomPlayerInsurance

                player1.calculateSurgeryCost(player1); // calculates cost (10000 - (coverage% * 10000) which is a value stored in the player's object (I changed this formula so that it works with integers)

                // output message with insurance name, coverage, and projected surgery cost
                cout << "You received " << player1.getPlayerInsurance().getInsuranceName() << ", which covers " << player1.getPlayerInsurance().getCoverage() << "% of the cost of The Surgery." << endl
                     << "If your surgeon is in-network, your surgery will cost $" << player1.getSurgeryCost() << "." << endl
                     << endl;

                player1.engagePlayer(); // engage player

                player1.completeStep(); // increment num steps completed

                for (int f = 0; f < 14; f++)
                {
                    user_calendar.moveForward(); // move forward 14 days
                }

                player1.setDaysRemaining(player1.getDaysRemaining() - 14); // decrement days remaining

                user_calendar.printMap(); // print updated calendar

                player1.printStats(); // display stats

                cout << endl; // spacing
            }
        }

        // Step 3: Select a Surgeon
        if (menu_selection == "3")
        {
            cout << endl;

            if (player1.getNumStepsCompleted() > (stoi(menu_selection) - 1)) // check that user has not already completed this step
            {
                player1.stepAlreadyComplete(player1);
            }

            else if (player1.getNumStepsCompleted() < (stoi(menu_selection) - 1)) // check that user has completed all previous steps
            {
                player1.previousStepIncomplete(player1);
            }

            else
            {
                // create variable for menu choices in sub menu (surgeon finder)
                string menu_choice;

                while (menu_choice != "6") // nested loop to keep player in surgeon finder menu until they decide to exit
                {
                    // print main menu to user (view-only list, non-interactive)
                    cout << "======Surgeon Finder=====" << endl
                         << "1) View all surgeons" << endl                   // simply outputs pre-written list of surgeons
                         << "2) Find surgeons who take my insurance" << endl // executes algorithm which populates surgeons array in Medical class
                         << "3) Get a surgeon's minimum wait time" << endl   // minimum wait time fast forwards the user that many days depending on what surgeon they choose
                         << "4) Get a surgeon's experience level" << endl    // note: years of experience does not affect anything meaningful in the game
                         << "5) Choose a surgeon " << endl                   // option which, once executed correctly, completes Step 3 (select a Surgeon)
                         << "6) Return to Main Menu" << endl;                // exits surgeon finder menu

                    getline(cin, menu_choice); // get user surgeon finder menu choice

                    // input validation
                    if (menu_choice != "1" && menu_choice != "2" && menu_choice != "3" && menu_choice != "4" && menu_choice != "5" && menu_choice != "6")
                    {
                        cout << "Please enter an integer 1-6 for your selection." << endl
                             << endl;
                    }

                    else if (menu_choice == "1") // if player selects 1
                    {
                        cout << "======Our Surgeons=====" << endl // output list of surgeon names
                             << "Dr. Joe Shmoe" << endl
                             << "Dr. Tran" << endl
                             << "Dr. Steiner" << endl
                             << "Dr. Beau Tfull" << endl
                             << "Dr. Nohnipl" << endl
                             << "Dr. E. Strogen" << endl
                             << "Dr. Chase R." << endl
                             << "Dr. McGhee" << endl
                             << "Dr. Chandler" << endl
                             << endl;
                    }

                    else if (menu_choice == "2" && player_medical.isSurgArrFull() == false)
                    {
                        /* user can only do this once because it populates the surgeons array of the medical class 
                        and assigns each surgeon an array of insurances, which should not change */

                        // output welcome statement
                        cout << "Welcome to our state-of-the-art surgeon / insurance matching algorithm:" << endl
                             << "Let's see who accepts your insurance..." << endl;

                        player1.engagePlayer(); // engage player to implement surgeon finding algorithm

                        /* call searchSurgeons member function of Medical class to search surgeons array 
                        for those that take the player's insurance; also populates surgeons array */
                        player_medical.searchSurgeons(player1.getPlayerInsurance());

                        cout << endl; // spacing

                        // set surg arr full variable to true so that this step can not be repeated (array can not be altered)
                        player_medical.setSurgArrFull(true);
                    }

                    else if (menu_choice == "2" && player_medical.isSurgArrFull() == true) // if step has already been completed
                    {
                        cout << "This action can only be completed once. Please refer to previous search results." << endl
                             << endl; // output rejection and guidance statement
                    }

                    else if (menu_choice == "3" && player_medical.isSurgArrFull() == false) // if surgeons array is not full (aka if step 2 hasn't been completed)
                    {
                        cout << "Beforing selecting this option, please find surgeons who take your insurance." << endl
                             << endl; // output rejection and guidance statement
                    }

                    else if (menu_choice == "3" && player_medical.isSurgArrFull() == true) // if player selects option 3 (get min wait time for a specific surgeon) and surgeons array is full
                    {
                        string user_input; // create variable for user input

                        cout << "Please enter the surgeon's name: " << endl; // prompt user for input of surgeon's name

                        getline(cin, user_input); // get user input using getline to accept spaces (all surgeons have spaces in name)

                        cout << endl; // spacing

                        // input validation: must be a viable surgeon name from list
                        if (user_input != "Dr. Chandler" && user_input != "Dr. Diklette" && user_input != "Dr. Tran" && user_input != "Dr. Steiner" && user_input != "Dr. Beau Tfull" && user_input != "Dr. Nohnipl" && user_input != "Dr. E. Strogen" && user_input != "Dr. Chase R." && user_input != "Dr. McGhee" && user_input != "Dr. Joe Shmoe")
                        {
                            cout << "That surgeon is not in our database. To view a list of our surgeons, please refer to option 1." << endl
                                 << endl;

                            player1.engagePlayer(); // engage player
                        }

                        else // if input is valid surgeon's name
                        {
                            // Get a specific surgeon's minimum wait time
                            cout << user_input << "'s wait time: " << player_medical.getSurgeon(user_input).getConsultationWait() << " day(s)" << endl
                                 << endl;

                            player1.engagePlayer(); // engage player
                        }
                    }

                    else if (menu_choice == "4" && player_medical.isSurgArrFull() == false) // if surgeons array is not full (aka if option 2 hasn't been completed)
                    {
                        cout << "Beforing selecting this option, please search for surgeons who take your insurance." << endl
                             << endl; // output rejection and guidance statement
                    }

                    else if (menu_choice == "4" && player_medical.isSurgArrFull() == true) // if user selects option 4 (get years experience option) and surgeons array is full (aka option 2 has been completed)
                    {

                        string user_input2; // create variable for user input

                        cout << "Please enter the surgeon's name: " << endl; // prompt user for input

                        getline(cin, user_input2); // get user input using getline to accept spaces (all surgeons have spaces in name)

                        cout << endl; // spacing

                        // input validation: must be a viable surgeon name from list
                        if (user_input2 != "Dr. Chandler" && user_input2 != "Dr. Diklette" && user_input2 != "Dr. Tran" && user_input2 != "Dr. Steiner" && user_input2 != "Dr. Beau Tfull" && user_input2 != "Dr. Nohnipl" && user_input2 != "Dr. E. Strogen" && user_input2 != "Dr. Chase R." && user_input2 != "Dr. McGhee" && user_input2 != "Dr. Joe Shmoe")
                        {

                            cout << "That surgeon is not in our database. If you need assistance, please refer to option 1." << endl
                                 << endl; // rejection and guidance input validation statement

                            player1.engagePlayer(); // engage player
                        }

                        else // if input is valid
                        {
                            // Get a specific surgeon's consultation wait time, and output in statement
                            cout << user_input2 << " has " << player_medical.getSurgeon(user_input2).getYearsExperience() << " years of experience." << endl
                                 << endl;
                        }
                    }

                    // 5) Choose a surgeon
                    else if (menu_choice == "5" && player_medical.isSurgArrFull() == false) // if player selects option 5 (choose a surgeon) but surgeons arr is not full
                    {
                        cout << "Beforing selecting this option, please search for surgeons who take your insurance." << endl
                             << endl; // output rejection and guidance statement
                    }

                    else if (menu_choice == "5" && player_medical.isSurgArrFull() == true) // if player selects option 5 and surgeons arr is full
                    {
                        if (player1.getSurgeon().getSurgeonName() != "") // if surgeon has already been chosen (aka surgeon name of player is no longer default empty string)
                        {
                            cout << "You have already selected a surgeon. Please return to Main Menu." << endl // output rejection and guidance statement
                                 << endl;
                        }

                        else // if the player has not yet selected a valid surgeon
                        {
                            cout << "So you're ready to select a surgeon! Who'll it be?" << endl; // prompt user

                            string user_surgeon; // create variable for user input of desired surgeon name

                            getline(cin, user_surgeon); // get user input using getline to accept spaces (all surgeons have spaces in name)

                            // input validation
                            if (user_surgeon != "Dr. Chandler" && user_surgeon != "Dr. Diklette" && user_surgeon != "Dr. Tran" && user_surgeon != "Dr. Steiner" && user_surgeon != "Dr. Beau Tfull" && user_surgeon != "Dr. Nohnipl" && user_surgeon != "Dr. E. Strogen" && user_surgeon != "Dr. Chase R." && user_surgeon != "Dr. McGhee" && user_surgeon != "Dr. Joe Shmoe")
                            {
                                cout << "It looks like that surgeon is not in our database." << endl // if not a valid surgeon name, output rejection statment
                                     << endl;
                            }
                            else // if the input is valid (a valid, accurately entered surgeon's name from database / list)
                            {

                                player1.setSurgeon(player_medical.getSurgeon(user_surgeon)); // sets player's surgeon to the surgeon who's name matches inputted name

                                player1.completeStep(); // increment num steps completed

                                // move forward 'surgeon's consultation wait' number of days with a loop
                                for (int n = 0; n < player_medical.getSurgeon(user_surgeon).getConsultationWait(); n++)
                                {
                                    user_calendar.moveForward();
                                }

                                // lose consultation wait number of days in days remaining count of player object
                                player1.setDaysRemaining(player1.getDaysRemaining() - player_medical.getSurgeon(user_surgeon).getConsultationWait());

                                player1.setEnergy(player1.getEnergy() - 10); // lose 10 E (energy) from the STRESS!!

                                user_calendar.printMap(); // print updated calendar

                                player1.printStats(); // display stats

                                cout << endl; // spacing
                            }
                        }
                    }
                }
            }
        }

        if (menu_selection == "4") // Step 4: Get therapist approval
        {
            cout << endl;

            if (player1.getNumStepsCompleted() > (stoi(menu_selection) - 1)) // check that user has not already completed this step
            {
                player1.stepAlreadyComplete(player1);
            }

            else if (player1.getNumStepsCompleted() < (stoi(menu_selection) - 1)) // check that user has completed all previous steps
            {
                player1.previousStepIncomplete(player1);
            }

            else
            {
                string user_transness; // create variable for user input for engaging with therapist

                if (player1.getHasMetTherapist() == false) // if it's the first time meeting therapist
                {

                    cout << "Hello " << player1.getUsername() << "." << endl // do a snarky introduction

                         << "I'm Dr. Gae T. Keeper, Ph. D, Psy. D, NPC, T4T—"
                         << "the only therapist around who can grant you access to gender-affirming medical care. " << endl
                         << "Nice to meet you." << endl
                         << "By the way, I'm out-of-network with your insurance. Got it?" << endl;

                    player1.engagePlayer(); // engage player

                    cout << "In order to deem you mentally viable for The Surgery, answer the following:" << endl
                         << "On a scale of \"not trans enough\" to \"SUPER TRANS\", how trans are you?" << endl; // ask the user the gatekeeping question
                }

                else // if its not the first meeting with the therapist, do a re-introduction but don't give full shpeel again
                {
                    cout << "Good to see you again, " << player1.getUsername() << "." << endl
                         << "How trans are you today?" << endl;
                }

                getline(cin, user_transness); // get user input for 'how trans' they are

                if (user_transness != "SUPER TRANS" && user_transness != "im very trans" && user_transness != "super trans" && user_transness != "SUPERRR TRANS" && user_transness != "SUPER TRANS " && user_transness != "TRANS AF" && user_transness != "I'M SO TRANS") // accept various inputs that declare a lot of transness (main correct input is "SUPER TRANS" though)
                {
                    cout << endl
                         << "It looks like we'll have to meet again, same time next week. That'll be $500." << endl // if the user input is not good enough for the therapist, output rejection and cost statement
                         << endl
                         << "You also lost 20 E." << endl;

                    player1.engagePlayer(); // engage player

                    for (int a = 0; a < 7; a++)
                    {
                        user_calendar.moveForward(); // increment day by 7 in calendar...
                    }

                    player1.setDaysRemaining(player1.getDaysRemaining() - 7); // ... and decrement player day remaining count

                    player1.setEnergy(player1.getEnergy() - 20); // lose 20 E (energy) per session

                    player1.setMoney(player1.getMoney() - 500); // lose $500 per session

                    user_calendar.printMap(); // print updated calendar

                    player1.printStats(); // display stats

                    cout << endl; // spacing
                }

                else // if the transness is up to the therapist's standards
                {
                    cout << endl
                         << "Very well then. That'll be "; // output satisfaction and cost statement

                    if (player1.getHasMetTherapist() == true)
                    {
                        cout << "another "; // change the phrase slightly if this is not the first meeting
                    }

                    cout << "five-hundo. Here's my stamp of approval. Have a smooth surgery." << endl
                         << endl;

                    player1.engagePlayer(); // engage player

                    player1.setEnergy(player1.getEnergy() - 20); // lose 20 E energy

                    player1.setMoney(player1.getMoney() - 500); // lose $500

                    player1.completeStep(); // increment num steps completed

                    user_calendar.moveForward(); // move forward in calendar

                    player1.setDaysRemaining(player1.getDaysRemaining() - 1); // decrement days remaining

                    user_calendar.printMap(); // print updated calendar

                    player1.printStats(); // display stats

                    cout << endl;
                }

                player1.setHasMetTherapist(true); // set having met with therapist bool variable equal to true for the player to slightly alter future interactions
            }
        }

        if (menu_selection == "5") // Option 5: Get Money / Energy
        {
            string activities_selection; // create variable for selection of restorative activites submenu

            while (activities_selection != "3") // until user opts to quit (option 3)
            {
                cout << endl
                     << "=====Restorative Activities====" << endl // output sub menu
                     << "1) Get $" << endl
                     << "2) Get E" << endl
                     << "3) Exit this Menu" << endl;

                getline(cin, activities_selection); // get user input

                // nested loop
                while (activities_selection != "1" && activities_selection != "2" && activities_selection != "3") // input validation while loop
                {
                    cout << "Please enter 1, 2  or 3 for your selection." << endl; // re-prompt user

                    getline(cin, activities_selection); // get new user input until input is valid
                }

                if (activities_selection == "1") // if player selects option 1
                {
                    string money_menu; // create variable for money submenu selection

                    // nested loop
                    while (money_menu != "3") // until the user opts to exit money restoration menu
                    {
                        // output sub menu for financial restoration
                        cout << "=====Financial Restoration Menu====" << endl
                             << "1) Work at sTarbux" << endl
                             << "2) Start an OnlyTrans" << endl
                             << "3) Exit this Menu" << endl;

                        getline(cin, money_menu); // get user input for $ menu option

                        // nested loop
                        while (money_menu != "1" && money_menu != "2" && money_menu != "3")
                        {
                            cout << "Please enter a valid menu option." << endl; // input validation loop
                            getline(cin, money_menu);                            // get new input until input is valid
                        }

                        if (money_menu == "1") // if user selects work at sTarbux option (option 1)
                        {
                            string starbux_days; // create variable for user input of how many days they want to work

                            cout << "Each day you work at sTarbux earns $120 (after tax) but costs 14 E." << endl // introduce working at sTarbux agreement
                                 << "You can work between 1 and 5 days consecutively." << endl
                                 << "How many days would you like to work?" << endl; // prompt user input

                            getline(cin, starbux_days); // get user input

                            // nested loop
                            // input validation loop: starbucks_days must be a number between 0 and the number of days remaining
                            while (starbux_days != "1" && starbux_days != "2" && starbux_days != "3" && starbux_days != "4" && starbux_days != "5")
                            {
                                cout << "Please enter a valid number of days (integer 1-5)." << endl;

                                getline(cin, starbux_days); // correct and get user input until input is valid selection
                            }

                            if (stoi(starbux_days) > player1.getDaysRemaining()) // if the player wants to work more days than they have left
                            {
                                cout << "You do not have enough days remaining to work " << starbux_days << " days." << endl; // input validation / rejection
                            }

                            else // if the user has enough days left to work the amount of days desired
                            {
                                player1.setEnergy((player1.getEnergy() - (stoi(starbux_days) * 14))); // subtract 14 E per day worked

                                player1.setMoney(player1.getMoney() + (stoi(starbux_days) * 120)); // add $120 per day worked

                                for (int j = 0; j < stoi(starbux_days); j++) // stoi() converts string to integer
                                {
                                    user_calendar.moveForward(); // move forward number of days worked with for loop
                                }

                                player1.setDaysRemaining((player1.getDaysRemaining() - stoi(starbux_days))); // subtract days worked from days remaining

                                user_calendar.printMap(); // print calendar
                                player1.printStats();     // print user stats
                                cout << endl;             // spacing
                            }
                        }

                        if (money_menu == "2") // If user selects option 2 (start an onlyfans)
                        {
                            if (player1.isOnlyFansStarted() == true) // check that activity has not been done already
                            {
                                cout << "You have already started your OnlyTrans." << endl;

                                player1.engagePlayer();
                            }

                            else // if user has not yet created their Onlyfans account
                            {
                                string of_username; // create variable for user input of onlyfans username

                                cout << "Create your OnlyTrans username:" << endl; // prompt user input

                                getline(cin, of_username); // get user input

                                player1.setOfUsername(of_username); // set player's only fans username private member to their input

                                player1.setOnlyFansStarted(true); // set only_fans_started_ bool of player object to true for input validation as shown above else statement

                                cout << "Congrats, " << of_username << "! You're gonna be popular!" << endl; // congratulate user with personalized message based on their username

                                cout << "Upload an image of **** ***** ********* to start earning!" << endl; // silly heehee

                                player1.engagePlayer(); // engage player

                                srand((unsigned int)time(0)); // create seed for calling rand()

                                int initial_earnings = 0; // create and initialize variable for earnings from starting the account

                                while (initial_earnings == 0) // use while loop to ensure user earns a non-zero value
                                {
                                    // generate random value between 0 and 1000 dollars for earnings
                                    initial_earnings = (1000 * double(rand()) / double(RAND_MAX)); // store value in an integer variable so that it doesn't output a double
                                }

                                cout << "HOT DAMN " << of_username << "!!! In the first five seconds you've already earned $" << initial_earnings << "!" << endl; // print statement specifying earnings

                                player1.engagePlayer(); // engage player

                                player1.setMoney(player1.getMoney() + initial_earnings); // increment player money by onlyfans earnings

                                user_calendar.moveForward(); // move forward one day

                                player1.setDaysRemaining(player1.getDaysRemaining() - 1); // decrement days remaining

                                user_calendar.printMap(); // print updated calendar

                                player1.printStats(); // print user stats

                                cout << endl;
                            }
                        }
                    }
                }

                else if (activities_selection == "2") // If user selects option 2 (energy restoration / "Get E")
                {
                    string energy_menu; // create variable for user selection within energy menu

                    while (energy_menu != "3") // until the user opts to exit E menu
                    {
                        cout << "====Energy Restoration Menu====" << endl // print E menu
                             << "1) Sleep" << endl
                             << "2) Buy a fursuit" << endl
                             << "3) Exit this Menu" << endl;

                        getline(cin, energy_menu); // get user input

                        while (energy_menu != "1" && energy_menu != "2" && energy_menu != "3") // until user inputs valid selection
                        {
                            cout << "Please enter a valid menu option." << endl; // prompt for valid input
                            getline(cin, energy_menu);                           // get new input
                        }

                        if (energy_menu == "1") // if user selects option 1 (sleep)
                        {
                            string sleep_days; // create variable for how many days user wants to sleep

                            cout << "Each day you sleep restores 2 E energy. You can sleep for a maximum of 7 days at a time. How many days would you like to sleep for?" << endl; // output introduction

                            getline(cin, sleep_days); // get user input for number of days wanted to sleep

                            // input validation loop: starbucks_days must be a number between 0 and the number of days remaining
                            while (sleep_days != "1" && sleep_days != "2" && sleep_days != "3" && sleep_days != "4" && sleep_days != "5" && sleep_days != "6" && sleep_days != "7")
                            {
                                cout << "Please enter a valid number of days (integer 1-7)." << endl; // reprompt user

                                getline(cin, sleep_days); // get new user input
                            }

                            if (stoi(sleep_days) > player1.getDaysRemaining()) // if there's not enough days remaining to sleep desired number of days
                            {
                                cout << "You do not have enough days remaining to sleep " << sleep_days << " days." << endl; // output rejection statement
                            }

                            else // if user entered valid number of days to achieve in their calendar
                            {
                                player1.setEnergy((player1.getEnergy() + (stoi(sleep_days) * 2))); // add  E per day slept

                                for (int k = 0; k < stoi(sleep_days); k++)
                                {
                                    user_calendar.moveForward(); // move forward number of days slept with for loop
                                }

                                player1.setDaysRemaining((player1.getDaysRemaining() - stoi(sleep_days))); // decrement days slept from days remaining

                                user_calendar.printMap(); // print calendar

                                player1.printStats(); // print stats

                                cout << endl;
                            }
                        }

                        else if (energy_menu == "2") // If player selection option (2) Buy a fursuit
                        {

                            if (player1.getFursonaMade() == true) // If user has already bought a fursuit
                            {
                                cout << "Woah there, Mx. " << fursona_name << "! Limit 1 (one) fursuit purchase per game." << endl // reject their request (you can only buy one fursuit per game)
                                     << endl;

                                player1.engagePlayer(); // engage player
                            }

                            else // if user has not yet created their fursona
                            {
                                cout << "Welcome to Fursuits N Friends! What is the name of your fursona?" << endl; // output welcome statement

                                getline(cin, fursona_name); // get user input

                                player1.setFursonaName(fursona_name); // set player's fursona name private member to user input

                                player1.setFursonaMade(true); // set bool of whether or not fursona has been made to true

                                cout << "Our custom fursuits can cost up to 3000 dollars. We determine the price after we've seen the order." << endl; // clarify financial agreement with statement

                                player1.engagePlayer(); // engage player

                                srand((unsigned int)time(0)); // create seed for calling rand()

                                int fursuit_cost = 0; // initialize fursuit cost to 0 to initialize non-zero-ing random function

                                while (fursuit_cost == 0) // ensure a non-zero value for cost of fursuit with while loop
                                {
                                    // generate random value between 0 and 3000 dollars for cost of fursuit
                                    fursuit_cost = (3000 * double(rand()) / double(RAND_MAX)); // store value in an integer variable so that it doesn't output a double
                                }

                                cout << "Your fursuit is being worked on! Your card has been charged $" << fursuit_cost << "! Thank you for your payment, " << fursona_name << "." << endl; // inform user of the cost of their purchase
                                cout << "You have earned 70 E." << endl;                                                                                                                    // and what they've gained (in addition to the fursuit)

                                player1.engagePlayer(); // engage player

                                player1.setMoney((player1.getMoney() - fursuit_cost)); // decrease player money by fursuit cost

                                player1.setEnergy((player1.getEnergy() + 70)); // increase player energy by 70 E

                                user_calendar.moveForward(); // move forward one day

                                player1.setDaysRemaining(player1.getDaysRemaining() - 1); // decrement days remaining by 1 day

                                user_calendar.printMap(); // print updated calendar

                                player1.printStats(); // print player stats

                                cout << endl;
                            }
                        }
                    }
                }
            }
        }

        if (menu_selection == "6") // Option 6: If player opts to skip to Day of Reckoning
        {
            player1.setDaysRemaining(0); // set player days remaining to 0

            player1.printStats(); // call printStats() to trigger Day of Reckoning algorithm
        }

        if (menu_selection == "7") // Option 7: print player stats
        {
            player1.printStats();
            cout << endl; // spacing
        }
    }

    if (menu_selection == "7") // Option 7: If user opts to quit game
    {
        cout << "Goodbye, " << username << "!" << endl; // output goodbye message
    }
}
