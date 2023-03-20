#include "getters.h"
using namespace std;

char * getWordFromFile(ifstream & inFile, char delimeter) {
	char * word = nullptr;
	char c = ' ';
	int wordLength = 0;
	while (inFile.peek() != delimeter) {
		c = inFile.get();
		// if empty
		if (!word) {
			word = new char[2];
			word[0] = c;
			word[1] = '\0';
		}
		else {
			char * dummy = new char[wordLength + 2];
			strcpy(dummy, word);
			dummy[wordLength] = c;
			dummy[wordLength + 1] = '\0';
			delete [] word;
			word = new char[wordLength + 2];
			strcpy(word, dummy);
			delete [] dummy;
			dummy = nullptr;
		}
		wordLength += 1;
	}
	inFile.ignore(1, delimeter);
	return word;
}
int getIntFromFile(ifstream & inFile, char delimeter) {
	int i;
	inFile >> i;
	inFile.ignore(1, delimeter);
	return i;
}
char getCharFromFile(ifstream & inFile, char delimeter) {
	char c;
	inFile >> c;
	inFile.ignore(1, delimeter);
	return c;
}
char * getWordFromUser() {
	char * word = nullptr;
	char c = ' ';
	int wordLength = 0;
	while (cin.peek() != '\n') {
		c = cin.get();
		// if empty
		if (!word) {
			word = new char[2];
			word[0] = c;
			word[1] = '\0';
		}
		else {
			char * dummy = new char[wordLength + 2];
			strcpy(dummy, word);
			dummy[wordLength] = c;
			dummy[wordLength + 1] = '\0';
			delete [] word;
			word = new char[wordLength + 2];
			strcpy(word, dummy);
			delete [] dummy;
			dummy = nullptr;
		}
		wordLength += 1;
	}
	cin.ignore(1, '\n');
	return word;
}
int getIntFromUser() {
	int i;
	cin >> i;
	while (!cin) {
		cout << "Bad Input! Try Again: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> i;
	}
	return i;
}
int getIntFromUser(int max) {
	int i;
	cin >> i;
	while (!cin || i > max) {
		cout << "Bad Input! Try Again: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> i;
	}
	return i;
}
char getCharFromUser() {
	char c;
	cin >> c;
	cin.ignore(1, '\n');
	return c;
}
// returns char * (not new)
char * wordToUpper(char * word) {
	for (int i = 0; i < static_cast<int>(strlen(word)); i++) {
		word[i] = toupper(word[i]);
	}
	return word;
}
// returns char * (not new)
char * wordToLower(char * word) {
	for (int i = 0; i < static_cast<int>(strlen(word)); i++) {
		word[i] = tolower(word[i]);
	}
	return word;
}
