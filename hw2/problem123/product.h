#ifndef PRODUCT 
#define PRODUCT 

class product
{
	private:
		int stock; // the stock of this product 
		int color_id;
	public:
		product(); // default constructor, stock = 0;
		product(int s); // set stock = s
		product(int s, int id); // set stock and color_id
		~product();
		int get_stock(); // returns stock
		int get_color_id(); // returns color_id 
		void increment_stock(); // increment the stock by one 
		void decrement_stock(); // decrement the stock by one 
		void add_to_stock(int a); // adds the parameter to the stock
		void sub_to_stock(int s); // subtracts the parameter from the stock 
		void set_stock(int s); // sets stock to the parameter value 
		void set_color_id(int id); // sets the color_id to the parameter value 
};

#endif