#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>
#include "matplotlibcpp.h"


namespace plt = matplotlibcpp;
using namespace std;

void generate_random_data(vector<int>& v, int n);
void Build_Max_Heap(vector<int>& A);

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
	vector<double> linear_func;
	vector<double> result1;

	for (int i = 1; i <= 100; i++) {
		data_size.push_back(i * 10000);
		linear_func.push_back(i*0.00011);
	}

	time_count(Build_Max_Heap, data_size, result1);
	time_log("Build_Max_Heap", data_size, result1);
	
	/*for (int i = 0; i < 100; i++) {
		result1[i] = result1[i] / linear_func[i];
	}*/

	plt::figure_size(600, 400);
	plt::named_plot("Build_Max_Heap", data_size, result1, "b-");
	plt::named_plot("$\\Theta(n)$", data_size, linear_func, "r--");
	plt::title("Build_Max_Heap Time Complexity");
	plt::ylabel("Running Time");
	plt::xlabel("Input Size");
	plt::legend();
	plt::pause(1);
	plt::show();
}
