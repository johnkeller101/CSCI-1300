//
//  John Keller
//  CSCI 1300 Project
//
//  Jason Zietz, Section 101
//
//  Created by John on 4/7/17.
//  Copyright © 2017 John. All rights reserved.
//

#ifndef makeGraph_h
#define makeGraph_h

#include <string>
#include <vector>

class makeGraph {
public:
    // Constructors
    // Use the pre-defined window values
    makeGraph(std::string func,std::string fname);
    makeGraph(std::string fname);
    // User defines the window values
    makeGraph(std::string func, float xmn, float xmx, float ymn, float ymx,std::string fname);
    makeGraph(std::vector<std::vector<float>> data, float xmn, float xmx, float ymn, float ymx,std::string fname);
    
    // Destructors
    ~makeGraph();
    
    // Return the string containing thr graph
    std::string outputGraph();
    // Save the graph to a file
    // note: this function needs to first open the file specified and make sure there is no data. If there is data, return false so the user knows something went wrong
    bool saveGraphToFile(std::string filename);
    
    // Various functions
    void setGraphFrequencies(float xfreq, float yfreq);
    void setChar(char pointChar);

    std::string makeLinear(std::string func);
    std::string makeScatter(std::string fname);
private:
    // Variables
    std::vector<std::vector<float>> graphData;
    std::string function;
    float xfreq = 1;
    float yfreq = 1;
    float xmin = -10;
    float xmax = 10;
    float ymin = -10;
    float ymax = 10;
    bool tangentLine = true;
    
    std::string displayGraph;
    std::string log_fname;
    
    // This function will follow the function and for each x value in the specified range and retrieve the y value.
    void generateDataForFunction();
    
};

#endif /* makeGraph_h */
