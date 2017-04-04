//
//  WordCounts.cpp
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
#include <algorithm>
using namespace std;

#include "WordCounts.h"


WordCounts::WordCounts(){
    //
}

bool cmd(const string & s1, const string & s2) {
    // This function is what sorts the array
    
    string s1_core = s1;
    string s1_int = s1_core.substr(s1_core.find(':')+1,s1_core.length()-s1_core.find(':'));
    int s1_count = stoi(s1_int);
    
    string s2_core = s2;
    string s2_int = s2_core.substr(s2_core.find(':')+1,s2_core.length()-s2_core.find(':'));
    int s2_count = stoi(s2_int);
    
    if(s1_count > s2_count) {
        return true;
    } else {
        return false;
    }
}

// Public functions

void WordCounts::countWords(string sentence){
    for(int i = 0;i<punct.size();i++){
        char punc = punct[i];
        while(sentence.find(punc)!=string::npos){
            sentence.replace(sentence.find(punc),1,"");
        }
    }

    // Now, let's make the string all lowercase
    locale loc;
    for(int i=0; i<sentence.length();i++){
        sentence[i] = tolower(sentence[i],loc);
    }
    
    // Now, onto the counting!
    string word;
    istringstream ss(sentence);
    while(getline(ss,word,' ')){
        bool counted = false;
        
        
        for(int i=0;i<words.size();i++){
            string testword = words[i];
            string w_substr = testword.substr(0,testword.find(seperatorChar));
            string i_substr = testword.substr(testword.find(seperatorChar)+1,testword.length()-testword.find(seperatorChar));
           // cout << i_substr << endl;
            int count = stoi(i_substr);
            
            if(w_substr == word) {
                count++;
                counted=true;
                
                words[i] = w_substr+":"+to_string(count);
            }
        }
        
        if(counted == false){
            words.push_back(word+":1");
        }
    }
}

int WordCounts::getCount(string word){
    // First, let's make sute the string is all lowercase
    locale loc;
    for(int i=0; i<word.length();i++){
        word[i] = tolower(word[i],loc);
    }
    
    // Now, let's look up the word in our vector
    for(int i=0;i<words.size();i++){
        string testword = words[i];
        string w_substr = testword.substr(0,testword.find(seperatorChar));
        string i_substr = testword.substr(testword.find(seperatorChar)+1,testword.length()-testword.find(seperatorChar));
        
        if(w_substr == word){
            return stoi(i_substr);
        }
    }
    
    // Note: this will only return 0 when no matching string is found
    return 0;
}

void WordCounts::resetCounts(){
    // This command just removes all the data in the vector
    words.clear();
}

int WordCounts::mostCommon(string commonWords[], int wordCount[], int n){
    // Sort the array using the cmd algorithm
    std::sort(words.begin(), words.end(), cmd);

    // Now let's make sure it isnt asking for a number greater than the total words counted
    if(n>words.size()){
        n = (int)words.size();
    }
    
    // Now add n number of words and counts to the arrays
    for(int i=0; i<n; i++){
        string testword = words[i];
        string w_substr = testword.substr(0,testword.find(seperatorChar));
        string i_substr = testword.substr(testword.find(seperatorChar)+1,testword.length()-testword.find(seperatorChar));
        int in = stoi(i_substr);
        
        commonWords[i] = w_substr;
        wordCount[i] = in;
    }
    
    // Finally, return the number of words added to the arrays (which is n)
    return n;
}

// THIS IS SIMPLY A TEST FUNCTION TO SHOW ALL THE COUNTED WORDS; IGNORE

void WordCounts::showAll(){
    for(int i=0;i<words.size();i++){
        cout << words[i] << endl;
    }
}
