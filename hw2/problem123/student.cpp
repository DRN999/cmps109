#include <iostream>
#include "student.h"

student::student()
{// default constructor
	class_id = 0;
	student_id = 0;
}// End constructor

student::student(int c_id, int s_id)
{// constructor with input 
	class_id = c_id;
	student_id = s_id;
}// End constructor(int, int) 

student::~student()
{// destructor 
	
}// End destructor 

int student::get_class_id()
{// returns the class number in institute
	return class_id;
}// End ret_class_id();

int student::get_student_id()
{// returns the student number in institute
	return student_id;
}// End ret_student_id 

void student::set_class(int id)
{// sets class_id to the input in
	class_id = id;
}// End set_class_id 

void student::set_student_id(int id)
{// sets student_id with input int
	student_id = id;
}// End set_student_id 

void student::set_seat_id(int id)
{
	seat_id = id;
}

