#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int len) {
	cout<<"The given array is : {";
	for (int i = 0; i < len; ++i)
		cout<<" "<<arr[i];
	cout<<" }"<<endl;
}

int binarySearch(int arr[], int low, int high, int value) {
	if(high < low) 
		return -1;
	int mid = (low + high) / 2;
	if(arr[mid] == value)
		return mid;
	if(value < arr[mid])
		return binarySearch(arr,low, mid - 1, value);
	return binarySearch(arr,mid + 1, high, value);
}

int main()
{
	int arr[10] = {12,278,356,420};
	int len = sizeof(arr) / sizeof(arr[0]);
	printArray(arr,4);
	int search = binarySearch(arr,0,3,356);	
	if(!~search)
		cout<<"Element 356 not found"<<endl;
	else cout<<"Element 356 found at positon "<<(search + 1)<<endl;
	return 0;
}