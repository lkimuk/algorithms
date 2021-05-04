#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int partition(vector<int>& A, int start, int end)
{
	int pivot = A[end];
	int partitionIndex = start;
	for(int i = start; i < end; ++i) {
		if(A[i] <= pivot) {
			swap(A[i], A[partitionIndex]);
			partitionIndex++;
		}
	}

	swap(A[partitionIndex], A[end]);
	return partitionIndex;
}

void quicksort(vector<int>& A, int start, int end)
{
	if(start < end) {
		int partitionIndex = partition(A, start, end);
		for(int elem : A) cout << elem << ' ';
		cout << "partition index:" << partitionIndex << endl;
		quicksort(A, start, partitionIndex - 1);
		quicksort(A, partitionIndex + 1, end);
	}
}

int main()
{
	vector<int> A{6, 9, 3, 12, 5, 8, 7};
	for(int elem : A) cout << elem << ' ';

	cout << "\nsorting details:\n";
	
	quicksort(A, 0, A.size() - 1);
	for(int elem : A) cout << elem << ' ';


	cout << endl;
	return 0;
}
