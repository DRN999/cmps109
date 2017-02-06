#include <iostream>
#include "PointerList.h"
// comment out the entire code
// figured that I need this in my header file due to the fact that all my function side the headers are
// template functions. therefore cannot be inside the .cpp implementation, otherwise it will return 
// a undefined reference link error 
/*
template <class T>
PointerList<T>::PointerList(T* t)
{// the default constructor for the node, constructs the first node
	pointer = t;
	node_number = 0;
	next = nullptr;
	prev = nullptr;
	start = 1;
	end = 1;
}// End default constructor 

template <class T>
PointerList<T>::PointerList(T* t, int nn, PointerList<T>* p)
{// Constructor for adding a node onto a existing list
	pointer = t;
	node_number = nn;
	next = nullptr;
	prev = p;
	start = 0;
	end = 1;
}// End addNode

template <class T>
PointerList<T>::~PointerList()
{// destructor 

}// End destructor 

template <class T>
void PointerList<T>::delete_node(T* t)
{// finds and deletes the node from the list
	PointerList<T>* p = this->find_node(t);
	this.remove_node(p);
	
}// End deleteNode

template <class T>
void PointerList<T>::delete_node(int i)
{
	PointerList<T>* p = this->find_node(i);
	this->remove_node(p);
}

template <class T>
void PointerList<T>::remove_node(PointerList<T>* p)
{
	if(p->get_start() && p->get_end())
	{// if this node is the only node 
		delete(this);
	}
	else if(p->get_start())
	{// if this node is the starting node but not the only node 
		p->next->reset_node_number();
		p->next->set_prev(nullptr);
		delete(this);
	}
	else if(p->get_end())
	{// if this node is the ending node but not the only node 
		p->prev->set_next(nullptr);
		p->prev->to_end();
		delete(this);
	}
	else
	{// if this node is in between 2 other nodes 
		p->get_prev()->set_next(p->next);
		p->get_next()->set_prev(p->prev);
		p->get_next()->reset_node_number(p->get_node_number());
		delete(this);
	}
}

template <class T>
void PointerList<T>::add_node(T* t)
{// adds a node to this list inputting a pointer 
	if(!end)
	{
		this->next->add_node(t);
	}
	else
	{
		PointerList<T> p = new PointerList<T>(t, node_number+1, this);
		this->next = &p;
		this->not_end();
	}
}// End add_node s

template <class T>
void PointerList<T>::reset_node_number()
{// calls reset_node_number assuming the starting node
	this->reset_node_number(0);
}// End reset_node_number(void)

template <class T>
void PointerList<T>::reset_node_number(int i)
{// re-initializes the node_number of each node 
	this->node_number = i;
	if(!end)
	{
		this->next->reset_node_number(i+1);
	}
}// End reset_node_number 

template <class T>
void PointerList<T>::not_start()
{// sets the start variable of this node to false
	this->start = 0;
}// End not_start 

template <class T>
void PointerList<T>::to_start()
{// sets the start variable of this node to true
	this->start = 1;
}// End to_start 

template <class T>
void PointerList<T>::not_end()
{// sets the end variable of this node to false
	this->end = 0;
}// End not_end

template <class T>
void PointerList<T>::to_end()
{// sets the end variable of this node to true
	this->end = 1;
}// End to_end

template <class T>
void PointerList<T>::set_pointer(T* t)
{// set the pointer variable to the input pointer 
	this->pointer = t;
}// End set_pointer 

template <class T>
void PointerList<T>::set_prev(PointerList<T>* p)
{// sets the previous node to the input pointer 
	this->prev = p;
}// End set_prev 

template <class T>
void PointerList<T>::set_next(PointerList<T>* p)
{// sets the next node to the input pointer 
	this->next = p;
}// End set_next 

template <class T>
int PointerList<T>::is_empty()
{// returns if this node is nullptr or not 
	if(this.pointer == nullptr)
		return 1;
	return 0;
}// End is_empty 

template <class T>
int PointerList<T>::get_start()
{// returns the start variable of this node
	return start;
}// End get_start 

template <class T>
int PointerList<T>::get_end()
{// returns the end variable of this node 
	return end;
}// End get_end 

template <class T>
int PointerList<T>::get_node_number()
{// returns the node_number variable 
	return node_number; 
}// End node_number 

template <class T>
int PointerList<T>::get_size()
{
	PointerList* p = this;
	int size = 1;
	while(!p->get_end())
	{
		p = p->get_next();
		++size;
	}
	return size;
}

template <class T>
PointerList<T>* PointerList<T>::get_prev()
{// returns the previous node pointer 
	return this.prev;
}// End get_prev 

template <class T>
PointerList<T>* PointerList<T>::get_next()
{// returns the next node pointer 
	return this.next;
}// End get_next 

template <class T>
T* PointerList<T>::get_pointer()
{// returns the pointer variable of this node 
	return this.pointer;
}// End get_pointer 

template <class T>
PointerList<T>* PointerList<T>::find_node(T* t)
{// finds a particular node of the list with the same pointer 
	if(this.start)
	{
		PointerList<T>* p = this;
		if(this->get_pointer() == t)
		{
			return p;
		}
		
		while(!p->get_end())
		{
			p = p->get_next();
			if(p->get_pointer == t)
				return p;
		}
	}
	else
	{ // since this function assumes the user is calling it from the start node, it check if it is not 
		
	}	
	return nullptr;
}// End find_node(T*) 

template <class T>
PointerList<T>* PointerList<T>::find_node(int i)
{// finds the pointer of the particular node in the list with the index of the node 
	if(this.start)
	{
		PointerList<T>* p = this;
		while(i)
		{
			p = p->get_next();
			--i;
		}
		return p;
	}	
	else
	{ // since this function assumes the user is calling it from the start node, it check if it is not 
		
	}	
	return nullptr;
}// End find_node(int) 

*/