// C++ program to find the element
// occurring odd number of times
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countSort(vector<int> &arr, int n, int exp)
{
	 // output array
	vector<int> output(n);
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual
	//  position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
template<class T>
void radixsort(vector<T> &arr, int n)
{
	// Find the maximum number to know number of digits

	int m = *max_element(arr.begin(), arr.end());

	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}





int main() {
	vector<int> vec;
	int counter = 10;
	for (int i = 0; i < 10; i++) {
		vec.push_back(--counter);
	}
	radixsort(vec,10);
	for (auto it : vec)
		cout << it << " ";
	cout << endl;


}
