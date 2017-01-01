#ifndef CONTAINER
#define CONTAINER

class Container
{
	
	public:
		Container();
		Container(double e);
		Container(double l, double w);
		~Container(){};
		double area();
		double ret_length();
		double ret_width();
	
	private:
		double length;
		double width;
	
};

#endif

