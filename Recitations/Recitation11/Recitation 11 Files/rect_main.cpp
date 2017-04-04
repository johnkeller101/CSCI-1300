#include <iostream>
#include "rect.cpp"
using namespace std;


int main()
{
	Rect rectarray[3] = {{-1.5 , 2, 5, 4, "Red"} , {}, {3,4, "Green"}};
	RectVector rv(rectarray, 3);
	cout << "The color of the element at index 0 is " << \
	rv.getRectByIndex(0).getColor();
	cout<< "The point (0,0) was found at index " <<rv.findPoint(0,0);
	cout<<"Removing all red-colored rectangles..."
	rv.removeRectByColor("Red");
	cout << "The color of the element at index 0 is " << \
	rv.getRectByIndex(0).getColor();	
}
