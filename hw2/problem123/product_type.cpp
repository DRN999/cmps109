#include <iostream>
#include "product_type.h"

product_type::product_type()
{// default constructor 
	this->products = new PointerList<product>(new product(0, 0));
	for(int i = 1; i < 8; i++)
		this->products->add_node(new product(0, i));
	this->product_id = 0;
}// End constructor 

product_type::product_type(int id)
{// constructor with id parameter 
	this->products = new PointerList<product>(new product(0, 0));
	for(int i = 1; i < 8; i++)
		this->products->add_node(new product(0, i));
	this->product_id = id;
}// End constructor 

product_type::~product_type()
{// destructor 

	this->products->delete_list();
	delete ((product*)this->products->get_pointer());
	delete (products);
	
}// End destructor 

int product_type::get_product_id()
{// returns product_id 
	return this->product_id;
}// End get_product_id 

int product_type::get_total_stock()
{ // returns the total stock from all the colors 
	int total = 0;
	PointerList<product>* p = this->products;
	total += p->get_pointer()->get_stock();
	while(!p->get_end())
	{
		p = p->get_next();
		total += p->get_pointer()->get_stock();
	}
	return total;
}// End get_total_stock 

int product_type::get_color_stock(int c)
{//returns the stock of a particular color 
	return (this->products->find_node(c)->get_pointer()->get_stock());
}// End get_color_stock 


void product_type::add_color_stock(int c, int a)
{// adds the input value into the stock of the specific color 
	this->products->find_node(c)->get_pointer()->add_to_stock(a);
}// End add_color_stock 

void product_type::sub_color_stock(int c, int s)
{// subtracts the input value into the stock of the specific color
	this->products->find_node(c)->get_pointer()->sub_to_stock(s);
}// End sub_color_stock 

PointerList<product>* product_type::get_products()
{// returns products 
	return this->products;
}// End get_products 
