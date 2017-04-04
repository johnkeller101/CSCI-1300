//
//  SpellChecker.hpp
//  Assignment7
//
//  Created by John on 3/23/17.
//  Copyright © 2017 John. All rights reserved.
//

#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include <iostream>
#include <vector>

class SpellChecker {
public:
    SpellChecker(std::string lang,std::string f1,std::string f2);
    SpellChecker(std::string);
    SpellChecker();
    ~SpellChecker();
    
    std::string language;
    std::vector<std::vector<std::string>> mispelledWords;
    std::vector<std::string> validWords;
    std::vector<char> punctuationChars = {'!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/',':',';','<','=','>','?','@','[',']','^','_','`','{','|','}','~',};
    
    std::string fixUp(std::string sentence);
    
    bool loadValidWords(std::string);
    bool loadMisspelledWords(std::string);
    void setBeginMarker(char);
    void setEndMarker(char);
    char getBeginMarker();
    char getEndMarker();
    
    void checkData();
    
private:
    char begin_mark = '~';
    char end_mark = '~';
};

#endif /* SPELLCHECKER_H_ */
