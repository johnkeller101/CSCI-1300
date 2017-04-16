#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


class StringReader{
	private:
    std::vector<std::string> stringList;
	public:
		void readFromFile(string);
		int findFirstStringMatch(string);
		void removeStringbyValue(string);
		string getStringAtIndex(int);
		int getListSize();
};


void StringReader::readFromFile(string filename)
{
	ifstream inputFile(filename.c_str());
	string line;
	while(getline(inputFile, line))
	{
        stringList.push_back(line);
	}
}

int StringReader::findFirstStringMatch(string substring)
{
	int val;
	int length = stringList.size();
	for (int i=0; i < length; i++)
	{
        if(substring == stringList[i]){
            val = i;
            break;
        }
	}
	return val+1;
}

void StringReader::removeStringbyValue(string substring) 
{
	for (int i=0; i < int(stringList.size()); i++)
	{
		//TODO: Add code to delete all matches for the substring.
	}
}

int StringReader::getListSize()
{
	return stringList.size();
}

string StringReader::getStringAtIndex(int ind)
{
	return stringList[ind];
}

int main()
{
	StringReader rdr;
	rdr.readFromFile("names.txt");
	cout<< "The names in the vector are: \n";
	for (int i=0; i<rdr.getListSize(); i++) {
		cout<< rdr.getStringAtIndex(i)<< endl;
	}
	cout<< "Deleting all names containing \'ik\'";
	rdr.removeStringbyValue("ik");
	cout<< "The names in the vector are: \n";
	for (int i=0; i<rdr.getListSize(); i++) {
		cout<< rdr.getStringAtIndex(i)<< endl;
	}
}
