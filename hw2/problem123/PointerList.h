#ifndef POINTERLIST
#define POINTERLIST
// Noriaki Nakano nnakano@ucsc.edu 
// cmps 109 assignment #2 
// Template class to take in pointers of data and put them into a link-list 

template <class T>
class PointerList
{
	
	private:
		T* pointer; // the actual pointer
		PointerList<T>* next; // pointer to the next node 
		PointerList<T>* prev; // pointer to the previous node 
		int node_number; // the node number of the node in the list 
		int start; // checks if this is the starting node 
		int end; // checks if this is the ending node
		
	public:
		PointerList<T>(T* t); // default constructor to start a new nodelist
		PointerList<T>(T* t, int nn, PointerList* p);// constructor to add a new node to the existing list
		~PointerList<T>(); // destructor 
		void delete_node(T* t); // deletes a node from the list with the pointer 
		void delete_node(int i); // deletes a node from the list with a index 
		void delete_list(); // default function for deleting the list 
		void delete_list(PointerList<T>* p); // recursion function for deleteing the list
		void remove_node(PointerList<T>* p); // removes the input node of the input pointerlist 
		void add_node(T* t); // adds a node to the list 
		void insert_after(T* t); // insert_after the node 
		void insert_before(T* t); // insert_before the node 
		void reset_node_number(); // reset the node number assuming input number is zero
		void reset_node_number(int n); // resets the node number starting from the input number
		void to_start(); // changes the start variable of ths node to true 
		void not_start(); // changes the start variable of this node to false 
		void to_end();// changes the end variable of this node to true 
		void not_end(); // changes the end variable of this node to false 
		void set_pointer(T* t); // set the pointer of the node to the input pointer of object 
		void set_prev(PointerList* p); // sets the previous node to the input pointer 
		void set_next(PointerList* p); // sets the next node to the input pointer 
		int is_empty(); // returns if the list is empty or not 
		int get_start(); // returns the start variable of this node 
		int get_end(); // returns the end variable of this node 
		int get_node_number(); // returns the node_number variable 
		int get_size(); // returns the size of the list 
		PointerList<T>* get_prev(); // returns the pointer of the previous node 
		PointerList<T>* get_next(); // returns the pointer of the next node 
		PointerList<T>* find_node(T* t);
		PointerList<T>* find_node(int i);// returns the pointer with the input index of the node from the first node 
		T* get_pointer(); // returns the input pointer
		
}; // End class PointerList 



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
	this->remove_node(p);
	
}// End deleteNode

template <class T>
void PointerList<T>::delete_node(int i)
{
	PointerList<T>* p = this->find_node(i);
	this->remove_node(p);
}

template <class T>
void PointerList<T>::delete_list()
{
	if(!this->end)
		delete_list(this->next);
	this->remove_node(this->get_next());
}

template <class T>
void PointerList<T>::delete_list(PointerList<T>* p)
{
	if(!p->get_next()->get_end())
		p->delete_list(p->get_next());
	p->remove_node(p->get_next());
}

template <class T>
void PointerList<T>::remove_node(PointerList<T>* p)
{
	if(p->get_start() && p->get_end())
	{// if this node is the only node 
		delete((T*)p->get_pointer());
		delete(p);
	}
	else if(p->get_start())
	{// if this node is the starting node but not the only node 
		p->next->reset_node_number();
		p->next->set_prev(nullptr);
		delete((T*)p->get_pointer());
		delete(p);
	}
	else if(p->get_end())
	{// if this node is the ending node but not the only node 
		p->prev->set_next(nullptr);
		p->prev->to_end();
		delete((T*)p->get_pointer());
		delete(p);
	}
	else
	{// if this node is in between 2 other nodes 
		p->get_prev()->set_next(p->next);
		p->get_next()->set_prev(p->prev);
		p->get_next()->reset_node_number(p->get_node_number());
		delete((T*)p->get_pointer());
		delete(p);
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
		PointerList<T>* p = new PointerList<T>(t, node_number+1, this);
		this->next = p;
		this->not_end();
	}
}// End add_node s

template <class T>
void PointerList<T>::insert_after(T* t)
{// insert a node in between the list, after the current node 
	if(this->end)
	{
		this->add_node(t);
	}
	else
	{
		PointerList<T>* temp = new PointerList<T>(t, this->node_number + 1, this);
		temp->set_next(this->next);
		this->next->set_prev(temp);
		this->next = temp;
		temp->reset_node_number(temp->get_node_number());
	}
}// End insert_after 

template <class T>
void PointerList<T>::insert_before(T* t)
{// insert a node in between the list, before the current node 
	if(this->start)
	{
		PointerList<T>* temp = new PointerList<T>(t);
		temp->to_start();
		temp->set_next(this);
		this->prev = temp;
		this->not_start();
		temp->reset_node_number();
	}
	else
	{
		PointerList<T>* temp = new PointerList<T>(t);
		temp->set_prev(this->prev);
		this->prev->set_next(temp);
		this->prev = temp;
		temp->set_next(this);
		temp->reset_node_number(this->node_number);
	}
}// End insert_before 

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
	return this->prev;
}// End get_prev 

template <class T>
PointerList<T>* PointerList<T>::get_next()
{// returns the next node pointer 
	return this->next;
}// End get_next 

template <class T>
T* PointerList<T>::get_pointer()
{// returns the pointer variable of this node 
	return this->pointer;
}// End get_pointer 

template <class T>
PointerList<T>* PointerList<T>::find_node(T* t)
{// finds a particular node of the list with the same pointer 
	if(this->start)
	{
		PointerList<T>* p = this;
		if(this->get_pointer() == t)
		{
			return p;
		}
		
		while(!p->get_end())
		{
			p = p->get_next();
			if(p->get_pointer() == t)
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
	if(this->start)
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

#endif