#include <iostream>
#include <string>
#include "song.h"

using namespace std;

string Song::getTitle() const
{
    return title;
}

void Song::setTitle(string t)
{
    title = t;
}



Song::Song(){
    title = "";
    artist = "";
    size = 0;

}
Song::Song(string title){
    this-> title = title;
    artist = "";
    size = 0;

}
Song::Song(string title, string artist, int size){

    this -> title = title;
    this ->artist = artist;
    this ->size = size;

}


string Song::getArtist()const{
    return artist;

}
void Song::setArtist(string artist){
    this->artist = artist;

}
int Song::getSize()const {
    return size;

}
void Song::setSize(int s){
     size = s;

}

void Song::swap(Song &p){
    Song temp = p;
    p = *this;
    *this = temp;

}

bool Song::operator >(Song const &rhs){
    if(this->artist> rhs.artist) {
        return true;
    }
    else if (this->title>rhs.title) {
        return true;
    }
    else if (this->size> rhs. size) {
        return true;
    }
    else {
        return false;
    }

}
bool Song::operator <(Song const &rhs){
    if(this->artist< rhs.artist) {
        return true;
    }
    else if (this->title<rhs.title) {
        return true;
    }
    else if (this->size< rhs. size) {
        return true;
    }
    else {
        return false;
    }

}
bool Song::operator ==(Song const &rhs){
    if (this->artist == rhs.artist && this->title == rhs.title && this->size== rhs.size){
        return true;
    }
    else {
        return false;
    }
}