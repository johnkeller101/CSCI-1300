//
//  main.cpp
//  Recitation 3
//
//  Created by John Keller on 1/30/17.
//  Copyright © 2017 John Keller. All rights reserved.
//

#include <iostream>

using namespace std;

void printFourteenerInfo(int height) {
    if (height == 14060) {
        cout << "14060 ft is the height of Mount Bierstadt. It is near Idaho Springs."<< endl;
    } else if (height == 14036) {
        cout << "14036 ft is the height of Mount Sherman. You can drive a long way to the trailhead if you’re feeling lazy."<< endl;
    } else if (height == 14269) {
        cout << "14269 ft is the height of Mount Antero. Apparently the hike is safe but it is one of the easier (i.e., boring) fourteeners."<< endl;
    } else {
        cout << "Height entered does not match a fourteener in this computer program. Please enter a correct height." << endl;
    }
}

int main() {
    int input = 0;
    
    cout << "Enter the height of a fourteener: ";
    cin >> input;
    
    printFourteenerInfo(input);
    
    return 0;

}
