#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int len) {
	cout<<"The given array is : {";
	for (int i = 0; i < len; ++i)
		cout<<" "<<arr[i];
	cout<<" }"<<endl;
}

int insertSorted(int arr[], int len, int value) {
	int i;
	for(i = len - 1; i >= 0 && arr[i] > value; i--)
		arr[i+1] = arr[i];
	arr[i+1] = value;
	cout<<"Element "<<value<<" inserted at position "<<(i+2)<<" successfully"<<endl;
	return len + 1;
}

int main()
{
	int arr[10] = {12,278,356,420};
	int len = 4;
	printArray(arr,len);
	len = insertSorted(arr,len,4);
	printArray(arr,len);
	return 0;
}