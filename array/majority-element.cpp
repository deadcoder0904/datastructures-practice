#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int len) {
	cout<<"The given array is : {";
	for (int i = 0; i < len; ++i)
		cout<<" "<<arr[i];
	cout<<" }"<<endl;
}

int majorityElementUsingMap(int arr[], int len) {
	map<int,int> freq;
	for(int i = 0; i < len; i++)
		if(!freq[arr[i]])
			freq[arr[i]] = 1;
		else freq[arr[i]]++;
	for(int i = 0; i < len; i++)
		if(freq[arr[i]] > len/2)
			return arr[i];
	return 0;
}

void printMajorityUsingMap(int arr[], int len) {
	int cand = majorityElementUsingMap(arr,9);
	if(cand)
		cout<<"Majority Element Using Map  : "<<cand<<endl;
	else cout<<"No Majority Element Using Map"<<endl;	
}

int findCandidate(int arr[], int len) {
	int major_i = 0, count = 1;
	for(int i = 1; i < len; i++) {
		if(arr[major_i] == arr[i])
			count++;
		else count--;
		if(count == 0) {
			major_i = i;
			count = 1;
		}
	}
	return arr[major_i];
}

bool isMajor(int arr[], int len, int cand) {
	int count = 0;
	for(int i = 0; i < len; i++)
		if(arr[i] == cand)
			count++;
	if(count > len/2)
		return 1;
	return 0;	
}

void printMajorityUsingMoore(int arr[], int len) {
	int cand = findCandidate(arr,len);
	if(cand)
		cout<<"Majority Element Using Moore's Voting Algorithm  : "<<cand<<endl;
	else cout<<"No Majority Element Using Moore's Voting Algorithm"<<endl;
}

int main()
{
	int arr[9] = {3,3,4,2,4,4,2,4,4};
	printArray(arr,9);
	printMajorityUsingMap(arr,9);
	printMajorityUsingMoore(arr,9);
	return 0;
}