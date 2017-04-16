//
//  John Keller
//  CSCI 1300 Project
//
//  Jason Zietz, Section 101
//
//  Created by John on 4/7/17.
//  Copyright © 2017 John. All rights reserved.
//

#include "makeGraph.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include "readWriteData.h"
#include "importCSV.h"
using namespace std;

makeGraph::makeGraph(std::string func,string fname){
    log_fname = fname;
//    makeLinear(func);
}
makeGraph::makeGraph(string fname){
//    importCSV test(fname);
//    data = test.getVector();
//    makeScatter(fname);
    
}
makeGraph::makeGraph(std::string func, float xmn, float xmx, float ymn, float ymx,string fname){
    xmin=xmn;
    xmax=xmx;
    ymin=ymn;
    ymax=ymx;
//    makeLinear(func);
    log_fname = fname;
}
makeGraph::makeGraph(std::vector<std::vector<float>> data, float xmn, float xmx, float ymn, float ymx,string fname){
    xmin=xmn;
    xmax=xmx;
    ymin=ymn;
    ymax=ymx;
    graphData = data;
//    makeScatter(fname);
}

makeGraph::~makeGraph(){
    // destructor
}


std::string makeGraph::makeScatter(std::string fname){
    string graph = "";
    
    readWriteData read(fname);
    std::vector<std::vector<float>> scatter_data = read.getReadData();
    
    // for each line in graph
    for(int y=ymax;y>ymin;y--){
        string line = "";
        vector<float> x_values;
        
        // for each entry in the csv file
        for(int l=0;l<scatter_data.size();l++){
            vector<float> vect = scatter_data[l];
            float x_pt = vect[0];
            float y_pt = vect[1];
            if(y == y_pt){
                x_values.push_back(x_pt);
            }
        }
        
        std::ostringstream s;
        s << y;
        if(s.str().length() == 1){
            line+="  ";
        } else if(s.str().length() == 2){
            line+=" ";
        }else {
            line+="";
        }
        line += s.str();
        line += " |";
        
        for(int x=xmin;x<xmax;x++){
            bool hasX = false;
            for(int n=0;n<x_values.size();n++){
                if(x_values[n] == x){
                    hasX = true;
                }
            }
            
            if(hasX == true){
                std::ostringstream s;
                s << x;
                line += "•";
            } else {
                line += " ";
            }
            
        }
        
        line += "\n";
        graph += line;
    }
    // generate bottom line
    graph+= "    |";
    for(int i = xmin; i<=xmax; i++){
        graph+="_";
    }
    graph+="\n";
    // generate bottom labels
    graph+= "    ";
    for(int i = xmin; i<=xmax; i++){
        
        if(i==xmin){
            std::ostringstream s;
            s << xmin;
            string val = s.str();
            
            graph+=val;
            i+=val.length();
        } else if(i==xmax){
            std::ostringstream s;
            s << xmax;
            string val = s.str();
            
            graph+=val;
            i+=val.length();
        }else if(i==0){
            graph+="0";
        } else {
            graph+=" ";
        }
    }

    if (fname.length() > 0) {
        class readWriteData write(fname);
        write.writeData(graph, fname);
    }
    displayGraph = graph;
    return graph;
}

string makeGraph::makeLinear(string func){
    string graph = "";
    int inset_amount = 2;
    
    float x, y;
    
    //determine coefficent (m)
    float m = stof(func.substr(func.find("=")+1,func.find("x")));
    
    //determine constant
    string end = func.substr(func.find("x"),func.length());
    float b = 0;
    if(end[0]=='+'){
        b = stof(func.substr(func.find("+"),func.length()));
    } else if (end[0]=='-'){
        b = stof(func.substr(func.find("-"),func.length()));
    }
    
    // controls alternating label number
    bool show_label = true;
    // for each line in the function
    for (y = ymax; y >= ymin; y--) {
        // now that we know our y value, let's determine our x value...
        
        x = (y - b) / m;
        // now, we know both our x and y value, so let's generate a graph
        
        // let's add the labels on the left side
        string line = "";
        if(show_label){
            // this osstringstream is a fix so the graph doesn't print 10.0000
            std::ostringstream s;
            s << y;
            // fix for both positive and negative numbers
            if(s.str().length() == 1){
                line+=" ";
            }
            line += s.str();
            if(s.str().length() < 3){
                line+=" ";
            }
        } else {
            for(int i=0;i<=inset_amount;i++){
                line+=" ";
            }
        }
        show_label = !show_label;
        line += "|";
        
        // now let's fill in all the
        for(int i=xmin;i<xmax;i++){
            if(i==x){
                if(m>0 && tangentLine){
                    line += '/';
                } else if(m<0 && tangentLine){
                    line += '\\';
                }else if(m==0 && tangentLine){
                    line += '|';
                }else {
                    line += '-';
                }
            } else {
                line += ' ';
            }
        }
        line += "\n";
        graph+= line;
    }
    // generate bottom line
    graph+= "   |";
    for(int i = xmin; i<=xmax; i++){
        graph+="_";
    }
    graph+="\n";
    // generate bottom labels
    graph+= "    ";
    for(int i = xmin; i<=xmax; i++){
        
        if(i==xmin){
            std::ostringstream s;
            s << xmin;
            string val = s.str();
            
            graph+=val;
            i+=val.length();
        } else if(i==xmax){
            std::ostringstream s;
            s << xmax;
            string val = s.str();
            
            graph+=val;
            i+=val.length();
        }else if(i==0){
            graph+="0";
        } else {
            graph+=" ";
        }
    }
    if (log_fname.length() > 3) {
        readWriteData write(log_fname);
        write.writeData(graph, log_fname);
    }
    return graph;
}

string removeSpaces(string input){
    for(int i=0;i<input.length();i++){
        if(input[i]==' '){
            input.erase(i,i+1);
        }
    }
    return input;
}
