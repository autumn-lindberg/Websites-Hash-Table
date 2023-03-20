#include "table.h"
using namespace std;

// constructors
Table::Table() {
	this->data = new List[1];
	this->size = 1;
}
Table::Table(int size) {
	this->data = new List[size];
	this->size = size;
}
Table::Table(const Table & src) {
	this->data = new List[src.size];
	for (int i = 0; i < this->size; i++) {
		this->data[i] = src.data[i];
	}
}
// destructor
Table::~Table() {
	if (this->data) delete [] this->data;
}
// overloaded operators
ostream & operator << (ostream & out, const Table & src) {
	src.displayAll();
	return out;
}
Table & Table::operator = (const Table & src) {
	if (this != &src) {
		if (this->data) delete [] this->data;
		this->data = new List[src.size];
		for (int i = 0; i < this->size; i++) {
			this->data[i] = src.data[i];
		}
	}
	return *this;
}
// add a website to table
bool Table::addSite(Website * w) {
	char * topicCopy = w->getTopic();
	int index = hash(topicCopy);
	delete [] topicCopy;
	return this->data[index].addSite(w);
}
// display a linked list based on topic, store in matches & numFound
bool Table::retrieve(char * topic, Website * matches, int & numFound) {
	bool returnVal = false;
	int index = hash(topic);
	returnVal = this->data[index].retrieve(topic, matches, numFound);
	for (int i = 0; i < numFound; i++) {
		cout << matches[i];
	}
	return returnVal;
}
// edit the review for a given topic and website name
bool Table::editReview(char * topic, char * name, char * newReview) {
	int index = hash(topic);
	return this->data[index].editReview(name, newReview);
}
// edit the rating for a given topic and website name
bool Table::editRating(char * topic, char * name, int newRating) {
	int index = hash(topic);
	return this->data[index].editRating(name, newRating); 
}
// remove all websites under a given rating
bool Table::removeSitesUnder(int rating) {
	for (int i = 0; i < this->size; i++) {
		if (this->data[i].getSize() != 0) this->data[i].removeSitesUnder(rating);
	}
	return true;
}
// display songs that match a given topic
void Table::displayByTopic(char * topic) {
	int index = hash(topic);
	this->data[index].displayByTopic(topic);
}
// display all songs
void Table::displayAll() const {
	for (int i = 0; i < this->size; i++) {
		if (this->data[i].isEmpty()) {
			cout << endl;
			cout << "LIST " << i + 1 << " IS EMPTY" << endl;
			cout << endl;
		}
		else {
			cout << "LIST " << i + 1 << ":" << endl;
			cout << endl;
			cout << this->data[i];
			cout << endl;
		}
	}
}
// display performance by showing the length of each chain
void Table::analyzePerformance() {
	for (int i = 0; i < this->size; i++) {
		cout << "Table #" << i + 1 << " size:  ";
		for (int z = 0; z < this->data[i].getSize(); z++) {
			cout << "*  ";
		} 
		cout << endl;
	}
}
// return hash for a given topic
// use first three letters of topic to hash
int Table::hash(char * topic) {
	int returnVal = 0;
	for (int i = 0; i < 3; i++) {
		returnVal += static_cast<int>(topic[i]);
	}
	returnVal %= this->size;
	return returnVal;
}
