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
	int x[] = {2,7,10};
	int y[] = {5,8,12,14};
	int m = sizeof(x)/sizeof(x[0]);
	int n = sizeof(y)/sizeof(y[0]);
	cout<<"Displaying x "<<endl;
	printArray(x,m);
	cout<<"Displaying y "<<endl;
	printArray(y,n);
	cout<<"Displaying Merged Array "<<endl;
	printArray(merge(x,y,m,n),m+n);
	return 0;
}