//#include "stdafx.h" <-- Use this library if necessary for your compiler
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include "Song.h"
using namespace std;
void StringSplitter(string line);
string Song[5];

int main() {
	string y;
	ifstream playlist;playlist.open("playlist.csv");
	ofstream classSongs;classSongs.open("class_songs.txt");

	if (!playlist.is_open()) {
		cout << "File not found" << endl;
	};

	cout << "I built a function/program that splits string using comma delimiters"
		<< "\nfor now it is really specific to my program"
		<< ", not a template as I will make it another time."
		<< "\nBy the way, I had to correct some of the info in the file eg. spelling etc"
		<< endl;

	while (!playlist.eof()) {
		
		getline(playlist, y, '\n');
		StringSplitter(y);
		
		classSongs << Song[0] << "'s favorite song is '" << Song[2] << "' by "
			<< Song[1] << " with a duration of "
			<< Song[3] << " and genre of " << Song[4] << "." << endl;
	};
	
	/*Gloria Washington's favorite song is 'Greatest Love Of All'
	by Whitney Houston with a duration of 3.30 and genre of Pop.*/

	playlist.close();
	classSongs.close();
	
	return 0;
}
void StringSplitter(string line) {
	
	int iter, firstcomma_pos; int full_len_step;

	//String Splitter using comma delimitation
	for (iter = 0;iter < 5;iter++) {
		
		if (iter == 4) {//if statement for when comma finished, use .length() to catch the genre

			Song[4] = line.substr(0, line.length());//for the last item, there is no preceding comma to use as a marker
			
			break;
		}

		firstcomma_pos = line.find(',');// continuously update comma pos to cut out string
		Song[iter] = line.substr(0, firstcomma_pos);//string extracter using comma delimiter
		
		full_len_step = line.length() - (firstcomma_pos + 1); //length tracked to continuously update parent string
		line = line.substr((firstcomma_pos + 1), full_len_step);//constantly updating parent string
	}
};
