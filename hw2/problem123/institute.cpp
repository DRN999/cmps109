#include <iostream>
#include "institute.h"

institute::institute()
{	// init default values of students and classrooms in the institution
	// by default: create 256 students and assign them to classroom # 0
	student_number = 1;
	class_number = 1;
	classes = new PointerList<classroom>(new classroom(0, this));
	for(int i = 1; i < 8; i++)
	{
		classes->add_node(new classroom(i, this));
		++class_number;
	}
	students = new PointerList<student>(new student(classes->find_node(rand() % 8)->get_pointer()->get_class_number(), 0));
	for(int i = 1; i < 256; i++)
	{
		students->add_node(new student(classes->find_node(rand() % 8)->get_pointer()->get_class_number(), i));
		++student_number;
	}
}// End Constructor 

institute::institute(int stud)
{
	student_number = 1;
	class_number = 1;
	classes = new PointerList<classroom>(new classroom(0, this));
	for(int i = 1; i < 8; i++)
	{
		classes->add_node(new classroom(i, this));
		++class_number;
	}
	students = new PointerList<student>(new student(classes->find_node(rand() % 8)->get_pointer()->get_class_number(), 0));
	for(int i = 1; i < stud; i++)
	{
		students->add_node(new student(classes->find_node(rand() % 8)->get_pointer()->get_class_number(), i));
		++student_number;
	}
}

institute::institute(int stud, int clas)
{
	student_number = 1;
	class_number = 1;
	classes = new PointerList<classroom>(new classroom(0, this));
	for(int i = 1; i < clas; i++)
	{
		classes->add_node(new classroom(i, this));
		++class_number;
	}
	students = new PointerList<student>(new student(classes->find_node(rand() % clas)->get_pointer()->get_class_number(), 0));
	for(int i = 1; i < stud; i++)
	{
		students->add_node(new student(classes->find_node(rand() % clas)->get_pointer()->get_class_number(), i));
		++student_number;
	}
}


institute::~institute()
{// Destuctor for institute object 
	std::cout << "institute destructed" << std::endl;
	classes->delete_list();
	students->delete_list();
	delete ((classroom*) classes->get_pointer());
	delete ((student*) students->get_pointer());
	delete (classes);
	delete (students);
}// End Destructor 

int main()
{// main program
	// test the institution by printing out information of the student and the classroom 
	// then allows the user to input 2 varaibles that will determine the size and number of classrooms/students 
	
	std::cout << "mainprogram: start" << std::endl;
	institute* inst = new institute();
	for(int i = 0; i < 256; i++)
	{
	
		std::cout << "student id: " << inst->get_students()->find_node(i)->get_pointer()->get_student_id() << std::endl;
		std::cout << "for loop count: " << i << std::endl;
		std::cout << "class_id of student: " << inst->get_students()->find_node(i)->get_pointer()->get_class_id() << std::endl;
		
		for(int j = 0; j < 8; j++)
		{
			std::cout << "state of classroom " << j + 1 << " (index:" << j << "): ";
			std::cout << ((inst->get_classes()->find_node(j)->get_pointer()->check_student_state(inst->get_students()->find_node(i)->get_pointer())== 1) ? "seat is reserved" : "seat is used by student");
			std::cout << std::endl;
		}
		
		std::cout << std::endl;
	}
	std::cout << "Available seats in institute: " << (inst->isFull() ? "institution is full" : ((256 - inst->get_student_number()) + " seats available")) << std::endl;
	
	int stud = 0, clas = 0; // take in user input for number of classes and students 
	std::cout << "Create institution of own:" << std::endl << "Input student number(MAX 255, MIN 0): ";
	std::cin >> stud;
	std::cout << "Input class number: ";
	std::cin >> clas;
	std::cout << std::endl;
	
	institute* create = new institute(stud, clas);
	for(int i = 0; i < stud; i++)
	{ // loop for new institute made by user input 
	
		std::cout << "student id: " << create->get_students()->find_node(i)->get_pointer()->get_student_id() << std::endl;
		std::cout << "for loop count: " << i << std::endl;
		std::cout << "class_id of student: " << create->get_students()->find_node(i)->get_pointer()->get_class_id() << std::endl;
		
		for(int j = 0; j < clas; j++)
		{
			std::cout << "state of classroom " << j + 1 << " (index:" << j << "): ";
			std::cout << ((create->get_classes()->find_node(j)->get_pointer()->check_student_state(create->get_students()->find_node(i)->get_pointer())== 1) ? "seat is reserved" : "seat is used by student");
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	
	std::cout << std::endl << "Available seats in institute: " << (create->isFull() ? "institution is full" : (std::to_string(256 - create->get_student_number()) + " seats available")) << std::endl;
	std::cout << std::endl;
	
	delete(inst);
	delete(create);
	return 0;
	
}// End main 

int institute::isFull()
{// if student number is 255 retuns 1
	if(this->student_number == 256)
		return 1;
	return 0;
}// End isFull

void institute::add_student(student* s)
{// add a student into the array 

	if(isFull())
	{
		std::cout << "CLASS IS FULL" << std::endl << "student unable to enter class" << std::endl;
	}
	else
	{
		students->add_node(s);
		++student_number;
		s->set_seat_id(student_number);
	}
}// End add_student

void institute::remove_student(student* s)
{// removes the particular student from the institution using the pointer of the student 
	students->delete_node(s);
	--student_number;
}// End remove_student(student*)

void institute::remove_student(int index)
{// removes the particular student from the institution using the index of the student 
	students->delete_node(index);
	--student_number;
}// End remove_student(int)

int institute::get_student_number()
{// returns the student number 
	return student_number;
}// End get_student_number 

PointerList<student>* institute::get_students()
{// returns the students PointerList 
	return students;
}// End get_students

PointerList<classroom>* institute::get_classes()
{// returns the classes PointerList 
	return classes;
}// End get_classes 

