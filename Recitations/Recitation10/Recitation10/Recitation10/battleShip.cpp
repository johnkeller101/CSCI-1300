//
//  battleShip.cpp
//  Recitation10
//
//  Created by John Keller on 3/20/17.
//  Copyright © 2017 John Keller. All rights reserved.
//

#include "battleShip.h"
#include <iostream>
#include <string>

using namespace std;

battleShip::battleShip(string newname){
    name = newname;
}
battleShip::~battleShip(){
    //dtor
}


void battleShip::setShipName(string newname){
    name = newname;
}

string battleShip::getShipName(){
    return name;
}

void battleShip::setSize(int newsize){
    size = newsize;
}
int battleShip::getSize(){
    return size;
}

void battleShip::recordHit(){
    hits++;
}
bool battleShip::isSunk(){
    if(hits == size) {
        return true;
    } else {
        return false;
    }
}
