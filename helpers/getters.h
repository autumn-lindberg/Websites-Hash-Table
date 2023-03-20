#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// get input from a fil euntil delimeter
char * getWordFromFile(ifstream & inFile, char delimeter);
int getIntFromFile(ifstream & inFile, char delimeter);
char getCharFromFile(ifstream & inFile, char delimeter);
// get input from user
char * getWordFromUser();
int getIntFromUser();
int getIntFromUser(int max);
char getCharFromUser();
// take char array and make it uppercase/lowercase
char * wordToUpper(char * word);
char * wordToLower(char * word);

