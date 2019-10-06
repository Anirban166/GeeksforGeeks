//(1) Reverse
import java.io.*;
class GFG {
    
    static void reverse(int arr[], int n)
    {
        for(int i = 0; i < n/2; i++)
        {
            int temp = arr[i];
            arr[i] = arr[n-i-1];
            arr[n-i-1] = temp;
        }
    }
	public static void main (String[] args) {
		int arr[] = new int[]{2, 8, 7, 10, 5};
		int n = arr.length;
		
		reverse(arr, n);
		for(int i = 0; i < n; i++)
		  System.out.print(arr[i] + " ");
	}
}

//(2) Rotate
import java.io.*;
import java.util.*;
import java.lang.*;

class GFG {
    
    static void reverse(int arr[], int start, int end)
    {
        int temp = 0;
        while(start < end)
        {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    static void rotateByd(int arr[], int d, int n)
    {
        reverse(arr, 0, d-1);
        reverse(arr, d, n-1);
        reverse(arr, 0, n-1);
    }
	public static void main (String[] args) 
	{
	    int arr[] = new int[]{2, 8, 7, 10, 5};
	    int n = arr.length;
	    int d = 3;
	    
	    rotateByd(arr, d, n);
	    for(int i = 0; i < n; i++)
	     System.out.print(arr[i] + " ");
	}
}

//(3) Leaders 
class LeadersInArray 
{ 
	/* Java Function to print leaders in an array */
	void printLeaders(int arr[], int size) 
	{ 
		int max_from_right = arr[size-1]; 

		/* Rightmost element is always leader */
		System.out.print(max_from_right + " "); 
	
		for (int i = size-2; i >= 0; i--) 
		{ 
			if (max_from_right < arr[i]) 
			{		 
			max_from_right = arr[i]; 
			System.out.print(max_from_right + " "); 
			} 
		}	 
	} 

	/* Driver program to test above functions */
	public static void main(String[] args) 
	{ 
		LeadersInArray lead = new LeadersInArray(); 
		int arr[] = new int[]{16, 17, 4, 3, 5, 2}; 
		int n = arr.length; 
		lead.printLeaders(arr, n); 
	} 
} 

//(4) Trapping water
// Java program to find maximum amount of water that can 
// be trapped within given set of bars. 

class Test 
{ 
	static int arr[] = new int[]{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; 
	
	// Method for maximum amount of water 
	static int findWater(int n) 
	{ 
		// left[i] contains height of tallest bar to the 
		// left of i'th bar including itself 
		int left[] = new int[n]; 
	
		// Right [i] contains height of tallest bar to 
		// the right of ith bar including itself 
		int right[] = new int[n]; 
	
		// Initialize result 
		int water = 0; 
	
		// Fill left array 
		left[0] = arr[0]; 
		for (int i = 1; i < n; i++) 
		left[i] = Math.max(left[i-1], arr[i]); 
	
		// Fill right array 
		right[n-1] = arr[n-1]; 
		for (int i = n-2; i >= 0; i--) 
		right[i] = Math.max(right[i+1], arr[i]); 
	
		// Calculate the accumulated water element by element 
		// consider the amount of water on i'th bar, the 
		// amount of water accumulated on this particular 
		// bar will be equal to min(left[i], right[i]) - arr[i] . 
		for (int i = 0; i < n; i++) 
		water += Math.min(left[i],right[i]) - arr[i]; 
	
		return water; 
	} 
	
	// Driver method to test the above function 
	public static void main(String[] args) 
	{ 
		
		System.out.println("Maximum water that can be accumulated is " + 
										findWater(arr.length)); 
	} 
} 

//(5) Stock buy and sell
import java.util.ArrayList; 

// Solution structure 
class Interval { 
	int buy, sell; 
} 

class StockBuySell { 
	// This function finds the buy sell schedule for maximum profit 
	void stockBuySell(int price[], int n) 
	{ 
		// Prices must be given for at least two days 
		if (n == 1) 
			return; 

		int count = 0; 

		// solution array 
		ArrayList<Interval> sol = new ArrayList<Interval>(); 

		// Traverse through given price array 
		int i = 0; 
		while (i < n - 1) { 
			// Find Local Minima. Note that the limit is (n-2) as we are 
			// comparing present element to the next element. 
			while ((i < n - 1) && (price[i + 1] <= price[i])) 
				i++; 

			// If we reached the end, break as no further solution possible 
			if (i == n - 1) 
				break; 

			Interval e = new Interval(); 
			e.buy = i++; 
			// Store the index of minima 

			// Find Local Maxima. Note that the limit is (n-1) as we are 
			// comparing to previous element 
			while ((i < n) && (price[i] >= price[i - 1])) 
				i++; 

			// Store the index of maxima 
			e.sell = i - 1; 
			sol.add(e); 

			// Increment number of buy/sell 
			count++; 
		} 

		// print solution 
		if (count == 0) 
			System.out.println("There is no day when buying the stock "
							+ "will make profit"); 
		else
			for (int j = 0; j < count; j++) 
				System.out.println("Buy on day: " + sol.get(j).buy 
								+ "	 "
								+ "Sell on day : " + sol.get(j).sell); 

		return; 
	} 

	public static void main(String args[]) 
	{ 
		StockBuySell stock = new StockBuySell(); 

		// stock prices on consecutive days 
		int price[] = { 100, 180, 260, 310, 40, 535, 695 }; 
		int n = price.length; 

		// fucntion call 
		stock.stockBuySell(price, n); 
	} 
} 

