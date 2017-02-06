#ifndef STUDENT
#define STUDENT

class classroom;

class student
{ // hold student information 
	
		private: 
			int class_id; // the class number it is in (institution)
			int student_id; // the student number in the institution 
			int seat_id; // the student number in the classroom 
		public: 
			student(); // default constructor
			student(int c_id, int s_id); // constructor for class number and student number in institute
			~student(); // destructor
			int get_class_id(); // returns the classroom
			int get_student_id(); // returns the student_id 
			void set_class(int id); // sets class_id with the input 
			void set_student_id(int id); // set student_id with the input 
			void set_seat_id(int id); // set seat number of the institution 
};

#endif