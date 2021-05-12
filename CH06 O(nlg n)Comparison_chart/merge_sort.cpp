#include <vector>
using namespace std;

void merge(vector<int>& A, int p, int q, int r)
{
	int n1, n2, i, j, k;
	n1 = q - p + 1;
	n2 = r - q;
	vector<int> L(n1 + 1), R(n2 + 1);
	for (i = 0; i < n1; ++i)
		L[i] = A[p + i];
	for (j = 0; j < n2; ++j)
		R[j] = A[q + 1 + j];
	L[i] = INT_MAX;
	R[j] = INT_MAX;
	i = 0;
	j = 0;
	for (k = p; k <= r; ++k) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			++i;
		}
		else {
			A[k] = R[j];
			++j;
		}
	}
}

void merge_sort(vector<int>& A, int p, int r)
{
	if (p < r) {
		int q = floor((p + r) / 2) + 1;
		merge_sort(A, p, q - 1);
		merge_sort(A, q, r);
		merge(A, p, q - 1, r);
	}
}