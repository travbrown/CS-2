#include<iostream>
using namespace std;
#include "Song.h"

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
void Song::setDuration(double mins) {
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