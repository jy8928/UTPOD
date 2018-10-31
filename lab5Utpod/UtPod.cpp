#include "song.h"
#include "UtPod.h"
#include <cstdlib>
#include <time.h>

using namespace std;


UtPod::UtPod(){
    memSize = MAX_MEMORY;
    songs = NULL;
}

//Constructor with size parameter
//The user of the class will pass in a size.
//If the size is greater than MAX_MEMORY or less than or equal to 0,
//set the size to MAX_MEMORY.
UtPod::UtPod(int size){

    if(size> MAX_MEMORY || size<= 0)
    {
        memSize= MAX_MEMORY;
    }
    else {
        memSize = size;
    }
    songs = NULL;
}

/* FUNCTION - int addSong
 * attempts to add a new song to the UtPod
     o returns a 0 if successful
     o returns -1 if not enough memory to add the song

 precondition: s is a valid Song

 input parms -

 output parms -
*/

int UtPod::addSong(Song const &newS){


    SongNode* cur;

    if (getRemainingMemory() < newS.getSize()) {
        return NO_MEMORY;
    }
    if (songs == NULL) {
        SongNode* newNode_NTH = new SongNode();

        newNode_NTH->s.setArtist(newS.getArtist());
        newNode_NTH->s.setTitle(newS.getTitle());
        newNode_NTH->s.setSize(newS.getSize());

        //newNode_NTH->s = newS;
        newNode_NTH->next = NULL;
        // Add song to end of list
        songs = newNode_NTH ;
        return SUCCESS;
    }
    else {
        for (cur = songs; cur->next != NULL; cur = cur->next);    // Traverse linked list

        SongNode *newNode = new SongNode();                   // Create new node for song being added

        newNode->s.setArtist(newS.getArtist());
        newNode->s.setTitle(newS.getTitle());
        newNode->s.setSize(newS.getSize());
        //newNode->s = newS;
        newNode->next = NULL;                               // Add song to end of list
        cur->next = newNode;
        return SUCCESS;
        // songs = temp;
    }



}


/* FUNCTION - int removeSong
 * attempts to remove a song from the UtPod
 * removes the first instance of a song that is in the the UtPod multiple times
     o returns 0 if successful
     o returns -1 if nothing is removed


   input parms -

   output parms -
*/



int UtPod::removeSong(Song const &removeS) {
    SongNode* prev;
    SongNode* cur;

    for (cur = songs, prev = NULL; cur != NULL && !(cur->s == removeS); prev = cur, cur = cur->next);

    if (cur == NULL)
    {
        return  NOT_FOUND;                                      // song not found
    }
    if (prev == NULL){
        songs = songs->next;                             // song in first node
    }
    else {
        prev->next = cur->next;
    }                                                    // song in some other node
    delete cur;
    return SUCCESS;
}


/* FUNCTION - void shuffle
 *  shuffles the sngs into random order
    o will do nothing if there are less than two songs in the current list

   input parms -

   output parms -
*/
int UtPod::NumSongs(SongNode const &head) {                 // count number of songs
    SongNode* cur;
    int cnt = 0;
    for (cur = songs; cur->next != NULL; cur = cur->next){
        cnt++;
    }
    return cnt;
}

long UtPod::Random(SongNode const &head, int numSongs){     // RNG
    int numSides = numSongs;                            // Our "dice" sides based on number of songs
    long dice;

    unsigned int currentTime = 42;

    srand(currentTime);
    for(int i = 0; i<10; i++){
        dice = (rand() % numSides) + 1;
    }
    return dice;                                        // Returns index of a random song in our list of songs
}

void UtPod::shuffle(){
    int numSongs = NumSongs(*songs);
    long index1 = Random(*songs, numSongs);
    long index2 = Random(*songs, numSongs);
    SongNode* song1;
    SongNode* song2;
    SongNode* temp;
    SongNode* cur = songs;
    SongNode* prev1 = cur;
    SongNode* prev2 = cur;

    for (int i = 0; i < index1; i++){                   // Get song #1 data
        prev1 = cur;
        cur = cur->next;
    }
    song1 = cur;

    for (int i = 0; i < index2; i++){                   // Get song #2 data
        prev2 = cur;
        cur = cur->next;
    }
    song2 = cur;
                                                        // Shuffle
    temp->next = song2->next;
    prev1 -> next = song2;
    song2 -> next = song1 -> next;
    prev2 -> next = song1;
    song1 -> next = temp->next;
}


/* FUNCTION - void showSongList
 * prints the current list of songs in order from first to last to standard output
 * format - Title, Artist, size in MB (one song per line)

   input parms -

   output parms -
*/

void UtPod::showSongList(){                                 // Prints out "Title, artist, size MB"
    SongNode* cur;
    for (cur = songs; cur != NULL; cur = cur->next){
        cout << " " << cur->s.getTitle() << "," ;
        cout << " " << cur->s.getArtist() << "," ;
        cout << " " << cur->s.getSize() << "MB\n";
    }

}


/* FUNCTION - void sortSongList
 *  sorts the songs in ascending order
    o will do nothing if there are less than two songs in the current list

   input parms -

   output parms -
*/

void UtPod::sortSongList() {



    SongNode *currentNode = songs;
    SongNode *NextNode = songs;


    int numSongs = NumSongs(*songs);

    if (numSongs < 2) {
        return;
    } else {

        while (currentNode != NULL) {
            SongNode *SmallestNode = currentNode;
            while (NextNode != NULL) {
                if(NextNode->s < SmallestNode->s){
                    SmallestNode = NextNode;
                }
                NextNode = NextNode->next;
            }
            (SmallestNode->s).swap(currentNode->s);
            currentNode = currentNode->next;
            NextNode = currentNode;
        }

    }
}


/* FUNCTION - void clearMemory
 * clears all the songs from memory

   input parms -

   output parms -
*/
void UtPod::clearMemory(){
    int numSongs = NumSongs(*songs);
    /*while (numSongs != 0){                     // Repeat last song deletion until empty
        for (cur = songs; cur->next != NULL; cur = cur->next){        // Get to end of list to get last song
            prev->next = cur;
        }
                            // Change the 2nd to last song to the last song and delete last song

            prev->next = NULL;
        string name = cur->s.getTitle();
        string artist = cur->s.getArtist();
            std::cout << " deleting Node " << cur->s.getTitle()  << " and " << cur->s.getArtist() << std::endl;
            delete cur;
            std::cout << " deleted Node " <<  name  << " and " << artist << std::endl;
        numSongs--;
    }*/
    while(songs != NULL){
        SongNode* head = songs;
        songs = songs->next;
        delete head;
    }

}


/* FUNCTION - int getTotalMemory
 *  returns the total amount of memory in the UtPod
    o will do nothing if there are less than two songs in the current list

   input parms -

   output parms -
*/

int UtPod::getTotalMemory() {                                       // Get total memory
    int TotalmemSize = 0;
    SongNode *cur;
    int numSongs = NumSongs(*songs);
    if(numSongs >= 2){
        for (cur = songs; cur != NULL; cur = cur->next) {
            TotalmemSize = cur->s.getSize()+TotalmemSize;
        }
        return TotalmemSize;
    }
}


/* FUNCTION - int getRemainingMemory
 *  returns the amount of memory available for adding new songs

   input parms -

   output parms -
*/

int UtPod::getRemainingMemory(){                                    // Get memory leftover
    int TotalmemSize = 0;
    SongNode *cur;
    for (cur = songs; cur != NULL; cur = cur->next) {
        TotalmemSize = cur->s.getSize()+TotalmemSize;
    }
    return MAX_MEMORY-TotalmemSize;

}

 UtPod::~UtPod() {
     clearMemory();

 }





