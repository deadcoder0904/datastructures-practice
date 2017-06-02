#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int len) {
	cout<<"The given array is : {";
	for (int i = 0; i < len; ++i)
		cout<<" "<<arr[i];
	cout<<" }"<<endl;
}

int *merge(int x[], int y[], int m, int n) {
	int *arr=new int[m+n], i=0, j=0, k=0;
	while(i<m && j<n)
		if(x[i] <= y[j])
			arr[k++] = x[i++];
		else arr[k++] = y[j++];
	while(i<m)
		arr[k++] = x[i++];
	while(j<n)
		arr[k++] = y[j++];
	return arr;
}

int main()
{
	int x[] = {1, 12, 15, 26, 38};
	int y[] = {2, 13, 17, 30, 45};
	int m = sizeof(x)/sizeof(x[0]);
	int n = sizeof(y)/sizeof(y[0]);
	cout<<"Displaying x "<<endl;
	printArray(x,m);
	cout<<"Displaying y "<<endl;
	printArray(y,n);
	cout<<"Displaying Merged Array "<<endl;
	int *arr = new int[m+n];
	arr = merge(x,y,m,n);
	printArray(arr,m+n);
	int avg = (m+n)/2;
	if((m+n)&1)
		cout<<"Median: "<<arr[avg];
	else cout<<"Median: "<<(arr[avg]+arr[avg-1])/2;
	return 0;
}