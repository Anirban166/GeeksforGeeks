class InsertionSort
{
  
  // Function to sort an array using insertion sort
  void insert(int arr[],int i)
  {
       // Your code here
       int x = arr[i],temp,j;
       for(j=i-1;j>=0;j--)
       {
           if(arr[j]>x)
                arr[j+1]=arr[j];
            else
                break;
       }
       arr[j+1]=x;
  }

}
