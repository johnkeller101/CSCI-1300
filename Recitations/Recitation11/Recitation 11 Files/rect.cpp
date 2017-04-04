#include "rect.h"

/* Functions for Rect 
---------------------
*/

Rect::Rect()
{
	/*TODO- Write code for constructor here.
	Set the values of the variables as
	x - 0
	y - 0
	width - 10
	height - 10
	color - Blue
	*/

}

Rect::Rect(float newX, float newY, float newWidth, \
	float newHeight, string newColor)
{
 	/*TODO- Write code for constructor here.
	Set the values of the variables as provided in the parameters
	*/
}

Rect::Rect(float newWidth, float newHeight, string newColor)
{
	/*TODO- Write code for constructor here.
	Set the values of the variables as provided in the parameters
	Set x=0 and y =0.
	*/
}
	
float Rect::getX()
{
	return x;
}

float Rect::getY()
{
	return y;
}

float Rect::getWidth()
{
	return width;
}

float Rect::getHeight()
{
	return height;
}

string Rect::getColor()
{
	return color;
}

void Rect::setX(float newX)
{
	x = newX;
}

void Rect::setY(float newY)
{
	y = newY;
}

void Rect::setWidth(float newWidth)
{	
	width = newWidth;
}

void Rect::setHeight(float newHeight)
{
	height = newHeight;
}

void Rect::setColor(string newColor)
{
	color = newColor;
}

float Rect::getArea()
{
	//TODO- Implement this function. Area = width times height.
}

bool Rect::pointInRect(float pointX, float pointY)
{
	/* TODO- Find whether a point is in a rectangle or not.
	A point lies within a rectangle if the x coordinate of the point
	is within [x, x+width] and the y coordinate of the point is within
	[y, y+height]
	*/
}


/* RectVector Functions
 * --------------------
 */


RectVector::RectVector(Rect array[], int array_size)
{
	/*TODO- Implement this function to initialize the vect variable of the 
	 * class with the element of the array parameter
	 */
}

void RectVector::pushRect(Rect r)
{
	vect.push_back(r);
}

void RectVector::removeRectByIndex(int index)
{
	vect.erase(vect.begin()+index);
}

Rect RectVector::getRectByIndex(int index)
{
	return vect[index];
}

int RectVector::findPoint(float pointX, float pointY)
{
	/*TODO- Complete thus function to return the index of the first 
	 * rectangle  that contains the point given by the coordinates in 
	 * the parameters. It returns -1, if the point was not found.
	 */
}

void RectVector::removeRectByColor(string removeColor)
{
	/*TODO- Complete this function to remove all rectangles in the 
	 * vector variable that have the color specified by 'removeColor'
	 */
}
