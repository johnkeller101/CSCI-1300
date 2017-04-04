//
//  rect.h
//  Recitation11
//
//  Created by John Keller on 4/4/17.
//  Copyright © 2017 John Keller. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

class Rect {
private:
	float x,y;
	float width, height;
	string color;

public:
	Rect();
	Rect(float, float, float, float, string);
	Rect(float, float, string);
    
	//Getter Methods
	float getX();
	float getY();
	float getWidth();
	float getHeight();
	string getColor();
    
	//Setter Methods
	void setX(float);
	void setY(float);
	void setWidth(float);
	void setHeight(float);
	void setColor(string);
    
	//Functionality 
	float getArea(); 
	bool pointInRect(float, float);
};

class RectVector {
private:
    vector<Rect> vect;
public:
	RectVector(Rect [], int);
	Rect getRectByIndex(int);
	void pushRect(Rect);
	void removeRectByIndex(int);
	int findPoint(float, float);
	void removeRectByColor(string);
};
