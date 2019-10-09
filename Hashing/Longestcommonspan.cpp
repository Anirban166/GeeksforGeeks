#include <bits/stdc++.h> 
using namespace std; 

// Returns largest common subarray with equal 
// number of 0s and 1s in both of t 
int longestCommonSum(bool arr1[], bool arr2[], int n) 
{ 
	// Find difference between the two 
	int arr[n]; 
	for (int i=0; i<n; i++) 
	arr[i] = arr1[i] - arr2[i]; 
	
	// Creates an empty hashMap hM 
	unordered_map<int, int> hM; 

	int sum = 0;	 // Initialize sum of elements 
	int max_len = 0; // Initialize result 

	// Traverse through the given array 
	for (int i = 0; i < n; i++) 
	{ 
		// Add current element to sum 
		sum += arr[i]; 

		// To handle sum=0 at last index 
		if (sum == 0) 
			max_len = i + 1; 

		// If this sum is seen before, 
		// then update max_len if required 
		if (hM.find(sum) != hM.end()) 
		max_len = max(max_len, i - hM[sum]); 
			
		else // Else put this sum in hash table 
			hM[sum] = i; 
	} 

	return max_len; 
} 

// Driver progra+m to test above function 
int main() 
{ 
	bool arr1[] = {0, 1, 0, 1, 1, 1, 1}; 
	bool arr2[] = {1, 1, 1, 1, 1, 0, 1}; 
	int n = sizeof(arr1)/sizeof(arr1[0]); 
	cout << longestCommonSum(arr1, arr2, n); 
	return 0; 
} 
