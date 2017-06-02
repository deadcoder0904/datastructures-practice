#include <bits/stdc++.h>
#define max(x,y) x > y ? x : y;
using namespace std;

void printArray(int arr[], int len) {
	cout<<"The given array is : {";
	for (int i = 0; i < len; ++i)
		cout<<" "<<arr[i];
	cout<<" }"<<endl;
}

int largestSubArraySumKadane(int arr[], int len, int *start, int *end) {
	int max_so_far = 0, max_ending_here = 0, s = 0;
	for(int i = 0; i < len; ++i) {
		max_ending_here += arr[i];
		if(max_ending_here < 0) {
			max_ending_here = 0;
			s = i + 1;
		}
		else
			if(max_so_far < max_ending_here) {
				max_so_far = max_ending_here;
				*start = s;
				*end = i;
			}
	}
	return max_so_far;
}

int largestSubArraySumDP(int arr[], int len) {
	int curr_max = arr[0], max_so_far = arr[0];
	for(int i = 1; i < len; i++) {
		curr_max = max(arr[i], curr_max + arr[i]);
		max_so_far = max(max_so_far, curr_max);
	}
	return max_so_far;
}

int main()
{
	int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int len = sizeof(arr) / sizeof(arr[0]);
	printArray(arr,len);
	int start = 0, end = 0;
	cout<<"Largest SubArray Sum using Kadane's: "<<largestSubArraySumKadane(arr, len, &start, &end)<<",Start Index: "<<start<<",End Index: "<<end<<endl;
	cout<<"Largest SubArray Sum using Dynamic Programming: "<<largestSubArraySumDP(arr, len)<<endl;
	return 0;
}