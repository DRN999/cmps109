
// Noriaki Nakano
// Container.h
// .h file of Container object
#ifndef CONTAINER
#define CONTAINER

class Container
{ // this class contains the information of a rectangular shape and also return the area of such shape
	
	public: 
		Container(); // constructors
		Container(double e); // incorrect constructor
		Container(double l, double w); // parametric constructor
		~Container(); // destructor
		double area(); // returns area of container
		double ret_length(); // returns the private variable length
		double ret_width(); // returns the private variable width
	
	private: 
		double length; // length of rectangular container
		double width; // width of rectangular container
	
}; // end Class Container

#endif

