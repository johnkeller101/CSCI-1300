//
//  main.cpp
//  Recitation7
//
//  Created by John Keller on 2/27/17.
//  Copyright © 2017 John Keller. All rights reserved.
//

#include <iostream>

using namespace std;

int main(){
    int length = 20;
    double myDoubles[length];
    // Question 1
    for(int i = 0; i < length; i++){
        myDoubles[i] = i;
    }
    // Question 2
    for(int i = 0; i < length; i++){
        cout << myDoubles[i] << endl;
    }
    // Question 3
    double average;
    for(int i = 0; i < length; i++){
        average += myDoubles[i];
    }
    average = average/length;
    cout << "The average value of myDoubles is: " << average << endl;
}
