// C++ program to find the element
// occurring odd number of times
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



template<class T> 
void insertinoSort(vector<T> &arr) {
	int size = arr.size();
	T key;
	int j = 0;

	for (int i = 1; i < size; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}

}

int main() {
	vector<int> vec;
	int counter = 10;
	for (int i = 0; i < 10; i++) {
		vec.push_back(--counter);
	}
	insertinoSort(vec);
	for (auto it : vec)
		cout << it << " ";
	cout << endl;


}
