//
//  Name            John Keller
//  Recitation TA   Jason Zietz
//  Assignment #    5
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
