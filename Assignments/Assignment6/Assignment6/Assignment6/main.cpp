//
//  main.cpp
//  Assignment6
//
//  Created by John on 4/4/17.
//  Copyright © 2017 John. All rights reserved.
//

#include "Assignment6.cpp"

int main() {
    string names[8];
    float avg_scores[8];
    string outputName = "SampleOutput.txt";
    
    string inputName = "SampleInput.txt";
    cout << "Count of " << inputName << " is " << CountLines(inputName) << endl;
    cout << "Read scores: " << endl << ReadScores(inputName, names, avg_scores, 8) << endl;
    
    WriteGrades(outputName, names, avg_scores, 8);
}

