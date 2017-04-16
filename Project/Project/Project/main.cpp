//
//  John Keller
//  CSCI 1300 Project
//
//  Jason Zietz, Section 101
//
//  Created by John on 4/4/17.
//  Copyright © 2017 John. All rights reserved.
//

#include "makeGraph.h"

#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main() {
    cout << "Welcome to John's Graphing Calculator!" << endl;
    cout << "     Please take a moment to note some of the calculator's limitations:" << endl;
    cout << "     - only supports linear functions" << endl;
    cout << "     - scatter plot only supports whole numbers, no decimals" << endl << endl;

    
    
    cout << "Please enter a linear (or 'random' for a randomly generated equation): " << endl;
    string test;
    cin >> test;
    
    if(test=="random"){
        int x_rand = rand() % 10 - 1;
        int b_rand = rand() % 10 - 1;
        string equ = "y=";
        equ += to_string(x_rand-5);
        equ += "x+";
        equ += to_string(b_rand-5);
        cout << endl << "Randomly generated: " << equ << endl;
        test = equ;
    }
    
    cout << endl << "Would you like to save this graph to log.txt? (y/n)" << endl;
    string save_question;
    cin >> save_question;
    
    
    string log = "";
    if(save_question == "y" || save_question == "yes"){
        log = "log.txt";
    }
    makeGraph graph(test,log);
    
    cout << endl << graph.makeLinear(test) << endl;
    
    
    cout << endl << "Would you like to import and view the graph of sin.csv? (y/n)" << endl;
    string q2;
    cin >> q2;
    
    if(save_question == "y" || save_question == "yes"){
        makeGraph g("sin.csv");
        cout << g.makeScatter("sin.csv") << endl;
    }
}
