#include <bits/stdc++.h> 
using namespace std; 

void swap(int* a, int* b) 
{ 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
} 

int partition(int arr[], int left, int right) 
{ 
	int x = arr[right], i = left; 
	for (int j = left; j <= right - 1; j++) { 
		if (arr[j] <= x) { 
			swap(&arr[i], &arr[j]); 
			i++; 
		} 
	} 
	swap(&arr[i], &arr[right]); 
	return i; 
} 

int kthSmallest(int arr[], int left, int right, int k) 
{ 
	if (k > 0 && k <= right - left + 1) 
    { 

		int pos = partition(arr, left, right); 

		if (pos - left == k - 1) 
			return arr[pos]; 
		if (pos - left > k - 1)  
			return kthSmallest(arr, left, pos - 1, k); 

		return kthSmallest(arr, pos + 1, right, k - pos + left - 1); 
	} 

	// If k is more than number of elements in array 
	return INT_MAX; 
} 

int main() 
{ 
	int arr[] = { 12, 3, 5, 7, 4, 19, 26 }; 
	int n = sizeof(arr) / sizeof(arr[0]), k = 3; 
	cout << "K'th smallest element is " << kthSmallest(arr, 0, n - 1, k); 
	return 0; 
} 
