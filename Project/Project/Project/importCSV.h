//
//  John Keller
//  CSCI 1300 Project
//
//  Jason Zietz, Section 101
//
//  Created by John on 4/7/17.
//  Copyright © 2017 John. All rights reserved.
//

#ifndef importCSV_h
#define importCSV_h

#include <string>
#include <vector>

class importCSV {
public:
    // Constructor
    importCSV(std::string filename);
    
    // Desctructor
    ~importCSV();
    
    std::vector<std::vector<float>> getVector();
    float getDataSetCount();
    bool openCSV();
private:
    std::string csvDelim = ",";
    bool sortCSV();
    std::string filename;
    std::vector<std::vector<float>> graphData;
};

#endif /* importCSV_h */
