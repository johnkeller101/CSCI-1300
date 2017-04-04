//
//  battleShip.hpp
//  Recitation10
//
//  Created by John Keller on 3/20/17.
//  Copyright © 2017 John Keller. All rights reserved.
//

#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <iostream>
using namespace std;

class battleShip{
public:
    battleShip(string);
    ~battleShip();
    
    void setShipName(string);
    string getShipName();
    
    void setSize(int);
    int getSize();
    
    void recordHit();
    bool isSunk();
    
private:
    string name;
    int size;
    int hits;
};
#endif // BATTLESHIP_H
