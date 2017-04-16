//
//  readWriteData.cpp
//  Project
//
//  Created by John Keller on 4/16/17.
//  Copyright © 2017 John. All rights reserved.
//

#include "readWriteData.h"
#include "importCSV.h"
#include <iostream>
#include <fstream>

using namespace std;

readWriteData::readWriteData(std::string fname){
    readData(fname);
}
readWriteData::readWriteData(std::string data, std::string fname){
    writeData(data, fname);
}

readWriteData::~readWriteData(){
    // deconstructor
}

bool readWriteData::writeData(std::string data,std::string fname){
    
    ofstream myfile (fname.c_str());
    if (myfile.is_open()) {
        myfile << data;
        myfile.close();
        return true;
    }
    else cout << "Unable to open file";
    return false;
}

void readWriteData::readData(std::string fname){
    importCSV import(fname);
    import.openCSV();
    data = import.getVector();
}

std::vector<std::vector<float>> readWriteData::getReadData(){
    return data;
}
