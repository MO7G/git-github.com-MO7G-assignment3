// C++ program to find the element
// occurring odd number of times
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
template<class T>
void merge(vector<T>& arr, int beg, int mid, int end)
{
	int i, j, k;
	int n1 = mid - beg + 1;
	int n2 = end - mid;

	vector<T> LeftArray(n1), RightArray(n2); //temporary arrays  

	/* copy data to temp arrays */
	for (int i = 0; i < n1; i++)
		LeftArray[i] = arr[beg + i];
	for (int j = 0; j < n2; j++)
		RightArray[j] = arr[mid + 1 + j];

	i = 0; /* initial index of first sub-array */
	j = 0; /* initial index of second sub-array */
	k = beg;  /* initial index of merged sub-array */

	while (i < n1 && j < n2)
	{
		if (LeftArray[i] <= RightArray[j])
		{
			arr[k] = LeftArray[i];
			i++;
		}
		else
		{
			arr[k] = RightArray[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = LeftArray[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = RightArray[j];
		j++;
		k++;
	}
}
template<class T>
void mergeSort(vector<T> &arr, int beg, int end)
{

	if (beg < end)
	{
		int mid = (beg + end) / 2;
		mergeSort(arr, beg, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, beg, mid, end);
	}
}

int main() {
	vector<int> vec;
	int counter = 10;
	for (int i = 0; i < 10; i++) {
		vec.push_back(--counter);
	}
	mergeSort(vec,0,9);
	for (auto it : vec)
		cout << it << " ";
	cout << endl;


}
