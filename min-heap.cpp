#include <bits/stdc++.h> 
using namespace std; 
int arr[] = { 12, 3, 5, 7, 4, 19, 26 }; 
int n = sizeof(arr) / sizeof(arr[0]); 


int main() 
{
	priority_queue <int, vector<int>, greater<int> > pq;          //min-heap

	for(int i=0;i<n;i++)
	{
		pq.push(arr[i]);
	}
	int k=3;
	while (pq.empty() == false && k>1)
	{
		pq.pop();
		k--;
	}
	cout<<"K-th smallest element "<<pq.top();
} 
