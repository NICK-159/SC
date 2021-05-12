#include <vector>
#include <algorithm>
using namespace std;

void std_heap_sort(vector<int>& A)
{
	make_heap(A.begin(), A.end());
	sort_heap(A.begin(), A.end());
}
