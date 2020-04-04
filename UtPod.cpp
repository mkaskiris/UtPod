#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <time.h>
#include "UtPod.h"
#include "Song.h"

UtPod::UtPod(){
    memSize = MAX_MEMORY;
    songs = NULL;
}

UtPod::UtPod(int size) {
    if(size < 0 || size > 512) //constrains
        memSize = 512;
    else
        memSize = size;
    songs = NULL;
}

void UtPod::clearMemory(){
    SongNode* temp = songs; //iterators
    SongNode* prev = songs;
    while(prev != NULL){ //iterate list and delete nodes
        temp = temp->next;
        delete(prev);
        prev = temp;
    }
    songs = NULL;
}

UtPod::~UtPod() {
    clearMemory();
}

int UtPod::addSong(S::Song const &s) {
    if (getRemainingMemory() > s.getSize()) { //check if available space
        auto *temp = new SongNode; //create a new SongNode
        temp->s = s; //put data into node
        temp->next = songs; //put at top of list
        songs = temp;
        return SUCCESS;
    }else
        return NO_MEMORY;
}

int UtPod::removeSong(const S::Song &s) { //theres a problem here bruh

    SongNode *cur = songs;
    SongNode *prev = cur;
    //if list is empty
    if(songs == NULL)
        return NOT_FOUND;
    //if its the first and only song
    if(songs->next == NULL && cur->s.getTitle() == s.getTitle() && cur->s.getArtist() == s.getArtist() && cur->s.getSize() == s.getSize()){
        clearMemory();
        return SUCCESS;
    }
    //if its any other song in the list
    while(cur != NULL){
        if(cur->s.getTitle() == s.getTitle() && cur->s.getArtist() == s.getArtist() && cur->s.getSize() == s.getSize()){//found
            prev->next = cur->next;
            if(cur == songs) //if song to be deleted is head re-assign head
                songs = cur->next;
            delete(cur);
            return SUCCESS;
        }
        prev = cur;
        cur = cur->next;
    }
    return NOT_FOUND;
}

void UtPod:: showSongList() {
    SongNode *cur = songs;
    int i = 1;
    while(cur != NULL){ //iterate list and print each song
        std::cout << i << ". ";
        std::cout << cur->s;
        cur = cur->next;
        i++;
    }
}

void swap(S::Song &s1, S::Song &s2){ //swap 2 songs, could be a template
    S::Song temp = s1;
    s1 = s2;
    s2 = temp;
}

void UtPod::sortSongList(){ //bubble sorting the list
    if(songs == NULL || songs->next == NULL){
        return; //list already sorted
    }
    SongNode *cur; //create dummy nodes to iterate list
    SongNode *last = NULL;
    int swapped;

    do{//keep iterating through the list if there has been at least one swap in the previous iteration
        swapped =0;
        cur = songs;
        while(cur->next != last) {
            if (cur->s > cur->next->s) { //if current is bigger than next swap
                swap(cur->s, cur->next->s);
                swapped = 1;
            }
            cur = cur->next;
        }
        last = cur;
    }while(swapped);
}


void UtPod:: shuffle(){
    //find length of list (# of songs)
    SongNode *cur = songs;
    int count = 0;
    while(cur != NULL){
        count++;
        cur = cur->next;
    }

    if(count == 2) {//if only 2 songs in list
        swap(songs->s,songs->next->s);
        return;
    }
    if(count <= 1) //if 1 or less songs
        return;

    auto currentTime = (unsigned) time(NULL);
    srand(currentTime); //RANDOM SEED

    int shufflingTimes = 10*count;
    for(int j = 0; j < shufflingTimes; j++) {
        //get 2 nodes and switch them

        int f = rand() % count;//first number
        int s = rand() % count;//second number


        SongNode *first = songs; //iterators
        SongNode *second = songs;
        int i = 0;

        //find the songs in the list and swap them
        while (i < f) {
            first = first->next;
            i++;
        }
        i = 0;
        while (i < s) {
            second = second->next;
            i++;
        }
        swap(first->s, second->s);
    }

}

int UtPod:: getRemainingMemory(){
    int rem = getTotalMemory(); //initial memory value
    SongNode *cur = songs;
    while(cur != NULL){ //subtract size of songs in the list
        rem -= cur->s.getSize();
        cur = cur->next;
    }
    return rem;
}