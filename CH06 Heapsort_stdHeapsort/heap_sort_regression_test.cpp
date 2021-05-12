#define CATCH_CONFIG_MAIN
#include <vector>
#include <algorithm>
#include "catch.hpp"
using namespace std;

void std_heap_sort(vector<int>& A);
void Heapsort(vector<int>& A);

TEST_CASE("std_heap_sort are computed", "[std_heap_sort]") {
	vector<int>A = { 8,4,3,9,5 };
	vector<int> ans = { 3,4,5,8,9 };
	std_heap_sort(A);
	REQUIRE(A == ans);
}

TEST_CASE("Heapsort are computed", "[Heapsort]") {
	vector<int>A = { 8,4,3,9,5 };
	vector<int> ans = { 3,4,5,8,9 };
	Heapsort(A);
	REQUIRE(A == ans);
}

TEST_CASE("Heapsort regression test are computed", "[Regression]") {
	vector<int>A = { 8,4,3,9,5 };
	vector<int>B = { 8,4,3,9,5 };
	std_heap_sort(A);
	Heapsort(B);
	REQUIRE(A == B);
}
