#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int len) {
	cout<<"The given array is : {";
	for (int i = 0; i < len; ++i)
		cout<<" "<<arr[i];
	cout<<" }"<<endl;
}

void hasArrayTwoCandidatesUsingSorting(int arr[],int len, int sum) {
	int i = 0, j = len - 1;
	while(i < j)
		if(arr[i] + arr[j] == sum)
			break;
		else 
			if(arr[i] + arr[j] < sum)
				i++;
			else j--;
	if(i < j)
		cout<<"Pairs "<<arr[i]<<" and "<<arr[j]<<" equals to "<<sum<<endl;
	else cout<<"No Candidates Found"<<endl;
}

void hasArrayTwoCandidatesUsingHashMap(int arr[], int len, int sum) {
	unordered_set<int> seen;
	for(int i = 0; i < len; i++)
		if(seen.find(arr[i]) == seen.end())
			seen.insert(sum-arr[i]);
		else {
			cout<<"Pairs "<<arr[i]<<" and "<<sum-arr[i]<<" equals to "<<sum<<endl;
			return;
		}
	cout<<"No Candidates Found"<<endl;	
}

int main()
{
	int arr[5] = {4,2,3,1,5};
	printArray(arr,5);
	sort(arr,arr+5);
	hasArrayTwoCandidatesUsingSorting(arr,5,6);
	int arr1[5] = {4,2,3,1,5};
	printArray(arr1,5);
	hasArrayTwoCandidatesUsingHashMap(arr1,5,6);
	return 0;
}