#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
using table_type  = vector<vector<int>>;
using result_type = pair<table_type, table_type>; 


result_type matrix_chain_order(const vector<int>& matrices) 
{
	int len = matrices.size() - 1;
	table_type m(len + 1, vector<int>(len + 1));
	table_type s(len, vector<int>(len + 1));

	int i;
	for(i = 1; i <= len; ++i)
		m[i][i] = 0;

	for(int l = 2; l <= len; ++l) { // the length of multiplying matrices
		for(i = 1; i <= len - l + 1; ++i) { // i is the begin position of multiplying matrices
			int j = i + l - 1; // j is the end position of multiplying matrices
			for(int k = i; k <= j - 1; ++k) {
				int q = m[i][k] + m[k+1][j] + matrices[i-1] * matrices[k] * matrices[j];
				if(q < m[i][j] || m[i][j] == 0) {
					m[i][j] = q; // the minimum cost of multiplying matrices
					s[i][j] = k; // which position has given us minimum cost
				}
			}
		}
	}

	return make_pair(m, s);
}

void print_optimal_parens(const table_type& s, int i, int j) 
{
	if(i == j) cout << "A" << i;
	else {
		cout << "(";
		print_optimal_parens(s, i, s[i][j]);
		print_optimal_parens(s, s[i][j] + 1, j);
		cout << ")";
	}
}

void print_ms(const result_type& ms) 
{
	const auto& [m, s] = ms;
	int len = m.size() - 1;

	// print m
	int i, j;
	for(i = 1; i <= len; ++i) {
		for(j = 1; j <= len; ++j) {
			printf("%d\t", m[i][j]);
		}
		cout << endl;
	}
	cout << "--------------------------------------\n";

	// print s
	for(i = 1; i < len; ++i) {
		for(j = 1; j <= len; ++j) {
			printf("%d\t", s[i][j]);
		}
		cout << endl;
	}
	cout << "--------------------------------------\n";

	print_optimal_parens(s, 1, len);
	cout << endl;
}

int main() 
{
	vector<int> matrices{5, 4, 6, 2, 7};
	print_ms(matrix_chain_order(matrices));

	return 0;
}
