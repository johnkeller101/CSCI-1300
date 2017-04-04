//
//  Name            John Keller
//  Recitation TA   Jason Zietz
//  Assignment #    5
//

#include <iostream>
#include <fstream> // Include this to read and write data
#include <sstream> // Include to process commas
#include <string>
using namespace std;

// Define the functions prior to calling them
int CountLines(string filename);
int ReadScores(string filename, string names[], float avg_scores[], int array_size);
void WriteGrades( string filename, string names[], float avg_scores[], int n_students);
char getLetterGrade(float grade);
void sortByGrade(string names[], float scores[], int length);

/*
 // Part 1. Count the number of lines in a file.
 */

int CountLines(string filename) {
	// Define input filestream and open the desired file
	ifstream file;
	file.open(filename.c_str());

	// Define an index so we can accuratly count the number of lines
	int linecount = 0;

	// Test to make sure the file sucessfully opened, then run our counting code
	if(file.is_open()) {
		// For every line found, add one to the count
		string temp;
		while ( getline(file, temp) ) {
			linecount++;
		}
	} else {
		// The file failed to open, so let's return 0
		return 0;
	}
	return linecount;
}

/*
// Part 2. Parse a file and store the values in a variable.
*/

int ReadScores(string filename, string names[], float avg_scores[], int array_size) {
	// Open the file
	ifstream file;
	file.open(filename.c_str());
	int linecount = 0;

	if(file.is_open()) {
		// Iterate through lines
		string line;
		while(getline(file,line)){
			// Define the necessary variables for each line
			string name = line.substr(0,line.find(','));
			string result;
			float sum = 0;
			int index = 0;

			// Begin parsing the line by commas
			istringstream ss(line);
			while(getline(ss, result, ',')) {
				// Test to make sure we omit the name in first column
				if(index > 0) {
					// Add the number to the sum, after converting it to a float
					sum += stof(result.c_str());
				}
				index++;
			}
			// Set values in arrays
			avg_scores[linecount] = sum/(index-1);
			names[linecount] = name;
			// Add one to line count
			linecount++;
		}

	} else {
		// Show error message
		cout << "Error loading " << filename << endl;
	}

	return linecount;
}

/*
 // Part 3. Writing back to a file.
 */

void WriteGrades( string filename, string names[], float avg_scores[], int n_students) {

	ofstream file;
	file.open(filename.c_str());

	if(file.is_open()) {
		sortByGrade(names, avg_scores, n_students); // Runs sort function
		for(int i = 0; i<n_students; i++){
			string output = names[i] + ", " + to_string(avg_scores[i]) + ", " + getLetterGrade(avg_scores[i]) + "\n";
			cout << output;
			file << output;
		}

		file.close();
	} else {
		cout << "Failed to open file." << endl;
	}



}

char getLetterGrade(float grade) {

	// Function to get letters from grade values

	if(grade > 90) {
		return 'A';
	} else if (grade > 80) {
		return 'B';
	} else if (grade > 70) {
		return 'C';
	} else if (grade > 60) {
		return 'D';
	} else {
		return 'F';
	}
}

void sortByGrade(string names[], float scores[], int length) {

	// Sort the grades alphabetically, set values to each array accordingly

	bool isSorting = true;
	while(isSorting) {
		for(int i = 0; i < length; i++){
			if(names[i] > names[i+1]){
				string name = names[i];
				names[i]=names[i+1];
				names[i+1] = name;

				float score = scores[i];
				scores[i] = scores[i+1];
				scores[i+1] = score;

				isSorting = false;
			}
		}
	}
}
