#include <queue> // priority_queue
using namespace std;

void std_priority_queue(vector<int>& A)
{
	priority_queue<int,vector<int>,greater<int>> q;
	for (int i = 0; i < A.size(); i++) {
		q.push(A[i]);
	}
	for (int i = 0; i < A.size(); i++) {
		A[i] = q.top();
		q.pop();

	}
}
