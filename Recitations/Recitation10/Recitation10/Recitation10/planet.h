//
//  planet.hpp
//  Recitation10
//
//  Created by John Keller on 3/20/17.
//  Copyright © 2017 John Keller. All rights reserved.
//

#ifndef PLANET_H
#define PLANET_H

#include <iostream>
using namespace std;

class planet{
private:
    string name;
    float distance;
    float radius;
    
public:
    planet(string,float,float);
    ~planet();
    
    string getName();
    void setName(string);
    
    void setRadius(float);
    float getDiameter();
    
    void setDist(float);
    float getDist();
    float getOrbitPeriod();
};
#endif /* PLANET_H */
