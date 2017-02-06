#ifndef MAX_HEAP
#define MAS_HEAP

#include "Heap.h"
#include "PointerList.h"
#include "product.h"
// Noriaki Nakano
// This code(and the.cpp file) displays that I am currenty clueless as to how this heap structure should be working.
// I do so by extending Heap, then proceeding to completely ignore everything about Heap and make a linked-list instead, 
// then ran out of time so I needed to submit something.
// The reasoning for even attemping to forcefully change this into a linked-list
// should be more explained in the documentation inside README.

class MAX_Heap: public Heap
{
	private:
		PointerList<product>* list; // ordered linked list 
		int max_num, count;
	public:
		MAX_Heap(int MSize); // default constructor 
		bool insert (int item);
		bool delMax(int & item);
		MAX_Heap operator+(const MAX_Heap & h);
		MAX_Heap operator+(const int i);
		int operator[](int);
		MAX_Heap operator=(const MAX_Heap & h);
		MAX_Heap operator+=(const MAX_Heap & h);
		std::ostream &operator<<(std::ostream &output);
		
		~MAX_Heap();
};

#endif