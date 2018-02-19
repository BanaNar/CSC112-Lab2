/*
 *  @file    labTwo_Part2.cpp
 *  @author  Tony Xu (xuj16)
 *  @date    2/11/2018
 *  @version 9.0
 *
 *  This is a dice stimulator which stimulates rolling two dice.
 *
 */

#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ofstream outFS; // Output file stream

    outFS.open("DiceSimOut.csv"); // Open file
    if (!outFS.is_open()) {
        cout << "Could not open file DiceSimOut.csv." << endl;
        return 1;
    }

    // Declare variables
    unsigned int rSeed;
    unsigned int numTrials;
    unsigned int numSides;
    int firstDice, secondDice;
    int i;
    int numRolls = 1;
    int totalRolls = 0;
    int totalSum[18];

    // Initialize value of each possible value to zero
    for (i = 2; i <= 18; ++i){
        totalSum[i] = 0;
    }

    // Ask for user inputs
    cout << "Enter seed: ";
    cin >> rSeed;
    srand(rSeed); //use input seed
    cout << "Enter number of trials: ";
    cin >> numTrials;
    cout << "Enter number of sides per die: ";
    cin >> numSides;

    //Input with values out of range. Leading to end of program
    if ((numSides < 3) || (numSides > 9)){
        cout << "Error input for the number of sides. It should be from 3 to 9." << endl;
        return 1;
    }

    // Arrays to store rolls and scores
    int rolls[numTrials - 1];
    int scores[numTrials - 1];



    //for-loop for numTrials times
    for (i = 0; i < numTrials; ++i) {
        scores[i] = 0;
        //first roll
        firstDice = rand() % numSides + 1;
        secondDice = rand() % numSides + 1;
        totalSum[firstDice + secondDice]++;
        //while-loop to test if two dices have same values
        while (firstDice != secondDice) {
            ++numRolls;
            scores[i] = scores[i] + firstDice + secondDice;
            firstDice = rand() % numSides + 1;
            secondDice = rand() % numSides + 1;
            totalSum[firstDice + secondDice]++;
        }
        rolls[i] = numRolls;
        totalRolls += numRolls;
        numRolls = 1;
    }

    //Print Output
    cout << "Total rolls: " << totalRolls << endl;
    cout << "Counts for two-die roll counts." << endl;
    for (i = 2; i <= numSides * 2; ++i){
        cout << totalSum[i] << " ";
    }

    //Write to file
    for (i = 0; i < numTrials; ++i){
        outFS << rolls[i] << ", " << scores[i] << endl;
    }

    //Done with file, so close it
    outFS.close();

    return 0;
}
