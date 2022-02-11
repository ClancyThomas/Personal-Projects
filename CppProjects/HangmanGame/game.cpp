#include <iostream>
#include <string>
#include "game.h"

using namespace std;

bool game(string word) {
    
    string hiddenWord = "";
    for(int i = 0; i<word.length(); i++) {
        hiddenWord += "_";
    }
    
    cout << "Welcome to the game! Get ready to play..." <<endl;
    int guesses = 7;
    char guess;
   
    while(guesses > 0) {
        cout << "You have " << guesses << " guesses left" <<endl;
        printWord(hiddenWord);
        cout << "\nEnter your guess: ";
        cin >> guess;
        changeWord(hiddenWord, word, guess);
        if (updateWord(word, guess)) {
            cout << "Your guess was correct..." <<endl;
        }
        else {
            cout <<"Your guess was incorrect..." <<endl;
            guesses--;
        }
        printGallows(guesses);
        if (winLose(hiddenWord, word)) {
            cout << "You won!!" <<endl;
            return true; 
        }
        else {
            continue;
        }
    }

    cout << "   |_______________  " <<endl;
    cout << "   |/       |        " <<endl;
    cout << "   |        O        " <<endl;
    cout << "   |       \\|/        " <<endl;
    cout << "   |        |       " <<endl;
    cout << "   |       / \\      " <<endl;
    cout << "   |                 " <<endl;
    cout << " -------------------- " <<endl;
    cout << "YOU LOST " << endl;
    cout << "The word was: " << word <<endl; 
 
    return false;
}

void printWord(string hiddenWord){
    for(auto ch: hiddenWord) {
        cout << ch << " ";
    }
}

bool updateWord(string word, char guess) {
    for(int i=0; i<word.length(); i++) {
        if(word[i] == guess) {
            return true;
        }
        else {
            continue;
        } 
    }
    return false;
}

void changeWord(string & hiddenWord, string word, char guess) {
    for(int i=0; i<word.length(); i++){
        if(word[i] == guess){
            hiddenWord[i] = word[i];
        }
    }
}

bool winLose(string hiddenWord, string word) {
    for(int i=0; i<word.length(); i++) {
        if(hiddenWord[i] == word[i]) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}


void printGallows(int guesses) {

    if(guesses == 7) {
    cout << "   |_______________ " <<endl;
    cout << "   |/       |       " <<endl;
    cout << "   |                " <<endl;
    cout << "   |                " <<endl;
    cout << "   |                " <<endl;
    cout << "   |                " <<endl;
    cout << "   |                " <<endl;
    cout << "  ----------------- " <<endl;
    }

    else if(guesses == 6) {
    cout << "   |_______________ " <<endl;
    cout << "   |/       |       " <<endl;
    cout << "   |        O       " <<endl;
    cout << "   |                " <<endl;
    cout << "   |                " <<endl;
    cout << "   |                " <<endl;
    cout << "   |                " <<endl;
    cout << " ------------------ " <<endl;
    }

    else if(guesses == 5) {
    cout << "   |_______________  " <<endl;
    cout << "   |/       |        " <<endl;
    cout << "   |        O        " <<endl;
    cout << "   |        |        " <<endl;
    cout << "   |                 " <<endl;
    cout << "   |                 " <<endl;
    cout << "   |                 " <<endl;
    cout << " ------------------- " <<endl;
    }

    else if(guesses == 4) {
    cout << "   |_______________  " <<endl;
    cout << "   |/       |        " <<endl;
    cout << "   |        O        " <<endl;
    cout << "   |        |/        " <<endl;
    cout << "   |                 " <<endl;
    cout << "   |                 " <<endl;
    cout << "   |                 " <<endl;
    cout << " ------------------- " <<endl;
    }

    else if(guesses == 3) {
    cout << "   |_______________  " <<endl;
    cout << "   |/       |        " <<endl;
    cout << "   |        O        " <<endl;
    cout << "   |       \\|/        " <<endl;
    cout << "   |                 " <<endl;
    cout << "   |                 " <<endl;
    cout << "   |                 " <<endl;
    cout << " ------------------- " <<endl;
    }
 
    else if(guesses == 2) {
    cout << "   |_______________  " <<endl;
    cout << "   |/       |        " <<endl;
    cout << "   |        O        " <<endl;
    cout << "   |       \\|/        " <<endl;
    cout << "   |        |       " <<endl;
    cout << "   |                 " <<endl;
    cout << "   |                 " <<endl;
    cout << " ------------------- " <<endl;
    }


    else if(guesses == 1) {
    cout << "   |_______________  " <<endl;
    cout << "   |/       |        " <<endl;
    cout << "   |        O        " <<endl;
    cout << "   |       \\|/        " <<endl;
    cout << "   |        |       " <<endl;
    cout << "   |         \\        " <<endl;
    cout << "   |                 " <<endl;
    cout << " ------------------- " <<endl;
    }
   
}