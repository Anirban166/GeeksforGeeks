/*package whatever //do not write package name here */
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
 {
	static String fn(String str) 
      { 
            if(str.equals(""))
            return "";
            
            int i,j,k;
            int n=str.length();
            
            Stack<Character> s=new Stack<>();
	    boolean flag=false;
	    
        for(i=0;i<n;i++)
	    s.push(str.charAt(i));
	    str="";
	    char c=s.peek();
	    flag=false;
	    s.pop();
	    int key=0; //to check if we need to check the answer again
	    while(!s.isEmpty())    
	    {
	        //cout<<st.top()<<" ";
	        if(s.peek()==c)
	        {
	            flag=true;
	            key=1;
	        }
	        else if(s.peek()!=c  )
	        {
	            if(flag==false)
	            str+=c;
	            c=s.peek();
	            flag=false;
	        }
	        s.pop();
	    }
	    if(flag==false)
	    str+=c;
	    StringBuilder ss=new StringBuilder(str);
	    ss=ss.reverse();
	    str=ss.toString();
	    
	    if(key==1)
	    str=fn(str);
	    return str;
      }
	
	public static void main (String[] args) 
	 {
	 //code
	 Scanner sc=new Scanner(System.in); 
     int test = sc.nextInt(); 
	 sc.nextLine();
	 while(test-->0){
	    String str=sc.nextLine(); 

	    System.out.println(fn(str));

	 }

	 }
}
