//
// Created by mkask on 19/03/2020.
//

#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H

#include <string>
#include <iostream>
#include <utility>

namespace  S {

    class Song {
    private:
        std::string title;
        std::string artist;
        int size;

    public:
        Song() { //default constructor
            title = "";
            artist = "";
            size = 0;
        }

        Song(const Song &s){ //copy constructor
            title  = s.title;
            artist = s.artist;
            size = s.size;
        }

        Song(std::string artist, std::string title, int size) { //cosntructor
            this->title = title;
            this->artist = artist;
            this->size = size;
        }

        ////get and set methods for each of the private variables

        int getSize() const {
            return size;
        }

        std::string getTitle() const {
            return title;
        }

        std::string getArtist() const {
            return artist;
        }

        int setSize(int size){
            return this->size = size;
        }

        std::string setTitle(std::string title){
            this->title = title;
            return title;
        }

        std::string setArtist(std::string artist){
            this->artist = artist;
            return artist;
        }

        ////Operator Overloading
        friend std::ostream &operator <<(std::ostream &output, const Song &s){
            output << "Artist: " << s.artist <<  "\tTitle: " << s.title <<  "\tSize: " << s.size << std::endl;
            return output;
        }

        friend bool operator <(const Song &s1, const Song &s2) {
            //artist->title->size
            if(s1.getArtist() < s2.getArtist())
                return true;
            else if(s1.getArtist() == s2.getArtist()){
                if(s1.getTitle() < s2.getTitle())
                    return true;
                else if(s1.getTitle() == s2.getTitle()) {
                    if (s1.getSize() < s2.getSize())
                        return true;
                }
            }
            return false;
        }

        friend bool operator >(const Song &s1, const Song &s2) {
            //artist->title->size
            if(s1.getArtist() > s2.getArtist())
                return true;
            else if(s1.getArtist() == s2.getArtist()){
                if(s1.getTitle() > s2.getTitle())
                    return true;
                else if(s1.getTitle() == s2.getTitle()) {
                    if (s1.getSize() > s2.getSize())
                        return true;
                }
            }
            return false;
        }

        friend bool operator ==(const Song &s1, const Song &s2){
            return s1.getArtist() == s2.getArtist() && s1.getTitle() == s2.getTitle() && s1.getSize() == s2.getSize();
        }
    };

}

#endif //UTPOD_SONG_H
