#include <iostream>
#include "classroom.h"
#include "institute.h"

classroom::classroom()
{// default constructor 
	class_number = 0;
	student_number = 0;
}// End constructor 

classroom::classroom(int c_n, institute* inst)
{// constructor with param input 
	class_number = c_n;
	institution = inst;
}// End constructor 

classroom::~classroom()
{// destuctor - frees the student array 
	
}// End destuctor 

int classroom::get_student_number()
{// returns the number of students 
	return student_number;
}// End ret_student_number 

int classroom::get_class_number()
{// returns the class number in institution 
	return class_number;
}// End ret_class_number 

void classroom::set_student_number(int s_num)
{// sets the number of students 
	student_number = s_num;
}// End set_student_number

void classroom::set_class_number(int c_num)
{// sets the class_numer 
	class_number = c_num;
}// End set_class_number 

int classroom::check_student_state(student* s)
{   // returns 0 for student not inside institution, 
	// returns 1 for seat resereved for student, returns 2 for student using the seat 
	if(s == nullptr)
		return 0;
	else if(s->get_class_id() != this->class_number)
		return 1;
	return 2;
}// End check_student_state 

void classroom::check_class_size()
{ // check the student number in this particular classroom
	PointerList<student>* s = this->institution->get_students();
	this->student_number = 0;
	if(s->get_pointer()->get_class_id() == this->class_number)
		this->student_number++;
	
	while(!s->get_end())
	{
		s = s->get_next();
		if(s->get_pointer()->get_class_id() == this->class_number)
			this->student_number++;
	}
}// End check_class_zise 
