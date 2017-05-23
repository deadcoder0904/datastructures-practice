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

int deleteSorted(int arr[], int len, int value) {
	int pos = binarySearch(arr,0,len-1,value);
	if(!~pos)
		return len;
	while(pos < len) {
		arr[pos] = arr[pos+1];
		pos++;
	}
	return len - 1;
}

int main()
{
	int arr[10] = {12,278,356,420};
	int len = 4;
	printArray(arr,len);
	int newLen = deleteSorted(arr, len,12);
	if(newLen == len)
		cout<<"Element 12 not found"<<endl;
	else cout<<"Element 12 deleted successfully"<<endl;
	printArray(arr,newLen);
	return 0;
}