#include <bits/stdc++.h> 
using namespace std; 
int arr[] = { 12, 3, 5, 7, 4, 19, 26 }; 
int n = sizeof(arr) / sizeof(arr[0]); 

int partition(int arr[], int start, int end) 
{ 
	 int pivot = arr[end];
    int pIndex = start;
    for (int i = start; i < end; i++)
    {
        if (arr[i] <= pivot) //reverse the comparision sign for kth largest element
        {                  //i.e, if(a[i] >= pivot)
            swap(arr[pIndex], arr[i]);
            pIndex++;
        }
    }
    swap(arr[pIndex], arr[end]);
    return pIndex;
} 

int kthSmallest(int arr[], int start, int end, int k) 
{ 
	if (k > 0 && k<=n && start<=end ) 
    { 

		int pos = partition(arr, start, end); 
		if (pos == k-1)
			return arr[pos]; 
		if (pos-1 == k-1)
			return arr[pos-1]; 
		if (pos> k)  
			return kthSmallest(arr, start, pos - 1, k); 

		return kthSmallest(arr, pos + 1, end, k); 
	} 

	// If k is more than number of elements in array 
	return INT_MAX; 
} 

int main() 
{
	int k=3;
	cout <<"k-th smallest element is " << kthSmallest(arr, 0, n - 1, k); 
	return 0; 
} 
