import java.util.*;
import java.lang.*;
class Node{
	int data;
	Node left,right;
	Node(int d){
		data=d;
		left=null;
		right=null;
	}
}
class K{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0)
		{
			int n = sc.nextInt();
			Node root = new Node(sc.nextInt());
			for(int i=0;i<n-1;i++)
				insert(root,sc.nextInt());
			int k=sc.nextInt();
			GfG g = new GfG();
			System.out.println(g.maxDiff(root,k));
		}
	}
	public static Node insert(Node root,int n){
		if(root==null)
			return new Node(n);
		if(n<root.data)
			root.left=insert(root.left,n);
		if(n>root.data)
			root.right=insert(root.right,n);
		return root;
	}
}
}
/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
Node is as follows:
class Node{
	int data;
	Node left,right;
	Node(int d){
		data=d;
		left=null;
		right=null;
	}
}*/
class GfG
{
public static int maxDiff(Node root, int k)
{
if(root==null)
return 1000;
if(root.left==null && root.right==null)
return (int)Math.abs(k-root.data);
int a=(int)Math.min(maxDiff(root.left,k),maxDiff(root.right,k));
int b=(int)Math.abs(k-root.data);
return Math.min(a,b);
}
}
