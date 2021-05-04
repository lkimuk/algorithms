#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
using table_type  = vector<vector<int>>;
using result_type = pair<table_type, table_type>;


result_type lcs_length(const string& x, const string& y)
{
	table_type c(x.size() + 1, vector<int>(y.size() + 1));
	table_type b(x.size() + 1, vector<int>(y.size() + 1));

	for(int i = 1; i < x.size() + 1; ++i) {
		for(int j = 1; j < y.size() + 1; ++j) {
			if(x[i-1] == y[j-1]) {
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = 1; // top-left
			}
			else if(c[i-1][j] >= c[i][j-1]) {
				c[i][j] = c[i-1][j];
				b[i][j] = 2; // top
			}
			else {
				c[i][j] = c[i][j-1];
				b[i][j] = 3; // left
			}
		}
	}

	return make_pair(c, b);
}

void print_lcs(const table_type& b, const string& x, int i, int j)
{
	// cout << i << " " << j << "-----\n";
	if(i == 0 || j == 0) return;
	if(b[i][j] == 1) { // top-left
		print_lcs(b, x, i - 1, j - 1);
		cout << x[i-1];
	}
	else if(b[i][j] == 2) { // top
		print_lcs(b, x, i - 1, j);
	}
	else { // left
		print_lcs(b, x, i, j - 1);
	}
}

void print_cb(const table_type& c, const table_type& b) 
{
	auto print = [](const table_type& t) {
		for(const auto& i : t) {
			for(const auto& j : i) {
				cout << j << ' ';
			}
			cout << endl;
		}
	};

	print(c);
	cout << "---------------------------------\n";
	print(b);
}


int main()
{
	string x, y;
	cout << "please input two string:\n";
	cin >> x >> y;
	const auto& [c, b] = lcs_length(x, y);
	
	print_cb(c, b);
	cout << x << " and " << y << " have the longest common subsequence: ";
	print_lcs(b, x, x.size(), y.size());


	cout << endl;
	return 0;
} 
