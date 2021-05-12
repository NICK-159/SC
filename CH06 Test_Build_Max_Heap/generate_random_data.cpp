#include <vector>
#include <algorithm>
using namespace std;

void generate_random_data(vector<int>& v, int n)
{
	v.resize(n);
	auto f = [n]() -> int { return rand() % n; };
	generate(v.begin(), v.end(), f);
}