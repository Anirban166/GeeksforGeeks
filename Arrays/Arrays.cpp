//(1) Reverse
#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int n)
{
    for(int i = 0; i < n/2; i++)
     swap(arr[i], arr[n-i-1]);
}

int main()
{
    int arr[] = {2, 8, 7, 10, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    reverse(arr, n);
    for(int i = 0; i < n; i++)
      cout << arr[i] << " ";
    return 0;
}

//(2) Reverse
#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int start, int end)
{
     int temp;
    while(start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateByd(int arr[], int d, int n)
{
    reverse(arr, 0, d-1);
    reverse(arr, d, n-1);
    reverse(arr, 0, n-1);
}

int main()
{
    int arr[] = {2, 8, 7, 10, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 3;
    rotateByd(arr, d, n);
    
    for(int i = 0; i < n; i++)
     cout << arr[i] << " ";
    return 0;
}

//(3) Leaders
#include <bits/stdc++.h> 
using namespace std; 

/* C++ Function to print leaders in an array */
void printLeaders(int arr[], int size) 
{ 
	int max_from_right = arr[size-1]; 

	/* Rightmost element is always leader */
	cout << max_from_right << " "; 
	
	for (int i = size-2; i >= 0; i--) 
	{ 
		if (max_from_right < arr[i]) 
		{		 
			max_from_right = arr[i]; 
			cout << max_from_right << " "; 
		} 
	}	 
} 

/* Driver program to test above function*/
int main() 
{ 
	int arr[] = {16, 17, 4, 3, 5, 2}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	printLeaders(arr, n); 
	return 0; 
}	 

//(4) Trapping rainwater
#include<bits/stdc++.h> 
using namespace std; 

int findWater(int arr[], int n) 
{ 
	// left[i] contains height of tallest bar to the 
	// left of i'th bar including itself 
	int left[n]; 

	// Right [i] contains height of tallest bar to 
	// the right of ith bar including itself 
	int right[n]; 

	// Initialize result 
	int water = 0; 

	// Fill left array 
	left[0] = arr[0]; 
	for (int i = 1; i < n; i++) 
	left[i] = max(left[i-1], arr[i]); 

	// Fill right array 
	right[n-1] = arr[n-1]; 
	for (int i = n-2; i >= 0; i--) 
	right[i] = max(right[i+1], arr[i]); 

	// Calculate the accumulated water element by element 
	// consider the amount of water on i'th bar, the 
	// amount of water accumulated on this particular 
	// bar will be equal to min(left[i], right[i]) - arr[i] . 
	for (int i = 0; i < n; i++) 
	water += min(left[i],right[i]) - arr[i]; 

	return water; 
} 

// Driver program 
int main() 
{ 
	int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "Maximum water that can be accumulated is "
		<< findWater(arr, n); 
	return 0; 
}

//(5) Stock buy and sell
#include <bits/stdc++.h> 
using namespace std; 

// solution structure 
class Interval { 
public: 
	int buy; 
	int sell; 
}; 

// This function finds the buy sell 
// schedule for maximum profit 
void stockBuySell(int price[], int n) 
{ 
	// Prices must be given for at least two days 
	if (n == 1) 
		return; 

	int count = 0; // count of solution pairs 

	// solution vector 
	Interval sol[n / 2 + 1]; 

	// Traverse through given price array 
	int i = 0; 
	while (i < n - 1) { 
		// Find Local Minima. Note that the limit is (n-2) as we are 
		// comparing present element to the next element. 
		while ((i < n - 1) && (price[i + 1] <= price[i])) 
			i++; 

		// If we reached the end, break 
		// as no further solution possible 
		if (i == n - 1) 
			break; 

		// Store the index of minima 
		sol[count].buy = i++; 

		// Find Local Maxima. Note that the limit is (n-1) as we are 
		// comparing to previous element 
		while ((i < n) && (price[i] >= price[i - 1])) 
			i++; 

		// Store the index of maxima 
		sol[count].sell = i - 1; 

		// Increment count of buy/sell pairs 
		count++; 
	} 

	// print solution 
	if (count == 0) 
		cout << "There is no day when buying"
			<< " the stock will make profitn"; 
	else { 
		for (int i = 0; i < count; i++) 
			cout << "Buy on day: " << sol[i].buy 
				<< "\t Sell on day: " << sol[i].sell << endl; 
	} 

	return; 
} 

// Driver code 
int main() 
{ 
	// stock prices on consecutive days 
	int price[] = { 100, 180, 260, 310, 40, 535, 695 }; 
	int n = sizeof(price) / sizeof(price[0]); 

	// fucntion call 
	stockBuySell(price, n); 

	return 0; 
} 


