#include <vector>
#include<iostream>
using namespace std;

int Parent(int i)
{
	return i / 2;
}

int Left(int i)
{
	return (i + 1) * 2 - 1;
} // end of Left

int Right(int i)
{
	return (i + 1) * 2;
} // end of Right

void Max_Heapify(std::vector<int>& A, int i, int heap_size)
{
	int largest;
	int l = Left(i);
	int r = Right(i);
	if (l <= heap_size && A[l] > A[i]) {
		largest = l;
	}
	else {
		largest = i;
	}
	if (r <= heap_size && A[r] > A[largest]) {
		largest = r;
	}
	if (largest != i) {
		swap(A[i], A[largest]);
		Max_Heapify(A, largest, heap_size);
	}
	
} // end of Max_Heapify

void Build_Max_Heap(std::vector<int>& A)
{
	for (int i = A.size()/2; i >= 0; i--) {
		Max_Heapify(A, i, A.size()-1);
	}
} // end of Build_Max_Heap