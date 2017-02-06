#ifndef INSTITUTE
#define INSTITUTE

#include "student.h"
#include "classroom.h"
#include "PointerList.h"

class institute
{
	private:
		PointerList<classroom>* classes; // 8 classes by default
		PointerList<student>* students; // total number of students
		int student_number; // current number of students 
		int class_number;
	public:
		institute();
		institute(int stud); 
		institute(int stud, int clas);
		~institute();
		void add_student(student* s); // adds the student to the array
		void remove_student(student* s); // finds and removes the student using their pointer 
		void remove_student(int s); // finds and removes the student using their index 
		PointerList<student>* get_students(); // returns the students variable 
		PointerList<classroom>* get_classes(); // returns the classes varaible 
		int isFull(); // returns if list of students is full 
		int get_student_number(); // returns the student_number 
		int get_class_number(); // returns the class_number 
};

#endif