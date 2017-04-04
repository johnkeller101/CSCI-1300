//
//  solarSystem.cpp
//  Recitation10
//
//  Created by John Keller on 3/21/17.
//  Copyright © 2017 John Keller. All rights reserved.
//

#include "solarSystem.h"
using namespace std;


solarSystem::solarSystem(string newname){
    systemName = newname;
}
solarSystem::~solarSystem(){
    //dtor
}

string solarSystem::findLargest() {
    float largest = 0;
    int largest_i = 0;
    for(int i=0; i<numPlanets; i++){
        if(planetDiameters[i]>largest){
            largest = planetDiameters[i];
            largest_i = i;
        }
    }
    
    return planetNames[largest_i];
}

string solarSystem::getName(){
    return systemName;
}

float solarSystem::getDiameter(){
   // return the diameter of the largest orbit
    
    float largest;
    for(int i=0; i <= numPlanets; i++){
		largest += planetOrbitDist[i];
    }
    
    return largest;
}

int solarSystem::getNumPlanets() {
    // return the number of planets in the system
    return numPlanets;
}

bool solarSystem::addPlanet(string newName, float dia, float orb) {
    if(numPlanets == maxNumPlanets) {
        return false;
    } else {
        numPlanets++;
        planetNames[numPlanets] = newName;
        planetDiameters[numPlanets] = dia;
        planetOrbitDist[numPlanets] = orb;
        
        return true;
    }
}
