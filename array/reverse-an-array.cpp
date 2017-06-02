#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int len) {
	cout<<"The given array is : {";
	for (int i = 0; i < len; ++i)
		cout<<" "<<arr[i];
	cout<<" }"<<endl;
}

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void reverseIterative(int arr[], int len) {
	for(int start = 0, end = len-1; start < end; ++start, --end)
		swap(&arr[start],&arr[end]);
}

void reverseRecursive(int arr[], int start, int end) {
	if(start >= end) return;

	swap(&arr[start],&arr[end]);
	return reverseRecursive(arr,start+1,end-1);
}

int main()
{
	int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
	int len = sizeof(arr)/sizeof(arr[0]);
	printArray(arr,len);
	reverseIterative(arr,len);
	printArray(arr,len);
	reverseRecursive(arr,0,len-1);
	printArray(arr,len);
	return 0;
}