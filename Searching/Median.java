import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		//code
		String str = "";
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		while(T-->0){
			int N = in.nextInt();
			int M = in.nextInt();
			int[] arr = new int[N];
			int[] brr = new int[M];
			for(int i = 0; i<N; i++)
				arr[i] = in.nextInt();
			for(int i = 0; i<M; i++)
				brr[i] = in.nextInt();
			str = str+Median(arr, brr, N, M)+"\n";
			
		}
		System.out.print(str);
	}
	static int Median(int a[], int b[], int a_length, int b_length){
		int index_a = 0;
		int index_b = 0;
		int value = 0;
		int median = 0;
		int pos = (a_length+b_length)/2;
		
		for(int i = 0; i<=pos;i++){
			if(index_a < a.length && a[index_a]<=b[index_b]){
				value = a[index_a];
				index_a++;
			}
			else if(index_b<b.length){
				value = b[index_b];
				index_b++;
			}
			if((a_length+b_length)%2==0 && i==pos-1)
				median = value;
		}
		median = (median!=0)?((int)Math.floor((double)(median+value)/2)):(value);
		return (median);
	}
}
