class Test 
{ 
	// Simple binary search algorithm 
	static int binarySearch(int arr[], int l, int r, int x) 
	{ 
		if (r>=l) 
		{ 
			int mid = l + (r - l)/2; 
			if (arr[mid] == x) 
				return mid; 
			if (arr[mid] > x) 
				return binarySearch(arr, l, mid-1, x); 
			return binarySearch(arr, mid+1, r, x); 
		} 
		return -1; 
	} 
	
	// Method takes an infinite size array and a key to be 
	// searched and returns its position if found else -1. 
	// We don't know size of arr[] and we can assume size to be 
	// infinite in this function. 
	// NOTE THAT THIS FUNCTION ASSUMES arr[] TO BE OF INFINITE SIZE 
	// THEREFORE, THERE IS NO INDEX OUT OF BOUND CHECKING 
	static int findPos(int arr[],int key) 
	{ 
		int l = 0, h = 1; 
		int val = arr[0]; 

		// Find h to do binary search 
		while (val < key) 
		{ 
			l = h;	 // store previous high 
			//check that 2*h doesn't exceeds array 
			//length to prevent ArrayOutOfBoundException 
			if(2*h < arr.length-1) 
			h = 2*h;			 
			else
			h = arr.length-1; 
			
			val = arr[h]; // update new val 
		} 

		// at this point we have updated low 
		// and high indices, thus use binary 
		// search between them 
		return binarySearch(arr, l, h, key); 
	} 

	// Driver method to test the above function 
	public static void main(String[] args) 
	{ 
		int arr[] = new int[]{3, 5, 7, 9, 10, 90, 
							100, 130, 140, 160, 170}; 
		int ans = findPos(arr,10); 
		
		if (ans==-1) 
			System.out.println("Element not found"); 
		else
			System.out.println("Element found at index " + ans); 
	} 
} 
