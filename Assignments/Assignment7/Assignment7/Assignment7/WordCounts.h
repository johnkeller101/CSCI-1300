//
//  WordCounts.hpp
//  Assignment7
//
//  Created by John on 3/23/17.
//  Copyright © 2017 John. All rights reserved.
//

#ifndef WORDCOUNTS_H
#define WORDCOUNTS_H

class WordCounts{
private:
    
    std::vector<std::string> words;
    
    std::vector<char> punct = {'!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/',':',';','<','=','>','?','@','[',']','^','_','`','{','|','}','~',};
    
public:
    WordCounts();
    char seperatorChar = ':';
    void countWords(std::string);
    int getCount(std::string);
    void resetCounts();
    int mostCommon(std::string[],int[],int);
    void showAll();
};


#endif /* WORDCOUNTS_H */
