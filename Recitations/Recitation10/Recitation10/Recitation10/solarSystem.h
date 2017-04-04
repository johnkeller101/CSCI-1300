//
//  solarSystem.hpp
//  Recitation10
//
//  Created by John Keller on 3/21/17.
//  Copyright © 2017 John Keller. All rights reserved.
//

#ifndef SOLAR_SYSTEM_H
#define SOLAR_SYSTEM_H

#include <string>
#include <iostream>
using namespace std;

class solarSystem{
private:
    int maxNumPlanets = 10;
    string systemName;
    int numPlanets = 0;
    string planetNames[10];
    float planetDiameters[10];
    float planetOrbitDist[10];
    
public:
    solarSystem(string);
    ~solarSystem();
    
    string findLargest();	// return the name of the largest planet
    string getName();		// return the name of the solar system
    float getDiameter();	// return the diameter of the largest orbit
    int getNumPlanets();	// return the number of planets in the system
    bool addPlanet(string, float, float);
};
#endif // SOLAR_SYSTEM_H
