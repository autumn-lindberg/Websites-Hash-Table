#pragma once
#include "website.h"
#include "list.h"
using namespace std;

class Table {
	private:
		List * data;
		int size;
		// return a hash for a given topic;
		int hash(char * topic);
	public:
		// constructors
		Table();
		Table(int size);
		Table(const Table & src);
		// destructor
		~Table();
		// overloaded operators
		friend ostream & operator << (ostream & out, const Table & src);
		Table & operator = (const Table & src);
		// add a website to table
		bool addSite(Website * w);
		// display a linked list based on topic, store in matches  & numFound
		bool retrieve(char * topic, Website * matches, int & numFound);
		// edit the review for a given topic and website name
		bool editReview(char * topic, char * name, char * newReview);
		// edit the rating for a given topic and website name
		bool editRating(char * topic, char * name, int newReview);
		// remove all websites under a given rating
		bool removeSitesUnder(int rating);
		// display songs that match a given topic
		void displayByTopic(char * topic);
		// display all songs
		void displayAll() const;
		// display performance by showing the length of each chain
		void analyzePerformance();
};
