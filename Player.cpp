// CSCI 1300 Spring 2023
// Author: McGhee Steiner
// Recitation: 201 – Ruvane
// Project 3 - Player.cpp

// .h files
#include "Player.h"
#include "Insurance.h"

// libraries
#include <fstream>
#include <random>
#include <cstdlib>

using namespace std;

Player::Player()
{
        money_ = 8000;              // dollars
        energy_ = 100;              // E (units of energy)
        username_ = "";             // set username to empty string
        days_remaining_ = 150;      // initialize days remaining to 150 (start of game / calendar)
        player_insurance_;          // initializes default insurance
        player_surgeon_;            // default surgeon
        num_steps_completed_ = 0;   // initialize number of steps completed to 0
        transphobic_fam_ = 0;       // initialize transphobic fam to false
        has_met_therapist_ = false; // player has not yet met with therapist
        surgery_cost_ = 10000;      // initialize surgery cost to 10000 (dollars)
        only_fans_started_ = false; // player has not yet started onlyfans
        of_username_ = "";          // initialize onlyfans username to empty string
        fursona_made_ = false;      // player has not yet made fursona
}

// parameterized constructor not needed

// getters and setters
int Player::getMoney()
{
        return money_;
}

void Player::setMoney(int money_parameter)
{
        money_ = money_parameter;
}

int Player::getEnergy()
{
        return energy_;
}

void Player::setEnergy(int energy_parameter)
{
        energy_ = energy_parameter;
}

string Player::getUsername()
{
        return username_;
}

void Player::setUsername(string username_parameter)
{
        username_ = username_parameter;
}

int Player::getDaysRemaining()
{
        if (days_remaining_ > 0) // if there are positive days remaining return integer
        {
                return days_remaining_;
        }

        return 0; // otherwise there are 0 days remaining.
}

void Player::setDaysRemaining(int days_remaining_parameter)
{
        days_remaining_ = days_remaining_parameter;
}

Insurance Player::getPlayerInsurance()
{
        return player_insurance_;
}

Surgeon Player::getSurgeon()
{
        return player_surgeon_;
}

void Player::setSurgeon(Surgeon player_surgeon_parameter)
{
        player_surgeon_ = player_surgeon_parameter;
}

int Player::getNumStepsCompleted()
{
        return num_steps_completed_;
}

int Player::getSurgeryCost()
{
        return surgery_cost_;
}

void Player::setSurgeryCost(int surgery_cost_parameter)
{
        surgery_cost_ = surgery_cost_parameter;
}

bool Player::isOnlyFansStarted()
{
        return only_fans_started_;
}

void Player::setOnlyFansStarted(bool only_fans_started_parameter)
{
        only_fans_started_ = only_fans_started_parameter;
}

string Player::getOfUsername()
{
        return of_username_;
}

void Player::setOfUsername(string of_username_parameter)
{
        of_username_ = of_username_parameter;
}

string Player::getFursonaName()
{
        return fursona_name_;
}

void Player::setFursonaName(string fursona_name_parameter)
{
        fursona_name_ = fursona_name_parameter;
}

bool Player::getFursonaMade()
{
        return fursona_made_;
}

void Player::setFursonaMade(bool fursona_made_parameter)
{
        fursona_made_ = fursona_made_parameter;
}

bool Player::getTransphobicFam()
{
        return transphobic_fam_;
}

void Player::setTransphobicFam(bool transphobic_fam_parameter)
{
        transphobic_fam_ = transphobic_fam_parameter;
}

bool Player::getHasMetTherapist()
{
        return has_met_therapist_;
}

void Player::setHasMetTherapist(bool has_met_therapist_parameter)

{
        has_met_therapist_ = has_met_therapist_parameter;
}

void Player::setNumStepsCompleted(int num_steps_completed_parameter)
{
        num_steps_completed_ = num_steps_completed_parameter;
}

/**
 * Name: split1()
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

int split1(string input_string, char separator, string arr[], int arr_size)
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
 * Function Name: setRandomPlayerInsurance()
 * Algorithm: This function creates a vector of insurances from the insurances.txt file and assigns one random insurance to the player's private insurance member.
 * 1. Create the file from insurances text file and get file input stream
 * 2. If file opens, execute algorithm:
 * 3. Declare line variable
 * 4. Create variable to hold output of split function and initialize to 0
 * 5. Loop through lines of file:
 * 6. Declare variables for and call split function
 * 7. If correct number of components are found, store each valid insurance as an object of the Insurance class in the insurances array
 * 8. Define the parts of the line in the text file as the parameters of a Insurances object
 * 9. Add insurance to the end of the vector using vector function push_back()
 * 10. Randomly assign the user an insurance from the array
 * 11. Create variable to store randomized insurance ID #
 * 12. Use ID number to get that insurance from the insurances array and assign to the user
 * random value 0-7 for random insurance in the insurance array
 * Parameters: vector<Insurance> insurances, int num_insurances_stored
 * Returns: nothing (void)
 * */
void Player::setRandomPlayerInsurance(vector<Insurance> insurances, int num_insurances_stored)
{

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

                        const int size = 2; // we're only looking for 2 components in the insurances (name and coverage)

                        string arr[2];

                        // num_splits is the value returned by split
                        num_splits = split1(line, separator, arr, size);

                        if (num_splits == 2) // the number of insurances found should only be incremented if the two attributes are found
                        {
                                num_insurances_stored++;

                                // this verified insurance should now be stored as an object of the Insurance class in the insurances array
                                // define the parts of the line in the text file as the parameters of a Insurances object
                                // Insurance(insurance_name (string), coverage (int)) vv see below
                                Insurance my_insurance = Insurance(arr[0], stoi(arr[1])); //stoi() converts string of arr[1] to integer value

                                insurances.push_back(my_insurance); // add insurance to the end of the vector using vector function push_back()
                        }
                }
        }

        // randomly assign the user an insurance from the array
        srand((unsigned int)time(0)); // create seed for rand()

        // create variable to store randomized insurance ID #
        int insurance_ID = (8 * double(rand()) / double(RAND_MAX)); // random value 0-8 for random insurance in the insurance array

        // use ID number to get that insurance from the insurances array and assign to the user
        player_insurance_ = insurances.at(insurance_ID);
}

/**
 * Function Name: engagePlayer()
 * Algorithm: Prompts user to give any input to continue using getline to accept any user input.
 * Parameters: none
 * Returns: no return value (void)
 * */
void Player::engagePlayer()
{
        // prompt user
        cout << "Press return to continue:" << endl;

        // variable for user engagement
        string user_engagement;

        // get user engagement
        getline(cin, user_engagement);

        cout << endl;
}

/**
 * Function Name: printStats()
 * Algorithm:
 * 1. If a player has non-zero money, energy AND days remaining before surgery, print their stats
 * 2. If player has been assigned an insurance plan, print this as a stat.
 * 3. If a player has selected a Surgeon, print this as a stat as well.
 * 4. If a player has no money (and/or no energy), inform them, say goodbye and end the program.
 * 5. If the player has no more days remaining, implement Day of Reckoning algorithm:
 * 6. See if surgeon accepts insurance and change surgery cost appropriately.
 * 7. Engage player.
 * 8. If player has not completed all 4 steps, let them know (failure) and exit the program.
 * 9. If the player has completed all 4 steps and has enough money for surgery, let them know (success) and end the program.
 * Parameters: None
 * Returns: no return value (void)
 * */
void Player::printStats()
{
        if (money_ > 0 && energy_ > 0 && days_remaining_ > 0) // if a player has non-zero money, energy AND days remaining before surgery
        {
                cout << "Current stats for ~" << username_ << "~: " << endl // print their stats
                     << "Money: $" << money_ << " | "
                     << "Energy: " << energy_ << " E"
                     << " | "
                     << "Days Remaining: " << days_remaining_ << " | "
                     << "Steps Completed: " << num_steps_completed_ << "/4";

                if (num_steps_completed_ > 1) // if player has gotten assigned an insurance plan
                {
                        cout << " | Insurance plan: " << player_insurance_.getInsuranceName(); // print their insurance plan as a stat
                }

                if (num_steps_completed_ > 2) // if player has completed choosing their surgeon step
                {
                        cout << " | Prospective Surgeon: " << player_surgeon_.getSurgeonName(); // print their surgeon as a stat!
                }

                // warnings for low energy, money or days remaining
                if (money_ < 5000)
                {
                        cout << endl
                             << "WARNING: LOW FUNDS";
                }

                if (energy_ < 20)
                {
                        cout << endl
                             << "WARNING: LOW ENERGY";
                }

                if (days_remaining_ < 14)
                {
                        cout << endl
                             << "WARNING: FEW DAYS REMAINING";
                }

                cout << endl
                     << endl;
        }

        else if (money_ <= 0) // if player has no money
        {
                cout << "You have run out of money"; // inform them of this

                if (energy_ <= 0)
                {
                        cout << " and energy. Goodbye, " << username_ << "!" << endl; // if the player also has no energy
                }

                else
                {
                        cout << ". Goodbye, " << username_ << "!" << endl; // parting message
                }

                exit(0); // end the game
        }

        else if (energy_ <= 0) // if the player has only run out of energy
        {
                cout << "You have run out of energy. Goodbye, " << username_ << "!" << endl; // parting message

                exit(0); // end the game
        }

        else if (days_remaining_ <= 0)
        {

                // see if surgeon accepts insurance and change surgery cost appropriately
                // aka if the surgeon does not take the player's insurance, set the surgery cost back to 10000
                if (player_surgeon_.acceptsInsurance(player_insurance_) == false)
                {
                        surgery_cost_ == 10000;
                }

                cout << "The Day of Reckoning has arrived." << endl; // dramatic

                // engage player
                // prompt user
                cout << "Press return key to continue:" << endl;

                // variable for user engagement
                string user_engagement;

                // get user engagement
                getline(cin, user_engagement);

                cout << endl;

                // ensure that steps are completed
                if (num_steps_completed_ != 4)
                {
                        cout << "Sorry, you have not completed all the steps necessary for surgery. Goodbye, " << username_ << "!" << endl;
                        exit(0);
                }

                else
                {
                        cout << "You have completed all 4 steps!" << endl; // partial success message

                        cout << "Your surgery cost is: $" << surgery_cost_ << endl // print stats
                             << "You have: $" << money_ << endl;

                        if (surgery_cost_ > money_) // if player doesn't have enough money for surgery
                        {
                                cout << "Sorry, you do not have enough money for The Surgery. Goodbye, " << username_ << "!" << endl; // failure message
                                exit(0);                                                                                              // end game
                        }

                        else
                        {
                                cout << "C O N G R A T U L A T I O N S   O N   Y O U R   T R A N S G E N D E R   S U R G E R Y " << username_ << "! ! ! ! ! ! ! ! ! ! ! !"; // congratulatory message

                                if (only_fans_started_ == true)
                                {
                                        cout << " A K A " << of_username_; // including their nicknames if they made them.
                                }

                                if (fursona_made_ == true)
                                {
                                        cout << " A K A " << fursona_name_;
                                }

                                cout << "! ! ! ! ! ! ! ! ! ! !" << endl;

                                exit(0); // end game
                        }
                }
        }
}

void Player::completeStep() // increments num_steps_completed_ by 1
{
        num_steps_completed_++;
}

void Player::previousStepIncomplete(Player player_parameter) // outputs message for when one or more previous steps are incomplete
{
        cout << "You have not completed one or more previous steps. Please complete step " << (player_parameter.getNumStepsCompleted() + 1) << " first." << endl
             << endl;
}

void Player::stepAlreadyComplete(Player player_parameter) // outputs message when a selected step has already been completed
{
        cout << "You have already completed this step. Please move on to step " << (player_parameter.getNumStepsCompleted() + 1) << "." << endl
             << endl;
}

void Player::calculateSurgeryCost(Player player_parameter) // sets surgery cost to new cost after insurance coverage
{
        surgery_cost_ = (surgery_cost_ - (((getPlayerInsurance().getCoverage()) * surgery_cost_) / 100)); // calculate cost cost - (coverage% * 10000)
}