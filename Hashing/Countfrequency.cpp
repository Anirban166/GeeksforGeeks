import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GFG {
	public static void main (String[] args) throws IOException{
		BufferedReader inp=new BufferedReader(new InputStreamReader(System.in));
		String s[] = inp.readLine().split(" ");
		int n = Integer.parseInt(s[0]);
		int w = Integer.parseInt(s[1]);
		int l = Integer.parseInt(s[2]);
		int h[] = new int[n];
		int r[] = new int[n];
		int index=0;
		int n1=n;
		while(n-->0)
		{
		    String s1[] = inp.readLine().split(" ");
		    h[index] = Integer.parseInt(s1[0]);
		    r[index] = Integer.parseInt(s1[1]);
		    index++;
		}
		long mon=0;
		
		while(mon>=0)
		{
		  //  System.out.println(mon);
		    long sum=0;
		    long height=0;
		    for(long i=0;i<n1;i=i+1){
		    height=h[i]+r[i]*mon;
		    if(height>=l)
		    {
		        sum+=height;
		      //  System.out.println(sum);
		    }}
		    if(sum>=w){
		    System.out.println(mon);
		    break;
		    }
		    mon=mon+1;
		}
	}
}
