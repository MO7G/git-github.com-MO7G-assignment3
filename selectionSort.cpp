// C++ program to find the element
// occurring odd number of times
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
template<class T>
void selectionSort(vector<T> &arr)
{
	int n = arr.size();
	int  min;

	
	for (int i = 0; i < n - 1; i++)
	{

		
		min = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[min])
				min = j;

		
		if (min != i)
			swap(arr[min], arr[i]);
	}
}
int main() {
	vector<int> vec;
	int counter = 10;
	for (int i = 0; i < 10; i++) {
		vec.push_back(--counter);
	}
	selectionSort(vec);
	for (auto it : vec)
		cout << it << " ";
	cout << endl;


}
