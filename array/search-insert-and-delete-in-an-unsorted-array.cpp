#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int len) {
	cout<<"[";
	for (int i = 0; i < len; ++i)
		cout<<" "<<arr[i];
	cout<<" ]"<<endl<<endl;
}

void searchUnsorted(int arr[], int len, int value) {
	for(int i = 0; i < len; i++)
		if(arr[i] == value) {
			cout<<"Element found at position "<<(i + 1)<<endl;
			return;
		}
		cout<<"Element not found"<<endl;
}

void insertUnsorted(int arr[], int len, int n, int value) {
	if(n >= len) {
		cout<<"Cannot insert as array is completely filled"<<endl;
		return;
	}	
	arr[n] = value;
	cout<<"Element "<<value<<" inserted at position "<<n<<" successfully"<<endl;
}

void deleteUnsorted(int arr[], int len, int value) {
	int i;
	for(i = 0; i < len; i++)
		if(arr[i] == value)
			break;
	if(i == len) {
			cout<<"Element not found"<<endl;
			return;
	}
	cout<<"Element "<<value<<" deleted successfully"<<endl;
	while(i < len) {
		arr[i] = arr[i+1];
		i++;
	}
}

int main()
{
	int arr[10] = {278,12,356,420};
	int len = sizeof(arr) / sizeof(arr[0]);
	printArray(arr,len);
	searchUnsorted(arr, len,52);
	printArray(arr,len);
	searchUnsorted(arr, len,356);
	printArray(arr,len);
	insertUnsorted(arr, len,4,977);
	printArray(arr,len);
	insertUnsorted(arr, len,6,27);
	printArray(arr,len);
	deleteUnsorted(arr, len,12);
	printArray(arr,len);
	deleteUnsorted(arr, len,121);
	printArray(arr,len);
	return 0;
}