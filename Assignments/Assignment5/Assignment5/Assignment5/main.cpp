//
//  Name            John Keller
//  Recitation TA   Jason Zietz
//  Assignment #    5
//

#include "Assignment5.cpp"

int main() {
    float scores[] = {82.3, 67.7, 76.3, 71.6, 75.1};
	int scores_size = 5;
	
	cout << getMedian(scores, scores_size) << endl;
	
	char grades[] = {'C','D','B','A','C'};
	int grades_size = 5;
	
	cout << countGrade(grades, 'A', grades_size) << endl;
}
