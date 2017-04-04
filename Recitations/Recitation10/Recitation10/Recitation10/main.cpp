//
//  main.cpp
//  Recitation10
//
//  Created by John Keller on 3/20/17.
//  Copyright © 2017 John Keller. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

#include "battleShip.h"
#include "planet.h"
#include "solarSystem.h"

using namespace std;

int main() {
    //TODO: Declare 3 instances of the battleship class: Destroyer Carrier Cruiser
    battleShip ship_one("Destroyer");
    battleShip ship_two("Carrier");
    battleShip ship_three("Cruiser");
    
    //TOD0: Give the ships a size: Destroyer-3 Carrier-5 Cruiser-2
    // you will need to call the appropriate methods
    ship_one.setSize(3);
    ship_two.setSize(5);
    ship_three.setSize(2);
    
    // Once you have this running for one, expand this while loop to include the other
    // two instances. Have the while loop end when all three ships have been sunk
    while(ship_one.isSunk() == false){
        ship_one.recordHit();
    }
    cout << "Ship one sunk" << endl;
    
    while(ship_two.isSunk() == false){
        ship_two.recordHit();
    }
    cout << "Ship two sunk" << endl;
    
    while(ship_three.isSunk() == false){
        ship_three.recordHit();
    }
    cout << "Ship three sunk" << endl;
    
    
    /// Part 2: Planets
    
    //TODO: Declare 4 instances of the planet class, using the following table for reference
    
    string names[4] = {"Mercury","Venus","Earth","Mars"};
    float radius[4] = {2440,6052,6371,3390};
    float orbit[4] = {0.387,0.723,1.000,1.524};
    
    std::vector<planet> p;
    for(int i = 0; i < 4; i++) {\
        planet pl(names[i], radius[i], orbit[i]);
        p.push_back(pl);
    }
    
    /*  NAME	RADIUS (km)		ORBIT RADIUS (AU)
     Mercury	2440     		0.387
     Venus     	6052       		0.723
     Earth     	6371       		1.000
     Mars      	3390     		1.524
     */
    
    // Use the following print statements to test your planet class code
    for(int i = 0; i < 4; i++)
    {
        cout << "The orbit of " << p[i].getName();
        cout << " takes " << p[i].getOrbitPeriod() << " years." << endl;
        cout << "The diameter of " << p[i].getName();
        cout << " is " << p[i].getDiameter() << " km." << endl;
        cout << p[i].getName() << " is " << p[i].getDist() << " AU from the Sun." << endl;
        cout << " --- " << endl;
    }
    
    
    /// Part 3: Solar System
    
     solarSystem sol("Sol");
     
     cout << "System name: " << sol.getName() << endl;
     
     // TODO: Add the four planets from part 2 to the solar system object
    
    //string newName, float dia, float orb
    for(int i=0; i<4; i++){
        sol.addPlanet(p[i].getName(), p[i].getDiameter(), p[i].getDist());
    }
    
     // Use the following print statements to test your solar system class code
     cout << sol.getName() << " has " << sol.getNumPlanets() << " planets." << endl;
     cout << "The biggest planet is " << sol.findLargest() << "." << endl;
     cout << "The diameter of " << sol.getName() << " is " << sol.getDiameter() << " AU." << endl;
    
    
}
