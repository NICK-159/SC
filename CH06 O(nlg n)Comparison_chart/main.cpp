#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;
using namespace std;

void generate_random_data(vector<int>& v, int n);
void std_heap_sort(vector<int>& A);
void Heapsort(vector<int>& A);
void merge_sort(vector<int>& A, int p, int r);
void std_priority_queue(vector<int>& A);

void time_count(void(*fun)(vector<int>&), const vector<double> data_size, vector<double>& running_time)
{
	chrono::high_resolution_clock::time_point start, end;
	vector<int> A;
	for (int i = 0; i < data_size.size(); i++) {
		// 產生資料
		generate_random_data(A, data_size[i]);
		// 開始計時
		start = chrono::high_resolution_clock::now();
		fun(A);
		end = chrono::high_resolution_clock::now();
		// 結束計時
		chrono::duration<double> diff = end - start;
		running_time.push_back(diff.count());
	}
}

void time_count(void(*fun)(vector<int>&, int, int), const vector<double> data_size, vector<double>& running_time)
{
	chrono::high_resolution_clock::time_point start, end;
	vector<int> A;
	for (int i = 0; i < data_size.size(); i++) {
		// 產生資料
		generate_random_data(A, data_size[i]);
		// 開始計時
		start = chrono::high_resolution_clock::now();
		fun(A, 0, A.size() - 1);
		end = chrono::high_resolution_clock::now();
		// 結束計時
		chrono::duration<double> diff = end - start;
		running_time.push_back(diff.count());
	}
}

void time_log(const string name, const vector<double>& x, const vector<double>& y)
{
	cout << name << ":" << endl;
	for (int i = 0; i < x.size(); i++) {
		cout << "Size:" << setw(7) << (int)x[i] << " Time:" << fixed << setprecision(7) << y[i] << endl;
	}
	cout << endl;
}

int main() {
	vector<double> data_size;
	vector<double> n_lg_n;
	vector<double> result1, result2, result3, result4;

	for (int i = 1; i <= 100; i++) {
		data_size.push_back(i * 10000);
		n_lg_n.push_back(i * log2(i) * 0.0003);
	}

	time_count(std_heap_sort, data_size, result1);
	time_log("std_heap_sort", data_size, result1);
	time_count(Heapsort, data_size, result2);
	time_log("Heapsort", data_size, result2);
	time_count(merge_sort, data_size, result3);
	time_log("merge_sort", data_size, result3);
	time_count(std_priority_queue, data_size, result4);
	time_log("std_priority_queue", data_size, result4);

	plt::figure_size(600, 400);
	plt::named_plot("std_heap_sort", data_size, result1);
	plt::named_plot("Heapsort_CLRS", data_size, result2);
	plt::named_plot("merge_sort_CLRS", data_size, result3);
	plt::named_plot("std_priority_queue", data_size, result4);
	plt::named_plot("$\\Theta(n*lg(n))$", data_size, n_lg_n);
	plt::title("Sorting Algorithm Time Complexity");
	plt::ylabel("Running Time");
	plt::xlabel("Input Size");
	plt::legend();
	plt::pause(1);
	plt::show();
}
