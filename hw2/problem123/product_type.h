#ifndef PRODUCT_TYPE
#define PRODUCT_TYPE 

#include "PointerList.h"
#include "product.h"

class product_type
{
	private:
		PointerList<product>* products; // 8 products with different colors 
		int product_id; // the id of the product in the inventory 
	public:
		product_type(); // default constructor 
		product_type(int id); // constructor with id input 
		~product_type(); // destructor 
		int get_product_id(); // returns the product_id 
		int get_total_stock(); // returns the total stock from all the colors 
		int get_color_stock(int c); //returns the stock of a particular color 
		void add_color_stock(int c, int a); // adds the input value into the stock of the specific color 
		void sub_color_stock(int c, int s); // subtracts the input value into the stock of the specific color 
		PointerList<product>* get_products(); // returns products 
};

#endif 
