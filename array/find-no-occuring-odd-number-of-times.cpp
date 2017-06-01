#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int len) {
	cout<<"The given array is : {";
	for (int i = 0; i < len; ++i)
		cout<<" "<<arr[i];
	cout<<" }"<<endl;
}

int getOccurrences(int arr[], int len) {
	int num = arr[0];
	for(int i = 1; i < len; ++i)
		num ^= arr[i];
	return num;
}

int main()
{
	int arr[] = {2, 3, 5, 4, 5, 2, 4, 3, 5, 2, 4, 4, 2};
	int len = sizeof(arr) / sizeof(arr[0]);
	printArray(arr,len);
	cout<<"Count: "<<getOccurrences(arr, len);
	return 0;
}