#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

//using namespace std;

int main(){
    //testing cosntructors
    UtPod t1(1000);
    std::cout << "Constructor input 1000, total memory: " << t1.getTotalMemory() <<std:: endl;

    UtPod t2(432);
    std::cout << "Constructor input 432, total memory: " << t2.getTotalMemory() <<std:: endl;

    UtPod t3(-95);
    std::cout << "Constructor input -95, total memory:  " << t3.getTotalMemory() <<std:: endl;

    UtPod t; //defualt constructor

    std::cout << "Default constructor memory: " << t.getTotalMemory() <<std:: endl; //check initial and remaining memory
    std::cout << "Remaining memory: " << t.getRemainingMemory() <<std:: endl;

    std::cout<<"Adding songs to pod object constructed with default constructor"<<std::endl;

    S::Song song("art", "namme", 5);
    int res = t.removeSong(song); //try to remove song which is not in list
    std::cout<<"Try to remove song from an empty list"<<std::endl;
    std:: cout << "Remove result = " << res << std::endl;
    std::cout << "Remaining memory: " << t.getRemainingMemory() <<std:: endl;

    std::cout << "Adding songs to empty list"<<std::endl;

    S::Song s1("art", "name", 5);
    int result = t.addSong(s1); //add to empty list
    std::cout<<"Add 1 result: "<< result <<std::endl;
    std::cout << "Remaining memory: " << t.getRemainingMemory() <<std:: endl;

    S::Song s2("2", "a", 5);
    std::cout<<"Trying to add to already created list"<<std::endl;
    result = t.addSong(s2);
    std::cout<<"Add 2 result: "<< result <<std::endl;
    std::cout << "Remaining memory: " << t.getRemainingMemory() <<std:: endl; //test remaining memory after each add

    S::Song s3("2", "a", 6);
    result = t.addSong(s3);
    std::cout<<"Add 3 result: "<< result <<std::endl;
    std::cout << "Remaining memory: " << t.getRemainingMemory() <<std:: endl;

    S::Song s4("Beatles", "Hey Jude1", 4);
    result = t.addSong(s4);
    std::cout<<"Add 4 result: "<< result <<std::endl;
    std::cout << "Remaining memory: " << t.getRemainingMemory() <<std:: endl;

    S::Song s5("Beatles", "Hey Jude2", 5);
    result = t.addSong(s5);
    std::cout<<"Add 5 result: "<< result <<std::endl;
    std::cout << "Remaining memory: " << t.getRemainingMemory() <<std:: endl;

    S::Song s6("Beatles", "Hey Jude3", 6);
    result = t.addSong(s6);
    std::cout<<"Add 6 result: "<< result <<std::endl;
    std::cout << "Remaining memory: " << t.getRemainingMemory() <<std:: endl;
    std::cout<<"try to remove last added song"<<std::endl;
    t.removeSong(s6);
    std::cout << "Remaining memory after deletion of song (should b +6): " << t.getRemainingMemory() <<std:: endl;

    S::Song s7("Beatles", "Hey Jude4", 7);
    result = t.addSong(s7);
    std::cout<<"Add 7 result: "<< result <<std::endl;
    std::cout << "Remaining memory: " << t.getRemainingMemory() <<std:: endl;

    S::Song s8("Beatles", "Hey Jude5", 600);
    result = t.addSong(s8);
    std::cout<<"try to add song over the capacity" <<std::endl;
    std::cout<<"Add  8 result: "<< result <<std::endl;
    std::cout << "Remaining memory: " << t.getRemainingMemory() <<std:: endl;

    std::cout<<"Printing List"<<std::endl;
    t.showSongList(); //check printing is ok with occupied list

    std::cout<<"Remove last song from list"<<std::endl;
    res = t.removeSong(s7); //jude5
    std::cout << "Removal result: "<<res << std::endl;

    std::cout << "Print sorted list" <<std::endl;
    t.sortSongList();
    t.showSongList();//check sorting after initial creation of list

    std::cout << "Try to remove song not in list, but list exists" <<std::endl;
    res = t.removeSong(song); //try to remove song which is not in list
    std:: cout << "Remove result = " << res << std::endl;

    std::cout << "Print shuffled list" <<std::endl;
    t.shuffle(); //check shuffle
    t.showSongList();

    std::cout<<"Try to remove song of shuffled list"<<std::endl;
    result = t.removeSong(s3);
    std::cout << "Removal result"<<res << std::endl;
    std::cout<<"Try to add song of shuffled list"<<std::endl;
    result = t.addSong(s3);
    std:: cout << "Add result = " << res << std::endl;

    std::cout<<"Sort shuffled list"<<std::endl;
    t.sortSongList(); //sort empty list
    t.showSongList(); //check sorting after shuffling & removing song

    std::cout<<"Remaining memory before clearmemory(): " << t.getRemainingMemory() <<std::endl;
    t.clearMemory(); //check clear memory
    std::cout<<"Remaining memory after clearmemory(): " << t.getRemainingMemory() <<std::endl;

    std::cout<<"Try to sort empty list and show"<<std::endl;
    t.sortSongList();
    t.showSongList(); //check show with empty list
    std::cout <<std::endl;

    std:: cout << "Remaining memory: " << t.getRemainingMemory()<<std::endl;
    std::cout << "Total memory: " << t.getTotalMemory() <<std:: endl;
    
    return 0;
}