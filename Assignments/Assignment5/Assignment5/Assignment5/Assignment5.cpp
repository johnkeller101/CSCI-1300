//
//  Name            John Keller
//  Recitation TA   Jason Zietz
//  Assignment #    5
//

#include <iostream>
using namespace std;

void fillArray(int data[], int size, int value);
void calculateGrades(float scores[], char grades[], int size);
float getAverageScore(float scores[], int size);
float getMinScore(float scores[], int size);
float getMaxScore(float scores[], int size);
void sortScores(float scores[], int size);
float getMedian(float scores[], int size);
int countGrade(char grades[], char grade, int size);

/*
 // Part 1 – Function call to initialize a given array with the given value.
 */

void fillArray(int data[], int size, int value){
	for(int i = 0; i < size; i++){
		data[i] = value;
	}
}

/*
// Part 2 – Calculate grades of students
*/

void calculateGrades(float scores[], char grades[], int size){
    /*
     A >= 90
     B >= 80
     C >= 70
     D >= 60
     F < 60
     */
    
    for(int i = 0; i < size; i++){
        float score = scores[i];
        if (score >= 90) {
            grades[i] = 'A';
        } else if(score >= 80) {
            grades[i] = 'B';
        } else if(score >= 70) {
            grades[i] = 'C';
        } else if(score >= 60) {
            grades[i] = 'D';
        } else {
            grades[i] = 'F';
        }
    }
}

/*
 // Part 3 – Calculate the average score of class
 */

float getAverageScore(float scores[], int size){
    float total = 0;
    for(int i = 0; i < size; i++){
        total += scores[i];
    }
    return total/size;
}

/*
 // Part 4 – Find the minimum score
 */

float getMinScore(float scores[], int size){
	float min = 10000000;
	for(int i = 0; i < size; i++){
		if(scores[i] < min)
			min = scores[i];
	}
	return min;
}

/*
 // Part 5 – Find the maximum score
 */

float getMaxScore(float scores[], int size){
	float max = 0;
	for(int i = 0; i < size; i++){
		if(scores[i] > max)
			max = scores[i];
	}
	return max;
}

/*
 // Part 6 – Sort the Scores Array
 */

void sortScores(float scores[], int size){

	for(int i = 0; i < size-1; i++) {
		for (int j = 0; j < size-1; j++) {
			if (scores[j] > scores[j+1]) {
				float value = scores[j];
				scores[j] = scores[j+1];
				scores[j+1] = value;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		cout << scores[i] << " ";
	}
	cout << endl;
}

/*
 // Part 7 – Find the median score.
 */

float getMedian(float scores[], int size){
	float scoresSorted[size];
	for(int i = 0; i < size; i++){
		scoresSorted[i] = scores[i];
	}
	
	
	for(int i = size - 1; i > 0; --i) {
		for (int j = 0; j < size-1; j++) {
			if (scoresSorted[j] > scoresSorted[j+1]) {
				float value = scoresSorted[j];
				scoresSorted[j] = scoresSorted[j+1];
				scoresSorted[j+1] = value;
			}
		}
	}
	
	if (size%2)
		return scoresSorted[size/2];
	else
		return (scoresSorted[size / 2] + scoresSorted[size/2 - 1]) / 2.0;
}

/*
 // Part 8 – Count the number of students with a particular grade
 */

int countGrade(char grades[], char grade, int size){
    int count = 0;
    for(int i = 0; i < size; i++){
		if(grades[i] == grade) {
            count++;
		}
    }
    return count;
}
