#include <iostream>
#include "MAX_Heap.h"


MAX_Heap::MAX_Heap(int MSize):Heap(MSize)
{
	list = new PointerList<product>(new product(0));
	max_num = MSize;
	count = 0;
}

bool MAX_Heap::insert(int item)
{// inserts the item so that the smallest item will come to the top of the heap 
	count++;
	if(count >= max_num)
	{
		std::cout << "Heap is full" << std::endl;
		return false;
	}
	if(count == 1)
		list->set_pointer(new product(item));
	else
	{
		PointerList<product>* temp  = list;
		if(temp->get_pointer()->get_stock() > item)
			temp->insert_before(new product(item));
		else
		{
			while(temp->get_pointer()->get_stock() < item && !temp->get_end())
			{
				temp = temp->get_next();
				if(temp->get_end())
				{
					temp->insert_after(new product(item));
				}
				else if(temp->get_pointer()->get_stock() < item)
				{
					temp->insert_before(new product(item));
				}
			}
		}
	}
	return true;
}// End insert 

bool MAX_Heap::delMax(int & item)
{
	if (!count) 
	{ 
		std::cout << "heap is empty" << std::endl ; 
		return false; 
	}
	
	return true;
}