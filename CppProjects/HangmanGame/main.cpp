/*=========================================================================
Hangman Game
Final Project CS1

By: Clancy Thomas
Date: December 9, 2020

A basic Hangman game that the user can play.

Algorithm Steps
1. Create a file that contains at least 20 words
2. Read each of the words into a vector
    - Open the text file
    - Read the words
    - Close the text file
3. Randomly select one of the words
    - Generate a random index
    - Use the word at that random index
4. Play the game
    - Enter a guess that is a letter
    - Check if the guess matches the word
    - Update the word if the letter is correct
    - Check if the word has been completely solved
5. Ask the user to quit or continue
6. Keep track of the stats
    - Display the stats
==========================================================================*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "utility.h"
#include "game.h"

using namespace std;

int main(int argc, char* argv[]) {
    
    vector<string> words;
    readWords(words);
    
    int totalGames = 0;
    int totalWins = 0;
    char ans;
   
    do{
        totalGames++;
        string word = randomWord(words);
        if (game(word))
            totalWins++;
        cout << "\nWould you like to play again? [Y|N]: ";
        cin >> ans;
    }while(ans == 'Y' or ans == 'y');

    int totalLosses = totalGames - totalWins;
    cout << "Total games played: " << totalGames <<endl;
    cout << "Total wins: " << totalWins <<endl;
    cout << "Total losses: " << totalLosses <<endl;
    cout << "Thank you for playing!!!" <<endl;
    
    return 0;
}



