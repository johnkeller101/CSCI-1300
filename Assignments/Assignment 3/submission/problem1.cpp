//
//  Name            John Keller
//  Recitation TA   Jason Zietz
//  Assignment #    3
//  Problem #       1
//

#include <iostream>

using namespace std;

void madLibs(void);

int main() {
    // Declare the variables
    bool inSession = true;
    string play = "";
    
    // Loop the function so when the user is done playing, it returns them to the beginning
    while (inSession) {
        // Retrieve user input
        cout << "Do you want to play a game? (y) or (n)";
        cin >> play;
        if (play == "y") {
            // User said they wanted to play, so let's run the madLibs() function
            madLibs();
        } else if (play == "n") {
            cout << "good bye" << endl;
            inSession = false; // This boolean is what kicks the user out of the loop, ending the program
        }
    }
}

void madLibs(void) {
    // Declare our story string, including the placeholders
    string story = "In the book War of the <PLURAL NOUN>, the main character is an anonymous <OCCUPATION> who records the arrival of the <ANIMAL>s in <PLACE> -- Needless to say, havoc reigns as the <ANIMAL>s continue to <VERB> everything in sight, until they are killed by the common <SINGULAR NOUN>.";

    // Declare the titles and items to replace in story (using an array)
    string parts[6][2] = {
        {"a plural noun","<PLURAL NOUN>"},
        {"a singular noun","<SINGULAR NOUN>"},
        {"an occupation","<OCCUPATION>"},
        {"an animal name","<ANIMAL>"},
        {"a place","<PLACE>"},
        {"a verb","<VERB>"}};
    
    // Go through the arrays, retrieving a user input and replacing the placeholder string
    for (auto & part : parts) {
        // Declare our variables
        string value = "";
        string title = part[0];
        string placeholder = part[1];
        
        // Retrieve the user input
        cout << "Enter " << title << ": ";
        cin >> value;
        
        // Let's determine if the placeholder exists within the story, if so, replace it with the user's value
        // And let's put it in a loop, so we can catch repeating placeholders
        while (story.find(placeholder)!=string::npos) {
            story.replace(story.find(placeholder),placeholder.length(),value);
            // Note: .replace(startPosition, length, newString)
            //       .find(string) returns the start index of the placeholder string
            //       .length() does the obvious and returns the length
        }
    }
    
    // Print the final string
    cout << story << endl;
    
    return;
}

