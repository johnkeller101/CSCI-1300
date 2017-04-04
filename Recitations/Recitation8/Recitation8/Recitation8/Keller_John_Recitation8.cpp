//
//  main.cpp
//  Recitation8
//
//  Created by John on 3/6/17.
//  Copyright © 2017 John. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

float * readScores(string inputFile, float scores[]);
void writeGrade(string outputFile, float scores[]);
char processGrades(int grade);

int main(){
    float arr[7];
    float * t = readScores("Scores.txt", arr);
    
    for(int i = 0; i < 7; i++) {
        cout << t[i] << endl;
    }
    
}

float* readScores(string inputFile, float scores[]) {
    ifstream myfile;
    myfile.open(inputFile.c_str());
    
    if(myfile.is_open()) {
        // File opening sucessful
        
        string line;
        int i = 0;
        while ( getline(myfile, line) ) {
            scores[i] = stof(line);
            i++;
        }
        
    } else {
        cout << "Error reading data from " << inputFile << endl;
    }
    
    myfile.close();
    
    return scores;
}

void writeGrade(string outputFile, float scores[]){
    int size = (sizeof(scores)/sizeof(scores[0]));
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += scores[i];
    }
    
    ofstream write;
    write.open(outputFile.c_str());
    
    if (write) {
        write << sum/size << ", " << processGrades(sum/size);
    }
    
    write.close();
    
}

char processGrades(int grade) {
    char letter = 'A';

    if (grade > 90) {
        letter = 'A';
    } else if (grade > 80) {
        letter = 'B';
    } else if (grade > 70) {
        letter = 'C';
    } else if (grade > 60) {
        letter = 'D';
    } else if (grade < 50) {
        letter = 'F';
    }
    
    return letter;
}
