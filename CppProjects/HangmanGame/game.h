#pragma once

#include <string>
#include <iostream>

using namespace std;

bool game(string);
void printWord(string);
bool updateWord(string, char);
void changeWord(string &, string, char);
bool winLose(string, string);
void printGallows(int);