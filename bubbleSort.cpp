// C++ program to find the element
// occurring odd number of times
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
template<class T> void bubbleSort(vector<T> &arr) {
	int size = arr.size();
	bool alarm ;
	for (int i = 0; i < size - 1; i++) {
		alarm = false;
		int newSize = size - i - 1;
		for (int j = 0; j < newSize ; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				alarm = true;
	
			}
		
		}

		if (!alarm) break;
	}
}

int main() {
	vector<int> vec;
	int counter = 10;
	for (int i = 0; i < 10; i++) {
		vec.push_back(--counter);
	}
	bubbleSort(vec);
	for (auto it : vec)
		cout << it << " ";
	cout << endl;


}
