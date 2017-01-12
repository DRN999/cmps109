
// Noriaki Nakano
// Conatiner object
// cpp file for the Container object
#include <iostream>
#include "Container.h"

Container::Container()
{
	length = 0.0;
	width = 0.0;
}// End Construcor 1
		
Container::Container(double e)
{
	length = 0.0;
	width = 0.0;
}// End Constructor 2
		
Container::Container(double l, double w)
{
	length = l;
	width = w;
}// End Constructor 3

Container::~Container()
{
	std::cout << "destructed" << std::endl;
}// End Destructor
	
double Container::area()
{// returns ares of container
	return length * width;
}// End area
		
double Container::ret_length()
{// returns the length of the container
	return length;
}// End ret_length

double Container::ret_width()
{// returns the width of the container
	return width;
}// End ret_width

