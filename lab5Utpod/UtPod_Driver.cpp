///* utPod_driver.cpp
//Demo Driver for the UtPod.
//
//Roger Priebe
//EE 312 10/16/18
//
//This is a basic driver for the UtPod.
//
//You will want to do more complete testing.
//
//*/
//#include <cstdlib>
//#include <iostream>
//#include "song.h"
//#include "UtPod.h"
//
//using namespace std;
//
//int main(int argc, char *argv[])
//
//{
//
//    UtPod t;
//
//
//    Song s1("Beatles", "Hey Jude1", 4);
//
//    int result = t.addSong(s1);
//    cout << "result = " << result << endl;
//
//
//    t.showSongList();
//
//
//     Song s2("Song2", "Hey Jude", 5);
//     result = t.addSong(s2);
//     cout << "result = " << result << endl;
//
//    t.showSongList();
//
//    cout << "made it2  " << endl;
//
//    Song s4("Beatles", "Hey Jude4", 7);
//    result = t.addSong(s4);
//    cout << "result = " << result << endl;
//
//    Song s3("Beatles", "Hey Jude3", 6);
//    result = t.addSong(s3);
//    cout << "result = " << result << endl;
//
//    Song scheck("Beatles", "Hey Jude4", 7);
//    result = t.addSong(s4);
//    cout << "result = " << result << endl;
//
//    Song s5("Beatles", "Hey Jude5", 241);
//    result = t.addSong(s5);
//    cout << "add result = " << result << endl;
//
//    t.showSongList();
//
//    result = t.removeSong(s2);
//    cout << "delete result = " << result << endl;
//
//    result = t.removeSong(s3);
//    cout << "delete result = " << result << endl;
//
//    t.showSongList();
//
//    result = t.removeSong(s1);
//    cout << "delete result = " << result << endl;
//
//    result = t.removeSong(s5);
//    cout << "delete result = " << result << endl;
//
//    result = t.removeSong(s4);
//    cout << "delete result = " << result << endl;
//
//
//    t.showSongList();
//
//    result = t.addSong(s5);
//    cout << "add result = " << result << endl;
//
//    t.showSongList();
//    cout << "memory = " << t.getRemainingMemory() << endl;
//
//    t.showSongList();
//
//
//
//
//}
//
/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.
*/

#include <cstdlib>
#include <iostream>
#include "song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])

{

    UtPod t;

    cout << "Testing show list\n";

    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;

    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;

    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;

    Song s6("Beatles1", "Hey Jude43", 4);
    result = t.addSong(s6);
    cout << "result = " << result << endl;

    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;

    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "result = " << result << endl;

    Song s7("ABBA", "Mamma Mia", 4);
    result = t.addSong(s7);
    cout << "result = " << result << endl;

    t.showSongList();


    cout << "Testing sort, output should be ordered list\n";
    t.sortSongList();
    t.showSongList();


    cout << "Testing remove song after removing HeyJude43, output should be ordered list w/o HeyJude43\n";
    result = t.removeSong(s6);
    cout << "delete result = " << result << endl;
    t.showSongList();

    cout << "Testing add song after adding HeyJude43, output should be ordered list with HeyJude43 at the end\n";
    result = t.addSong(s6);
    cout << "add result = " << result << endl;
    t.showSongList();

    cout << "Testing remaining memory, output should be 245\n";
    cout << "memory remaining = " << t.getRemainingMemory() << endl;

    cout << "Testing total memory, output should be 267\n";
    cout << "total memory used = " << t.getTotalMemory() << endl;

    cout << "Testing shuffle, outputs random song order\n";
    t.shuffle();
    t.showSongList();

    cout << "Testing shuffle again, should be a different output than above";
    t.shuffle();
    t.showSongList();

    cout << "Testing sort once more for good measure, should be the same as the sorted list above\n";
    t.sortSongList();
    t.showSongList();

    cout << "Testing clear memory, list should be empty\n";
    t.clearMemory();
    t.showSongList();
}