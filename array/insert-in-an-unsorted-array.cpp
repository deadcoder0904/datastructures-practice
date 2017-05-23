#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int len) {
	cout<<"The given array is : {";
	for (int i = 0; i < len; ++i)
		cout<<" "<<arr[i];
	cout<<" }"<<endl;
}

int insertUnsorted(int arr[], int len, int currentSize, int value) {
	if(currentSize >= len)
		return currentSize;
	arr[currentSize] = value;
	return currentSize + 1;
}

int main()
{
	int arr[10] = {278,12,356,420};
	int len = sizeof(arr) / sizeof(arr[0]);
	printArray(arr,4);
	int newLen = insertUnsorted(arr, len,4,977);
	if(newLen == len)
		cout<<"Cannot insert as array is completely filled"<<endl;
	else 	
		cout<<"Element 977 inserted at position "<<newLen<<" successfully"<<endl;
	printArray(arr,5);
	return 0;
}