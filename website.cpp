#include "website.h"
using namespace std;

// constructors
Website::Website() {
	this->name = nullptr;
	this->url = nullptr;
	this->topic = nullptr;
	this->desc = nullptr;
	this->review = nullptr;
	this->rating = 0;
}
Website::Website(char * name, char * url, char * topic, char * desc, char * review, int rating) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->url = new char[strlen(url) + 1];
	strcpy(this->url, url);
	this->topic = new char[strlen(topic) + 1];
	strcpy(this->topic, topic);
	this->desc = new char[strlen(desc) + 1];
	strcpy(this->desc, desc);
	this->review = new char[strlen(review) + 1];
	strcpy(this->review, review);
	this->rating = rating;
}
Website::Website(const Website & src) {
	this->name = new char[strlen(src.name) + 1];
	strcpy(this->name, src.name);
	this->url = new char[strlen(src.url) + 1];
	strcpy(this->url, src.url);
	this->topic = new char[strlen(src.topic) + 1];
	strcpy(this->topic, src.topic);
	this->desc = new char[strlen(src.desc) + 1];
	strcpy(this->desc, src.desc);
	this->review = new char[strlen(src.review) + 1];
	strcpy(this->review, src.review);
	this->rating = src.rating;
}
// destructor
Website::~Website() {
	if (this->name) {
		delete [] this->name;
		name = nullptr;
	}
	if (this->url) {
		delete [] this->url;
		url = nullptr;
	}
	if (this->topic) {
		delete [] this->topic;
		topic = nullptr;
	}
	if (this->desc) {
		delete [] this->desc;
		desc = nullptr;
	}
	if (this->review) {
		delete [] this->review;
		review = nullptr;
	}
	rating = 0;
}
// overloaded operators
ostream & operator << (ostream & out, const Website & src) {
	src.display();
	return out;
}
Website & Website::operator = (const Website & src) {
	if (this != &src) {
		if (this->name) {
			delete [] this->name;
			name = nullptr;
		}
		if (this->url) {
			delete [] this->url;
			url = nullptr;
		}
		if (this->topic) {
			delete [] this->topic;
			topic = nullptr;
		}
		if (this->desc) {
			delete [] this->desc;
			desc = nullptr;
		}
		if (this->review) {
			delete [] this->review;
			review = nullptr;
		}
		this->name = new char[strlen(src.name) + 1];
		strcpy(this->name, src.name);
		this->url = new char[strlen(src.url) + 1];
		strcpy(this->url, src.url);
		this->topic = new char[strlen(src.topic) + 1];
		strcpy(this->topic, src.topic);
		this->desc = new char[strlen(src.desc) + 1];
		strcpy(this->desc, src.desc);
		this->review = new char[strlen(src.review) + 1];
		strcpy(this->review, src.review);
		this->rating = src.rating;
	}
	return *this;
}
// comparison is based on rating
bool operator < (const Website & a, const Website & b) {
	return a.rating < b.rating;
}
bool operator > (const Website & a, const Website & b) {
	return a.rating > b.rating;
}
// getters
char * Website::getName() const {
	char * returnName = new char[strlen(this->name) + 1];
	strcpy(returnName, this->name);
	return returnName;
}
char * Website::getUrl() const {
	char * returnUrl = new char[strlen(this->url) + 1];
	strcpy(returnUrl, this->url);
	return returnUrl;
}
char * Website::getTopic() const {
	char * returnTopic = new char[strlen(this->topic) + 1];
	strcpy(returnTopic, this->topic);
	return returnTopic;
}
char * Website::getDesc() const {
	char * returnDesc = new char[strlen(this->desc) + 1];
	strcpy(returnDesc, this->desc);
	return returnDesc;
}
char * Website::getReview() const {
	char * returnReview = new char[strlen(this->review) + 1];
	strcpy(returnReview, this->review);
	return returnReview;
}
int Website::getRating() const {
	return this->rating;
}
// setters
void Website::setName(char * newName) {
	if (this->name) {
		delete [] this->name;
	}
	this->name = new char[strlen(newName) + 1];
	strcpy(this->name, newName);
}
void Website::setUrl(char * newUrl) {
	if (this->url) {
		delete [] this->url;
	}
	this->url = new char[strlen(newUrl) + 1];
	strcpy(this->url, newUrl);
}
void Website::setTopic(char * newTopic) {
	if (this->topic) {
		delete [] this->topic;
	}
	this->topic = new char[strlen(newTopic) + 1];
	strcpy(this->topic, newTopic);
}
void Website::setDesc(char * newDesc) {
	if (this->desc) {
		delete [] this->desc;
	}
	this->desc = new char[strlen(newDesc) + 1];
	strcpy(this->desc, newDesc);
}
void Website::setReview(char * newReview) {
	if (this->review) {
		delete [] this->review;
	}
	this->review = new char[strlen(newReview) + 1];
	strcpy(this->review, newReview);
}
void Website::setRating(int newRating) {
	this->rating = newRating;
}
// display a single website
void Website::display() const {
	cout << endl;
	cout << "  " << this->name << endl;
	cout << "  " << this->url << endl;
	cout << "  " << this->topic << endl;
	cout << "  " << this->desc << endl;
	cout << "  " << this->review << endl;
	cout << endl;
	cout << "  ";
	for (int i = 0; i < this->rating; i++) {
		cout << "*  ";
	}
	cout << endl;
}


