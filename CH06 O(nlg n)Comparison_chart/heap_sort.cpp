#include <vector>
using namespace std;

void Build_Max_Heap(std::vector<int>& A);
void Max_Heapify(std::vector<int>& A, int i, int heap_size);

void Heapsort(vector<int>& A)
{
	unsigned heapSize = A.size() - 1;
	Build_Max_Heap(A);
	for (unsigned i = heapSize; i > 0; --i) {
		swap(A[0], A[i]);
		heapSize -= 1;
		Max_Heapify(A, 0, heapSize);
	}
}
