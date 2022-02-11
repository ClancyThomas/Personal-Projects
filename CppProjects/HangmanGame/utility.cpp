#include <string>
#include <vector>
#include <fstream>
#include "utility.h"

using namespace std;

void readWords(vector<string> & words){
    ifstream fin("gameWords.txt");
    string word;
    while(fin >> word) {
        words.push_back(word);
    }
    fin.close();
}

string randomWord(const vector<string> & words) {
    srand(time(NULL));
    unsigned int index = rand()%20;
    return words[index];
}

