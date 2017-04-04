//
//  main.cpp
//  Assignment7
//
//  Created by John on 3/20/17.
//  Copyright © 2017 John. All rights reserved.
//

#include "SpellChecker.h"
#include "WordCounts.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;



int main() {
    vector<string> phrasesToCheck;
    
//    ifstream file;
//    file.open("GOODALL.txt");
//    if(file.is_open()) {
//        string line;
//        while(getline(file,line)){
//            phrasesToCheck.push_back(line);
//        }
//        file.close();
//    } else {
//        cout << "Error opening file..." << endl;
//    }
//    

    phrasesToCheck.push_back("tomor is another day");
    phrasesToCheck.push_back("tomorrow is another dat");
    
    // -------------------------------------------------------
    
    WordCounts count;
    
    SpellChecker check("English");
    check.loadValidWords("VALID_WORDS_3000.txt");
    check.loadValidWords("VALID_WORDS_3000.txt");
    check.loadMisspelledWords("MISSPELLED.txt");
    check.loadMisspelledWords("TEXT_2_ENGLISH.txt");
    
    for(int i=0;i<phrasesToCheck.size();i++){
        cout << check.fixUp(phrasesToCheck[i]) << endl;
        count.countWords(phrasesToCheck[i]);
    }
    
    int common_arr_count = 20;
    string common_words[20];
    int common_count[20];
    
    count.mostCommon(common_words, common_count, common_arr_count);
    
    for(int i=0; i<common_arr_count; i++){
//        cout << common_words[i] << " with " << common_count[i] << endl;
    }
    
    //count.showAll();
    //check.checkData();
}
