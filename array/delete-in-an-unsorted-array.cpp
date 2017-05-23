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

int deleteUnsorted(int arr[], int len, int value) {
	int pos = searchUnsorted(arr,len,value);
	if(pos == -1)
		return len;
	while(pos < len) {
		arr[pos] = arr[pos+1];
		pos++;
	}
	return len-1;
}

int main()
{
	int arr[10] = {278,12,356,420};
	int len = sizeof(arr) / sizeof(arr[0]);
	printArray(arr,4);
	int newLen = deleteUnsorted(arr, len,12);
	if(newLen == len)	
		cout<<"Element 12 not found"<<endl;
	else cout<<"Element 12 deleted successfully"<<endl;
	printArray(arr,3);
	return 0;
}