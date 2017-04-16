//
//  readWriteData.hpp
//  Project
//
//  Created by John Keller on 4/16/17.
//  Copyright © 2017 John. All rights reserved.
//

#ifndef readWriteData_h
#define readWriteData_h
#include <string>
#include <vector>

class readWriteData {
public:
    // Constructors
    readWriteData(std::string fname);
    readWriteData(std::string data, std::string fname);
    
    // Destructors
    ~readWriteData();
    
    bool writeData(std::string data,std::string fname);
    void readData(std::string fname);
    
    std::vector<std::vector<float>> getReadData();
private:
    std::string filename;
    std::vector<std::vector<float>> data;
};

#endif /* readWriteData_h */
