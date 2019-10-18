import java.lang.*;
import java.io.*;
import java.util.*;

class SegmentTree 
{

	static int [] segmentT = null;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer sr = new StringTokenizer(br.readLine());
		int T = Integer.parseInt(sr.nextToken());
		while(T>0){
			sr = new StringTokenizer(br.readLine());
		    int N =Integer.parseInt(sr.nextToken());
		    int M = Integer.parseInt(sr.nextToken());
		    
		    int [] ar = new int[N];
		    sr = new StringTokenizer(br.readLine());
		    for(int i =0;i<N;i++) {
		    	ar[i] = Integer.parseInt(sr.nextToken()); 
		    }
		    
		    int x = (int)(Math.ceil(Math.log(N)/Math.log(2)));
		    	int size= 2*(int) Math.pow(2, x)-1;
		    segmentT = new int[size];
		    
		    fillSegmentTree(ar,0,N-1,0);
		    
		    while(M>0) {
		    	sr = new StringTokenizer(br.readLine());
		    	
		    	String q = sr.nextToken();
		    	int u = Integer.parseInt(sr.nextToken());
		    	int v = Integer.parseInt(sr.nextToken());
		    	if(q.equals("U")) {
		    		if(u>-1&&u<N){
			    	    int diff = v-ar[u];
			    	    ar[u] = v;
		    		update(u,diff,0,N-1,0);}
		    	}else {
		    		int s = sum(u,v,0,N-1,0);
		    		System.out.println(s);
		    	}
		    	
		    	M--;
		    }
		    
		    T--;
		}
	}

	private static int fillSegmentTree(int[] ar, int l, int r, int i) {
		
		if(i>=segmentT.length)
			return 0;
		if(l==r) {
			return segmentT[i] = ar[l];
			
		}
		int mid = (l+r)/2;
		return segmentT[i] =  fillSegmentTree(ar,l,mid,2*i+1)+ fillSegmentTree(ar,mid+1,r,2*i+2);
	}

	private static void update(int u, int v,int l, int r, int i) {
		if(i>=segmentT.length)
			return ;
		
		if(u>=l&&u<=r) {
			segmentT[i]+=v;
			int mid = (l+r)/2;
			update(u,v,l,mid,2*i+1);
			update(u,v,mid+1,r,2*i+2);
		}
		
	}

	private static int sum(int u, int v, int l, int r, int i) {

		if(i>=segmentT.length)
			return 0;
		
		if(l>=u&&r<=v) {
			return segmentT[i];
		}else if(u>r||l>v){
			return 0;
		}
		
		int mid = (l+r)/2;
		return sum(u,v,l,mid,2*i+1)+sum(u,v,mid+1,r,2*i+2);
	}

}  
