//
//  rect.cpp
//  Recitation11
//
//  Created by John Keller on 4/4/17.
//  Copyright © 2017 John Keller. All rights reserved.
//

#include "rect.h"

/* Functions for Rect 
---------------------
*/

Rect::Rect() {
    x = 0;
    y = 0;
    width = 10;
    height = 10;
    color = "Blue";
}

Rect::Rect(float newX, float newY, float newWidth, float newHeight, string newColor) {
    x = newX;
    y = newY;
    width = newWidth;
    height = newHeight;
    color = newColor;
}

Rect::Rect(float newWidth, float newHeight, string newColor) {
    x = 0;
    y = 0;
    width = newWidth;
    height = newHeight;
    color = newColor;
}

float Rect::getX() {
	return x;
}

float Rect::getY() {
	return y;
}

float Rect::getWidth() {
	return width;
}

float Rect::getHeight() {
	return height;
}

string Rect::getColor() {
	return color;
}

void Rect::setX(float newX) {
	x = newX;
}

void Rect::setY(float newY) {
	y = newY;
}

void Rect::setWidth(float newWidth) {
	width = newWidth;
}

void Rect::setHeight(float newHeight) {
	height = newHeight;
}

void Rect::setColor(string newColor) {
	color = newColor;
}

float Rect::getArea() {
    return width * height;
}

bool Rect::pointInRect(float pointX, float pointY) {
    
    // Test for the x coordinate
    if(x < pointX && x+width > pointX){
        // Test for the y coordinate
        if(y < pointY && y+height > pointY){
            return true;
        }
    }
    return false;
}


/* RectVector Functions
 * --------------------
 */


RectVector::RectVector(Rect array[], int array_size) {
    for(int i=0; i<array_size; i++){
        vect[i] = array[i];
    }
}

void RectVector::pushRect(Rect r) {
	vect.push_back(r);
}

void RectVector::removeRectByIndex(int index) {
	vect.erase(vect.begin()+index);
}

Rect RectVector::getRectByIndex(int index) {
	return vect[index];
}

int RectVector::findPoint(float pointX, float pointY) {
    for(int i=0; i<vect.size(); i++){
        Rect temp = vect[i];
        if(temp.getX() < pointX && temp.getX()+temp.getWidth() > pointX){
            // Test for the y coordinate
            if(temp.getY() < pointY && temp.getY()+temp.getHeight() > pointY){
                return i;
            }
        }
    }
    return -1;
    
}

void RectVector::removeRectByColor(string removeColor) {
    for(int i=0; i<vect.size(); i++){
        Rect temp = vect[i];
        if(temp.getColor() == removeColor){
            removeRectByIndex(i);
        }
    }
}
