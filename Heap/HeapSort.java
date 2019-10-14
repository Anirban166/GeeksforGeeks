import java.util.*;
class Heap_Sort
{
    void printArray(int arr[],int n)
    {
        //int n = arr.length;
        for (int i=0; i<n; ++i)
            System.out.print(arr[i]+" ");
        System.out.println();
    }
    public static void main(String args[])
    {
        Scanner sc  = new Scanner(System.in);
        Heap_Sort hs = new Heap_Sort();
        int arr[] = new int[1000000];
        int T = sc.nextInt();
        while(T>0)
        {
            int n = sc.nextInt();
            for(int i=0;i<n;i++)
                arr[i] = sc.nextInt();
            hs.heapSort(arr,n);
            hs.printArray(arr,n);
            T--;
        }
    }
    public void heapSort(int arr[], int n)
    {
        GfG g = new GfG();
        g.buildHeap(arr, n);
        for (int i=n-1; i>=0; i--)
        {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            g.heapify(arr, i, 0);
        }
    }
}

}
/*This is a function problem.You only need to complete the function given below*/
class GfG
{
 private void swap(int[] a, int x, int y){
        if(a[x] != a[y]){
            a[x] ^= a[y];
            a[y] ^= a[x];
            a[x] ^= a[y];
        }
    }
    void buildHeap(int a[], int n){
        int start = (n-2)/2;
        for(int i=start; i>=0; i--)
            heapify(a, n, i);
    }
    void heapify(int a[], int n, int i){
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if(l < n && a[largest] < a[l]) largest = l;
        if(r < n && a[largest] < a[r]) largest = r;
        if(largest != i){
            swap(a, i, largest);
            heapify(a, n, largest);
        }
    }
 }
 
 
