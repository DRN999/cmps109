#ifndef SCANNER 
#define SCANNER 

#include "PointerList.h"
#include "product_type.h"

class scanner
{// main program 

	private:
		PointerList<product_type>* inventory; // hold 256 product types 
	public:
		scanner(); // default constructor 
		~scanner(); // destrutor 
		void add_stock(int id, int c, int a); // add stock to id of color by amount 
		void sub_stock(int id, int c, int s); // subtract stock to id of color by amount
		void print_inventory(); // prints inventory information 
		int check_stocked_id(int id); // returns true if product_type of id is stocked
		int check_stocked_color(int id, int c); // returns true if product_type of id and color is stocked
		int num_stocked(); // returns the number of product_types that are stocked 
		PointerList<product_type>* get_inventory(); // returns the inventory pointer 
		
};// End class scanner 

#endif
