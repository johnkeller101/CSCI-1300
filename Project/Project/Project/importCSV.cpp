//
//  John Keller
//  CSCI 1300 Project
//
//  Jason Zietz, Section 101
//
//  Created by John on 4/7/17.
//  Copyright © 2017 John. All rights reserved.
//

#include "importCSV.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

importCSV::importCSV(string fname){
    filename = fname;
    openCSV();
    
}

importCSV::~importCSV(){
    // destructor
}

std::vector<std::vector<float>> importCSV::getVector(){
    return graphData;
}

bool importCSV::openCSV(){
    // opening CSV in x,y form
    ifstream file;
    file.open(filename.c_str());
    if(file.is_open()) {
        string line;
        while(getline(file,line)){
            string result;
            istringstream ss(line);
            vector<string> temp;
//            cout<<line;
            if(strstr(line.c_str(),csvDelim.c_str())){
                float x = stof(line.substr(0,line.find(',')));
                float y = stof(line.substr(line.find(',')+1,line.length()));
                
                vector<float> point;
                point.push_back(x);
                point.push_back(y);
                
                graphData.push_back(point);
            }
        }
        file.close();
        return true;
    } else {
        return false;
    }
    
    return false;
}
