#pragma once
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class Website {
	private:
		char * name;
		char * url;
		char * topic;
		char * desc;
		char * review;
		int rating;
	public:
		// constructors
		Website();
		Website(char * name, char * url, char * topic, char * desc, char * review, int rating);
		Website(const Website & src);
		// destructor
		~Website();
		// overloaded operators
		friend ostream & operator << (ostream & out, const Website & src);
		Website & operator = (const Website & src);
		friend bool operator < (const Website & a, const Website & b);	// by rating
		friend bool operator > (const Website & a, const Website & b);	// by rating
		// getters
		char * getName() const;
		char * getUrl() const;
		char * getTopic() const;
		char * getDesc() const;
		char * getReview() const;
		int getRating() const;
		// setters
		void setName(char * newName);
		void setUrl(char * newUrl);
		void setTopic(char * newTopic);
		void setDesc(char * newDesc);
		void setReview(char * newReview);
		void setRating(int newRating);
		// display function
		void display() const;
};
