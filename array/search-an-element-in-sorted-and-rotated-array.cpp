#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int len) {
	cout<<"The given array is : {";
	for (int i = 0; i < len; ++i)
		cout<<" "<<arr[i];
	cout<<" }"<<endl;
}

int search(int arr[], int low, int high, int no) {
	if(low > high) return -1;

	int mid = (low+high)/2;
	if(no == arr[mid]) return mid;
	if(arr[low] <= arr[mid]) {
		if(no >= arr[low] && no <= arr[mid])
			return search(arr,low,mid-1,no);
		return search(arr,mid+1,high,no);
	}
	if(no >= arr[mid] && no <= arr[high])
		return search(arr,mid+1,high,no);
	return search(arr,low,mid-1,no);
}

int main()
{
	int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
	int len = sizeof(arr)/sizeof(arr[0]);
	printArray(arr,len);
	int index = search(arr,0,len-1,3);
	if(!~index)
		cout<<"Element not found"<<endl;
	else cout<<"Index: "<<index<<endl;
	return 0;
}