#include <iostream>
#include "scanner.h"

scanner::scanner()
{// default constructor 
	this->inventory = new PointerList<product_type>(new product_type(0));
	for(int i = 1; i < 256; i++)
	{
		this->inventory->add_node(new product_type(i));
	}
}// End constructor 

scanner::~scanner()
{// destructor

	inventory->delete_list();
	delete ((product_type*) inventory->get_pointer());
	delete (inventory); 
	
}// End destructor 

void scanner::add_stock(int id, int c, int a)
{// adds the amount to the color and id 
	this->inventory->find_node(id)->get_pointer()->add_color_stock(c, a);
}// End add_stock 

void scanner::sub_stock(int id, int c, int s)
{// subtracts the stock from product 
	this->inventory->find_node(id)->get_pointer()->sub_color_stock(c, s);
}// End sub_stock 

void scanner::print_inventory()
{// prints the inventory 
	for(int i = 0; i < 256; i++)
	{
		std::cout << "Product ID: " << this->get_inventory()->find_node(i)->get_pointer()->get_product_id() << std::endl;
		std::cout << "total stock in product: " << this->get_inventory()->find_node(i)->get_pointer()->get_total_stock() << std::endl;
		std::cout << "each color stock: ";
		for(int j = 0; j < 8; j++)
		{
			std::cout << this->get_inventory()->find_node(i)->get_pointer()->get_color_stock(j) << " ";
		}
		std::cout << std::endl << std::endl;
	}
	std::cout << "number of product_types that are stocked: " << this->num_stocked() << std::endl;
}// End print_inventory 

int scanner::check_stocked_id(int id)
{
	return this->inventory->find_node(id)->get_pointer()->get_total_stock() > 0;
}

int scanner::check_stocked_color(int id, int c)
{
	return this->inventory->find_node(id)->get_pointer()->get_color_stock(c) > 0;
}

int scanner::num_stocked()
{// returns the number product types are stocked 
	int total = 0;
	for(int i = 0; i < 256; i++)
	{
		if(this->inventory->find_node(i)->get_pointer()->get_total_stock() > 0)
			++total;
	}
	return total;
}// End num_stock 

PointerList<product_type>* scanner::get_inventory()
{// returns inventory 
	return this->inventory;
}// End get_inventory 

int main()
{// main
	scanner* s = new scanner();
	s->print_inventory();
	
	int id = 0, col = 0, amo = 0;
	std::cout << "Input id(0-255): ";
	std::cin >> id;
	std::cout << "Input color(0-7): ";
	std::cin >> col;
	std::cout << "Input amount to add: ";
	std::cin >> amo;
	s->add_stock(id, col, amo);
	s->print_inventory();
	
	delete(s);
	return 0;
}// End main