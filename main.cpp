#include "main.h"
#include <fstream>
using namespace std;

int main() {
	Table * t = new Table(8);
	char option = 'z';

	loadData(t);

	while (option != 'q') {
		option = menu();
		executeOption(t, option);
	}

	delete t;
}

bool loadData(Table * t) {

	ifstream inFile;
	char * name = nullptr;
	char * url = nullptr;
	char * topic = nullptr;
	char * desc = nullptr;
	char * review = nullptr;
	int rating;

	inFile.open("websites.txt");
	if (!inFile) {
		cout << "File did not open." << endl;
		return false;
	}
	else {
		do {
			name = getWordFromFile(inFile, ',');
			url = getWordFromFile(inFile, ',');
			topic = getWordFromFile(inFile, ',');
			desc = getWordFromFile(inFile, ',');
			review = getWordFromFile(inFile, ',');
			rating = getIntFromFile(inFile, '\n');

			Website * w = new Website(name, url, topic, desc, review, rating);
			t->addSite(w);

			delete [] name;
			delete [] url;
			delete [] topic;
			delete [] desc;
			delete [] review;
		} while (inFile.peek() != EOF); 
		inFile.close();
	}
	return true;
}

char menu() {
	char * selection = nullptr; 
	cout << endl;
	cout << "  INSERT       - Add A New Website To Table" << endl;
	cout << "  REVIEW       - Edit A Review For A Website" << endl;
	cout << "  STARS        - Edit A Rating For A Website" << endl;
	cout << "  DELETE       - Remove All Websites Under Likes Threshold" << endl;
	cout << "  TOPIC        - Display All Websites Based On Topic" << endl;
	cout << "  ALL          - Display All Websites" << endl;
	cout << "  PERFORMANCE  - Show Analysis Of Hash Function" << endl;
	cout << "  QUIT         - Quit This Program" << endl;
	cout << endl;
	cout << "Please Enter Your Choice: ";
	selection = getWordFromUser();
	cout << endl;
	selection = wordToUpper(selection);
	if (strcmp(selection, "INSERT") == 0) {
		delete [] selection;
		return 'i';
	}
	if (strcmp(selection, "REVIEW") == 0) {
		delete [] selection;
		return 'r';
	}
	if (strcmp(selection, "STARS") == 0) {
		delete [] selection;
		return 's';
	}
	if (strcmp(selection, "DELETE") == 0) {
		delete [] selection;
		return 'd';
	}
	if (strcmp(selection, "TOPIC") == 0) {
		delete [] selection;
		return 't';
	}
	if (strcmp(selection, "ALL") == 0) {
		delete [] selection;
		return 'a';
	}
	if (strcmp(selection, "PERFORMANCE") == 0) {
		delete [] selection;
		return 'p';
	}
	if (strcmp(selection, "QUIT") == 0) {
		delete [] selection;
		return 'q';
	}
	delete [] selection;
	return 'z';
}

void executeOption(Table *& t, char option) {
	char * name = nullptr;
	char * url = nullptr;
	char * topic = nullptr;
	char * desc = nullptr;
	char * review = nullptr;
	int rating;
	switch(option) {
		case 'i': {
			cout << "Website Name: ";
			name = getWordFromUser();
			cout << "Website URL: ";
			url = getWordFromUser();
			cout << "Topic: ";
			topic = getWordFromUser();
			cout << "Description: ";
			desc = getWordFromUser();
			cout << "Review: ";
			review = getWordFromUser();
			cout << "Rating: ";
			rating = getIntFromUser();
			Website * w = new Website(name, url, topic, desc, review, rating);
			t->addSite(w);
			cout << endl;
			cin.ignore(1, '\n');
			break;
		}
		case 'r':
			cout << "Topic Name: ";
			topic = getWordFromUser();
			cout << "Website Name: ";
			name = getWordFromUser();
			cout << "New Review: ";
			review = getWordFromUser();
			t->editReview(topic, name, review);
			cout << endl;
			break;
		case 's':
			cout << "Topic Name: ";
			topic = getWordFromUser();
			cout << "Website Name: ";
			name = getWordFromUser();
			cout << "New Rating: ";
			rating = getIntFromUser();
			t->editRating(topic, name, rating);
			cout << endl;
			cin.ignore(1, '\n');
			break;
		case 'd':
			cout << "Rating Threshold To Delete Under: ";
			rating = getIntFromUser();
			t->removeSitesUnder(rating);
			cout << endl;
			cin.ignore(1, '\n');
			break;
		case 't': {
			Website * matches = nullptr;
			int numFound;
			cout << "Topic Name: ";
			topic = getWordFromUser();
			t->retrieve(topic, matches, numFound);
			delete [] matches;
			break;
		}
		case 'a':
			cout << *(t) << endl;
			break;
		case 'p':
			t->analyzePerformance();
			break;
		case 'q':
			cout << "Thank You For Using My Program!" << endl;
			cout << endl;
			break;
		default:
			cout << "choice not recognized." << endl;
			break;
	}
	if (name) delete [] name;
	if (url) delete [] url;
	if (topic) delete [] topic;
	if (desc) delete [] desc;
	if (review) delete [] review;
}
