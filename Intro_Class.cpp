// Structs-Class.cpp : Defines the entry point for the console application.
//
//#include "stdafx.h" <-- Use if necessary to compile
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
/*Class called "Song" for the student name, title of the song, artist, genre, duration*/
class Song {
public:
	void setName(string name);
	void setTitle(string title);
	void setArtist(string artist);
	void setGenre(string genre);
	void setDuration(double mins);
	string getName();
	string getTitle();
	string getArtist();
	string getGenre();
	double getDuration();
private:
	string name;
	string title;
	string artist;
	string genre;
	double mins; //make minor change to hours and mins when finished
};

void Song::setName(string name) {
	this->name = name;
};
void Song::setTitle(string title) {
	this->title = title;
};
void Song::setArtist(string artist) {
	this->artist = artist;
};
void Song::setGenre(string genre) {
	this->genre = genre;
};
void Song::setDuration(double mins){
	this->mins = mins;
};

string Song::getName() {
	return this->name;
};
string Song::getTitle() {
	return this->title;
};
string Song::getArtist() {
	return this->artist;
};
string Song::getGenre() {
	return this->genre;
};
double Song::getDuration() {
	return this->mins;

};

string name, title, artist, genre; double mins;

int main()
{
	Song student1;
	/* 
		The following 5 lines prompt for and accept information
		then proceed to put info in student1's private variables,
		which is why the setter class functions must be called 
	*/

	cout << "Student Name: "; getline(cin, name); student1.setName(name);
	cout << "Title of your favourite song: "; getline(cin, title);student1.setTitle(title);
	cout << "Artist of this song: "; getline(cin, artist);student1.setArtist(artist);
	cout << "Song Genre: "; getline(cin, genre);student1.setGenre(genre);
	cout << "Song Length (minutes): "; cin >> mins;student1.setDuration(mins);

	cout << endl << endl << endl <<  endl;
	cout << "Student 1: " << student1.getName() << endl << endl;
	cout << "Favorite Song Info: \n\n\t" << student1.getArtist() << " ' " << student1.getTitle() << " ' " << endl;
	cout << "\n\t Genre: " << student1.getGenre() << "\n\t Song Length (minutes): " << student1.getDuration() << "\n\n";
		
	return 0;
}
