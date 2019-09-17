examheap: examheap.cpp heap.cpp heap.h
	g++ -c examheap.cpp
	g++ -c heap.cpp
	g++ examheap.o heap.o -o examheap
