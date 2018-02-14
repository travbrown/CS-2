#ifndef SONG_H
#define SONG_H
using namespace std;
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
	double mins;
};

#endif
