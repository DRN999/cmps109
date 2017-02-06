#ifndef CLASSROOM
#define CLASSROOM
#include "student.h"
#include "PointerList.h"

class institute;

class classroom
{ // holds the student 
	private:
		int class_number; // the class index inside institution 
		int student_number; // number of students in this class
		institute* institution; // reference to the insitution this class is in 
	public:
		classroom(); // default constructor 
		classroom(int c_n, institute* i);
		~classroom(); // deconstructor 
		int get_student_number(); // returns the number of students 
		int get_class_number(); // returns the class number in institution 
		int check_student_state(student* s); 	// returns 0 for student not inside institution, returns 1 for seat resereved
												// for student, returns 2 for student using the seat 
		void set_student_number(int num); // set the student_number 
		void set_class_number(int num);  // set the class_number 
		void check_class_size(); // reset the student_number inside this particular class
};

#endif