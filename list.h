#pragma once
#include "website.h"
using namespace std;

class List {
	private:
		struct Node {
			Node * next;
			Website * data;
			Node() {
				data = nullptr;
				next = nullptr;
			}
			// only use for copying data
			Node(const Node & src) {
				data = new Website(*(src.data));
				next = nullptr;
			}
			// only for new data
			Node(Website * w) {
				data = w;
				next = nullptr;
			}
			~Node() {
				if (data) {
					delete data;
					data = nullptr;
				}
			}
		};
		Node * head;
		int size;
	public:
		// constructors
		List();
		List(const List & src);
		// destructor
		~List();
		// recursive destructor
		void recursiveDestroy(Node *& head);
		// overloaded operators
		List & operator = (const List & src);	
    friend ostream & operator << (ostream & out, const List & src);
		friend bool operator < (const List & a, const List & b);
		friend bool operator > (const List & a, const List & b);
		// display entire list
		void display() const;
		// display recursively
		void display(Node * head) const;
		// display by topic
		void displayByTopic(char * topic) const;
		// add website to list in order of rating
		bool addSite(Website * w);
		// add website to list recursively in order of rating
		bool addWebsite(Website * w, Node * head);
		// edit rating for a given website
		bool editRating(char * websiteName, int rating);
		// edit rating for a given website recursively
		bool editRating(char * websiteName, int rating, Node * head);
		// edit review
		bool editReview(char * websiteName, char * review);
		// edit review recursively
		bool editReview(char * websiteName, char * review, Node * head);
		// remove websites under a given review threshold
		bool removeSitesUnder(int rating);
		// remove websites under a given review threshold recursively
		bool removeSitesUnder(int rating, Node * hear);
		// get length of list
		int getSize() const;
		// whether list contains anything or not
		bool isEmpty();
		// find a given name in the list
		bool find(char * name) const;
		// retrieve and store in matches and numFound
		bool retrieve(char * topic, Website *& matches, int & numFound);
};
