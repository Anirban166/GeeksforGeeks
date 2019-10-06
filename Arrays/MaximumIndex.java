class MaxDifference
{
    
    // Function to find maximum difference of j-1
    // arr[]: input array
    // n: size of array
    static int maxIndexDiff(int arr[], int n) { 
        
        int diff = 0;
        for(int i =0;i<n;i++){
        	
        	int j=-1;
        	for(j = n-1;j>i;j--){
        		if(arr[j]>=arr[i])
        			break;
        	}
        	if(i==j)
        		continue;
        	diff = (j-i>diff)?j-i:diff;
        }
        return diff;
}
}
