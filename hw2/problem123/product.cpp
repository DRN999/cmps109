#include <iostream>
#include "product.h"

product::product()
{// default constructor 
	this->stock = 0;
	this->color_id = 0;
}// End constructor 

product::product(int s)
{// constuctor with parameter 
	this->stock = s;
	this->color_id = 0;
}// End constructor 

product::product(int s, int id)
{// constructor with parameter, with color_id input 
	this->stock = s;
	this->color_id = id;
}// End constructor 

product::~product()
{// destructor 
	
}// End destructor  

int product::get_stock()
{// returns the stock varaible of this object 
	return this->stock;
}// End get_stock 

int product::get_color_id()
{// returns the color_id variable of this object 
	return this->color_id;
}// End get_color_id 

void product::increment_stock()
{// increments the stock by one 
	if(this->stock < 255)
		this->stock++;
	else
		std::cout << "inventory space for this product is full, cannot increment" << std::endl;
}// End increment_stock 

void product::decrement_stock()
{// decrements the stock by one 
	if(this->stock > 0)
		this->stock--;
	else
		std::cout << "no stock, cannot decrement" << std::endl;
}// End decrement_stock 

void product::add_to_stock(int a)
{// add the input value to the stock 
	if(this->stock + a < 256)
		this->stock += a;
	else
		std::cout << "inventory space for this product will overflow, cannot add" << std::endl;
}// End add_to_stock 

void product::sub_to_stock(int s)
{// subtracts the input value from the stock 
	if(this->stock - s >= 0)
		this->stock -= s;
	else 
		std::cout << "stock will go below zero, cannot subtract" << std::endl;
}// End sub_to_stock 

void product::set_stock(int s)
{// sets the stock to the input value 
	if(s >= 0 && s < 256)
		this->stock = s;
	else
		std::cout << "input stock is out of range (0-255)" << std::endl;
}// End set_stock 

void product::set_color_id(int id)
{// sets the color_id into the input value 
	this->color_id = id;
}// End set_color_id 

