#include <iostream>
#include <vector>
using namespace std;


void merge(vector<int>& A, int l, int m, int h)
{
	vector<int> L(m - l + 1);
	vector<int> R(h - m);
	int i, j, k;

	for(i = 0; i < L.size(); ++i)
		L[i] = A[l + i];
	for(j = 0; j < R.size(); ++j)
		R[j] = A[m + j + 1];

	i = j = 0;
	for(k = l; i < L.size() && j < R.size(); ++k) {
		if(L[i] < R[j])
			A[k] = L[i++];
		else
			A[k] = R[j++];
	}
	
	while(i < L.size()) A[k++] = L[i++];
	while(j < R.size()) A[k++] = R[j++];
}


void merge_sort(vector<int>& A, int l, int h)
{
	if(l < h) {
		int mid = (l + h) / 2;
		merge_sort(A, l, mid);
		merge_sort(A, mid + 1, h);
		merge(A, l, mid, h);
	}
}


int main()
{
	vector<int> A{9, 3, 7, 5, 6, 4, 8, 2};
	merge_sort(A, 0, A.size() - 1);
	for(const auto& elem : A) cout << elem << ' ';	

	cout << endl;
	return 0;
}
