#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int len) {
	cout<<"The given array is : {";
	for (int i = 0; i < len; ++i)
		cout<<" "<<arr[i];
	cout<<" }"<<endl;
}

int searchUnsorted(int arr[], int len, int value) {
	for(int i = 0; i < len; i++)
		if(arr[i] == value)
			return i;
	return -1;
}

int main()
{
	int arr[10] = {278,12,356,420};
	int len = sizeof(arr) / sizeof(arr[0]);
	printArray(arr,4);
	int pos = searchUnsorted(arr, len,52);
	if(!~pos)
		cout<<"Element 52 not found"<<endl;
	else cout<<"Element 52 found at position "<<(pos + 1)<<endl;
	return 0;
}