
// Noriaki Nakano
// private works c++

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include "Container.h"

using namespace std;

int main()
{
	
	int n = 15;
	int *ptr = &n;
	
	cout << endl << "Pointer test: " << endl;
	cout << "Address of variable &n: " << &n << endl;
	cout << "Address stored in pointer ptr: " << ptr << endl;
	cout << "Value of n: " << n << endl;
	cout << "Value of *ptr: " << *ptr << endl;
	
	Container c(10.0, 10.0);
	Container c2(10.0, 20.0);
	Container *cptr = &c;
	
	cout << endl << "OOP test1:" << endl;
	cout << "Container length: " << c.ret_length() << endl;
	cout << "Container width: " << c.ret_width() << endl;
	cout << "Container area: " << c.area() << endl;
	
	cout << endl << "OOP test2:" << endl;
	cout << "Container length: " << c2.ret_length() << endl;
	cout << "Container width: " << c2.ret_width() << endl;
	cout << "Container area: " << c2.area() << endl;
	
	cout << endl << "OOP pointer test:" << endl;
	cout << "Container length: " << cptr->ret_length() << endl;
	cout << "Container width: " << cptr->ret_width() << endl;
	cout << "Container area: " << cptr->area() << endl;
	
	cout << endl;
	return 0;
}

