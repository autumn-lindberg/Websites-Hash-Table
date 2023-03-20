#include "list.h"
#include "website.h"
using namespace std;

// constructors
List::List() {
	this->size = 0;
	this->head = nullptr;
}
List::List(const List & src) {
	this->head = new Node(*(src.head));
	Node * current = src.head;
	Node * thisCurrent = this->head;
	// copy using look ahead
	while (current->next) {
		thisCurrent->next = new Node(*(current->next));
		current = current->next;
		thisCurrent = thisCurrent->next;
	}
	this->size = src.size;
}
// destructor
List::~List() {
	Node * current = head;
	Node * dummy = nullptr;
	while (current) {
		dummy = current;
		current = current->next;
		delete dummy;
	}
}
// recursive destructor
void List::recursiveDestroy(Node *& current) {
	if (current) {
		recursiveDestroy(current->next);
		delete current;
	}
}
// overloaded operators
List & List::operator = (const List & src) {
	if (this != &src) {
		// destructor code
		Node * current = this->head;
		Node * dummy = nullptr;
		while (current) {
			dummy = current;
			current = current->next;
			delete dummy;
		}
		// copy constructor code
		this->head = new Node(*(src.head));
		current = src.head;
		Node * thisCurrent = this->head;
		// copy using look ahead
		while (current->next) {
			thisCurrent->next = new Node(*(current->next));
			current = current->next;
			thisCurrent = thisCurrent->next;
		}
		this->size = src.size;
	}
	return *this;
}
ostream & operator << (ostream & out, const List & src) {
	src.display();
	return out;
}
// compare sizes of linked lists
bool operator < (const List & a, const List & b) {
	return a.size < b.size;
}
bool operator > (const List & a, const List & b) {
	return a.size > b.size;
}
// display entire list
void List::display() const {
	Node * current = this->head;
	while (current) {
		cout << *(current->data);
		current = current->next;
	}
}
// display recursively
void List::display(Node * current) const {
	if (current) {
		cout << *(current->data);
		display(current->next);
	}
}
// display by topic
void List::displayByTopic(char * topic) const {
	Node * current = this->head;
	char * currentTopic = nullptr;
	while (current) {
		currentTopic = current->data->getTopic();
		if (strcmp(topic, currentTopic) == 0) cout << *(current->data);
		current = current->next;
		delete [] currentTopic;
	}
}
// add website to list in order of rating
bool List::addSite(Website * w) {
	Node * n = new Node(w);
	Node * current = this->head;
	this->size++;
	// if list is empty or inserting at head
	if (!current || current->data->getRating() >= n->data->getRating()) {
		n->next = this->head;
		this->head = n;
		return true;
	}
	// else add by rating 
	else {
		// navigate to right spot using look-ahead
		while (current->next && *(current->next->data) < *(n->data)) {
					current = current->next;
		}
		// current should not reach nullptr
		// insert node after current and before current next
		n->next = current->next;
		current->next = n;
		return true;
	}
}
// add website to list recursively in order of rating
bool List::addWebsite(Website * w, Node * current) {
	if (!current) {
		current = new Node(w);
		return true;
	}
	if (w->getRating() < current->data->getRating()) {
		Node * newNode = new Node(w);
		if (current == this->head) this->head = newNode;
		newNode->next = current;
		current = newNode;
		return true;
	}
	addWebsite(w, current->next);
	return true;
}
// edit rating for a given website
bool List::editRating(char * websiteName, int rating) {
	Node * current = this->head;
	char * name = nullptr;
	while (current) {
		name = current->data->getName();
		if (strcmp(websiteName, name) == 0) {
			delete [] name;
			current->data->setRating(rating);
			return true;
		}
		current = current->next;
		delete [] name;
	}
	return false;
}
// edit rating for a given website recursively
bool List::editRating(char * websiteName, int rating, Node * current) {
	char * name = nullptr;
	if (current) {
		name = current->data->getName();
		if (strcmp(name, websiteName) == 0) {
			delete [] name;
			current->data->setRating(rating);
			return true;
		}
		delete [] name;
		editRating(websiteName, rating, current->next);
	}
	return false;
}
// edit review
bool List::editReview(char * websiteName, char * review) {
	Node * current = this->head;
	char * name = nullptr;
	while (current) {
		name = current->data->getName();
		if (strcmp(name, websiteName) == 0) {
			delete [] name;
			current->data->setReview(review);
			return true;
		}
		delete [] name;
		current = current->next;
	}
	return false;
}
// edit review recursively
bool List::editReview(char * websiteName, char * review, Node * current) {
	// if list empty or deleting head
	char * name = nullptr;
	if (current) {
		name = current->data->getName();
		if (strcmp(name, websiteName) == 0) {
			delete [] name;
			current->data->setReview(review);
			return true;
		}
		delete [] name;
		editReview(websiteName, review, current->next);
	}
	return false;
}
// remove websites under a given review threshold
bool List::removeSitesUnder(int rating) {
	return removeSitesUnder(rating, this->head);
	Node * current = this->head;
	Node * temp = nullptr;
	bool found = false;
	// check head, then remove head if less than threshold
	// while loop to remove consecutive values
	while (current && current->data->getRating() < rating) {
		this->head = this->head->next;
		delete current;
		// reset current
		current = this->head;
		this->size--;
		found = true;
	}
	// search using look ahead (search both, no else statement here)
	while (current->next) {
		if (current->next->data->getRating() < rating) {
			// remove current next
			temp = current->next;
			current->next = current->next->next;
			delete temp;
			this->size--;
			found = true;
		}
		current = current->next;
	}
	return found;
}
// remove websites under a given review threshold recursively
bool List::removeSitesUnder(int rating, Node * current) {
	if (!current) return false;
	if (current->data->getRating() < rating) {
		if (current == this->head) this->head = this->head->next;
		Node * dummy = current;
		current = current->next;
		delete dummy;
		size--;
	}
	return removeSitesUnder(rating, current->next);
	return true;
}
// get length of list
int List::getSize() const {
	return this->size;
}
// whether list contains anything or not
bool List::isEmpty() {
	if (this->head) {
		return false;
	}
	else {
		return true;
	}
}
// find a given name in the list
bool List::find(char * name) const {
	Node * current = this->head;
	char * currentName = nullptr;
	while (current) {
		currentName = current->data->getName();
		if (strcmp(name, currentName) == 0) {
			delete [] currentName;
			return true;
		}
		current = current->next;
		delete [] currentName;
	}
	return false;
}
// retrieve and store in matches and numFound
bool List::retrieve(char * topic, Website *& matches, int & numFound) {
	Node * current = this->head;
	char * currentTopic = nullptr;
	Website * dummy = nullptr;
	int currentSize = 0;
	while (current) {
		currentTopic = current->data->getTopic();
		// if matches
		if (strcmp(topic, currentTopic) == 0) {
			// store previous matches in dummy and delete old matches
			dummy = new Website[currentSize + 1];
			// copy data into dummy
			for (int i = 0; i < currentSize; i++) {
				dummy[i] = matches[i];
			} 
			// delete old matches
			if (matches) delete [] matches;
			// create new larger array for matches and copy old data
			matches = new Website[currentSize + 1];
			for (int i = 0; i < currentSize; i++) {
				matches[i] = dummy[i];
			}
			// add new data
			matches[currentSize] = *(current->data);
			currentSize++;
			delete [] dummy;
		}
		if (currentTopic) delete [] currentTopic;
		current = current->next;
	}
	numFound = currentSize;
	return true;
}
