#ifndef LAB5UTPOD_SONG_H
#define LAB5UTPOD_SONG_H
#include <iostream>
#include <string>

using namespace std;


class Song {
private:

    string title;
    string artist;
    int size;

public:

    Song();
    Song(string title);
    Song(string title, string artist, int size);

    string getTitle() const;

    void setTitle(string t);


    string getArtist() const;
    void setArtist(string address);
    int getSize() const;
    void setSize(int s);

    void swap(Song &p);

    bool operator >(Song const &rhs);
    bool operator <(Song const &rhs);
    bool operator ==(Song const &rhs);


    // do i need ~Song();
};

#endif

