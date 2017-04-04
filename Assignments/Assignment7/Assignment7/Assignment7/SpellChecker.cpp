//
//  SpellChecker.cpp
//  Assignment7
//
//  Created by John on 3/23/17.
//  Copyright © 2017 John. All rights reserved.
//

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "SpellChecker.h"

SpellChecker::SpellChecker(string lang,string valid_words_filename,string misspelled_filename){
    // takes in: language, filename correct, filename mispelled
    language = lang;
    loadValidWords(valid_words_filename);
    loadMisspelledWords(misspelled_filename);
}
SpellChecker::SpellChecker(string lang){
    // takes in: language
    
    language = lang;
}

SpellChecker::SpellChecker(){
    
}
SpellChecker::~SpellChecker(){
    
}

// PUBLIC FUNCTIONS

bool SpellChecker::loadValidWords(string filename){
    ifstream file;
    file.open(filename.c_str());
    if(file.is_open()) {
        string line;
        while(getline(file,line)){
            validWords.push_back(line);
        }
        file.close();
        return true;
    } else {
        return false;
    }
}
bool SpellChecker::loadMisspelledWords(string filename){
    ifstream file;
    file.open(filename.c_str());
    if(file.is_open()) {
        string line;
        while(getline(file,line)){
            string result;
            istringstream ss(line);
            vector<string> temp;
            
            while(getline(ss,result,'\t')){
                temp.push_back(result);
            }
            mispelledWords.push_back(temp);
        }
        file.close();
        return true;
    } else {
        return false;
    }
}

string SpellChecker::fixUp(string sentence){
    // First, let's remove all the punctuation marks
    vector<char> positions_to_remove;
    
    for(int i = 0;i<punctuationChars.size();i++){
        char punc = punctuationChars[i];
        for (int i = 0; i < sentence.size(); i++){
            if (sentence[i] == punc){
                // Character in string is a punctuation mark! Now, let's test to see if it is
                // (1) at the beginning of the string
                // (2) has a space in front of the char
                // (3) has a space following the char
                // (4) is at the end of the sentance
                if(i == 0 || sentence[i-1] == ' ' || sentence[i+1] == ' ' || i+1 == sentence.length()){
                    sentence.replace(sentence.find(punc),1,"");
                }
            }
        }
    }
    // Now, let's make the string all lowercase
    locale loc;
    for(int i=0; i<sentence.length();i++){
        sentence[i] = tolower(sentence[i],loc);
    }
    
    // Finally, let's itterate through the words within the string!
    string word;
    istringstream ss(sentence);
    while(getline(ss,word,' ')){
        // Define the variables
        string oldWord = word;
        bool isValid = false;
        bool isMispelled = false;
        // Search through correct words
        
        for(int i = 0;i<validWords.size();i++){
            if(word==validWords[i]){
                isValid = true;
                // since the word is valid, do nothing
            }
        }
        
        // Search through mispelled words
        
        if(isValid == false){
            for(int i = 0;i<mispelledWords.size();i++){
                vector<string> temp = mispelledWords[i];
                if(word==temp[0]){
                    isMispelled = true;
                    word = temp[1];
                }
            }
        }
        
        // Now let's see if we need to add any characters...
        if(isValid == false && isMispelled == false) {
            word = begin_mark + word + end_mark;
        }
        
        // Replace the old word with the updated word
        sentence.replace(sentence.find(oldWord),oldWord.length(),word);
    }
    
    return sentence;
}


void SpellChecker::setBeginMarker(char begin){
    begin_mark = begin;
}
void SpellChecker::setEndMarker(char end){
    end_mark = end;
}
char SpellChecker::getBeginMarker(){
    return begin_mark;
}
char SpellChecker::getEndMarker(){
    return end_mark;
}


void SpellChecker::checkData(){
    // Spits out the data for each file
    
    cout << "Valid words: " << endl;
    
    for(int i=0;i<validWords.size();i++){
        cout << i << ": " << validWords[i] << endl;
    }
    
    cout << "Mispelled words: " << endl;
    for(int i=0;i<mispelledWords.size();i++){
        vector<string> temp = mispelledWords[i];
        cout << i << ": " << temp[0] << " - " << temp[1] << endl;
    }
}
