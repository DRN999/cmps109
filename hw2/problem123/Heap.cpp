#include <iostream>
#include "Heap.h"
using namespace std;

void Heap::adjust (int a[], int i, int n)
{
	int j = 2*i, item = a[i];
	while ( j <= n )
	{
		if (j<n && (a[j] < a[j+1])) j++;
		// Compare left and right child
		// and let j be the larger child
		if ( item >= a[j] ) break;
		a[j/2] = a[j]; j*=2;
	}
	a[j/2] = item;
}
Heap::Heap(int MSize):MaxSize(MSize)
{
	array = (int *) calloc(MSize+1,sizeof(int));
	Nel = 0;
}
bool Heap::insert (int item)
{
	int i = ++Nel;
	if ( i == MaxSize)
	{
		cout << "heap size exceeded" << endl;
		return false;
	}
	while ( (i > 1 ) && ( array[i/2] < item )) 
	{
		array[i] = array[i/2];
		i/=2;
	}
	array[i] = item;
	return true;
}

bool Heap::delMax(int & item)
{
	if ( !Nel) 
	{ 
		cout << "heap is empty" << endl ; return false; 
	}
	item = array[1];
	array [1] = array[Nel--];
	adjust (array,1,Nel);
	return true;
}