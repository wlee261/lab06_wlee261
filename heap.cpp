// heap.cpp
// Winston Lee

#include "heap.h"
#include <iostream>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
/* approach: 
heaps node value is larger than that of its parents
heaps are complete binary tree, which means that
- nonroot data at node i will have a parent at node (i-1)/2
- children of a node (if they exist) are
	- left: 2i+1
	- right: 2i+2

1. push data onto heap
2. compare data with parents, switch if data is smaller than parent until
   data is larger than its parent
*/
void Heap::push(int value){
	vdata.push_back(value); 
	int parent = ((vdata.size())-1-1)/2; 
	int index = vdata.size()-1;

	while(value<vdata[parent] && index!=0){
		int temp = vdata[parent];
		vdata[parent] = value;
		vdata[index] = temp;
		index = parent;
		parent = (index-1)/2;
	}

}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged

/* Approach:
min value of a heap is at its root
when popping a value, remove the root and replace it with the last element in the heap
rearrange the tree so it is ordered like a heap again
*/
void Heap::pop(){
	vdata[0] = vdata[(vdata.size())-1];
	vdata.pop_back();
	int n = 0;
	int mindex = 0;
	while((2*n+1 < vdata.size())){ //compare parent to its children, switch data if the parent is larger than its children
		if(vdata[mindex] > vdata[2*n+1]) //left child
			mindex = 2*n+1;
		if(vdata[mindex] > vdata[2*n+2]) //right child
			mindex = 2*n+2;
		if(n!=mindex){ //switch data
			int temp = vdata[n];
			vdata[n] = vdata[mindex];
			vdata[mindex] = temp;
			n = mindex;
		}
		else
			break;


	}
}

// Returns the minimum element in the heap
int Heap::top(){
	if(vdata.empty()){
		return 0;
	}
	return vdata.front();
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
	if(vdata.empty())
		return true;
	return false;
}
    
