// Noriaki Nakano
// Conatiner object
// cpp file for the Container object

#include "Container.h"

Container::Container()
{
	length = 0.0;
	width = 0.0;
}
		
Container::Container(double e)
{
	length = 0.0;
	width = 0.0;
}
		
Container::Container(double l, double w)
{
	length = l;
	width = w;
}
	
double Container::area()
{
	return length * width;
}
		
double Container::ret_length()
{
	return length;
}

double Container::ret_width()
{
	return width;
}