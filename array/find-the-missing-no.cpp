#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int len) {
	cout<<"The given array is : {";
	for (int i = 0; i < len; ++i)
		cout<<" "<<arr[i];
	cout<<" }"<<endl;
}

int missingNoUsingSum(int arr[], int n) {
	int sum = 0;
	int total = n*(n+1)/2;
	for(int i = 0; i < n; i++)
		sum += arr[i];
	return total - sum;
}

int missingNoUsingXOR(int arr[], int n) {
	int xor1 = arr[0];
	for (int i = 1; i < n; ++i)
		xor1 ^= arr[i];
	int xor2 = 1;
	for (int i = 2; i <= n; ++i)
		xor2 ^= i;
	return xor1 ^ xor2;
}

int main()
{
	int arr[] = {1,2,4,5,6};
	printArray(arr,5);
	cout<<"Missing Number Using Sum: "<<missingNoUsingSum(arr,6)<<endl;
	cout<<"Missing Number Using XOR: "<<missingNoUsingXOR(arr,6)<<endl;
	return 0;
}