import java.util.*;
class Node
{
    int data;
    Node left, right;
    Node(int key)
    {
        data = key;
        left = right = null;
    }
}
class FixingBST
{
    static int flag = 1;
    static int c = 0;
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int n = sc.nextInt();
            int m = n;
            if(n == 0)
            {
                System.out.println(0);
                continue;
            }
            Node root = null;
            Node temp = null;
             for(int i=0;i<n;i++){
                int a=sc.nextInt();
                int a1=sc.nextInt();
                char lr=sc.next().charAt(0);
                if(i==0){
                    root=new Node(a);
                    temp = new Node(a);
                    switch(lr){
                        case 'L':root.left=new Node(a1);
                                 temp.left = new Node(a1);
                        break;
                        case 'R':root.right=new Node(a1);
                                 temp.right=new Node(a1);
                        break;
                    }
                }
                else{
                    insert(root,a,a1,lr);
                    insert(temp, a, a1, lr);
                }
            }
            flag = 1;
            c = 0;
            GfG gfg = new GfG();
            root = gfg.correctBST(root);
            
            inorder(temp, root);
            if(c+1 == m)
            System.out.println(flag);
            else
            System.out.println("0");
            
        }
    }
    
    public static void insert(Node root, int a, int a1, char lr)
    {
         if(root==null){
            return;
        }
        if(root.data==a){
            switch(lr){
                case 'L':root.left=new Node(a1);
                break;
                case 'R':root.right=new Node(a1);
                break;
            }
            return;
        }
        insert(root.left,a,a1,lr);
        insert(root.right,a,a1,lr);
    }
    
    public static void inorder(Node temp, Node root)
    {
        	if(flag==0){
		      return;
	}
	if(temp==null && root== null)
		return;
	if(root==null){
		flag=0;
		return;
	}
	if(temp==null){
		flag=0;
		return;
	}
	if(temp.data==root.data){
	    c++;
	}
	inorder(temp.left,root.left);
	inorder(temp.right,root.right);
    }
}

}
/*This is a function problem.You only need to complete the function given below*/
/*
class Node
{
    int data;
    Node left, right;
    Node(int key)
    {
        data = key;
        left = right = null;
    }
}
*/
class GfG
{
    
    public void findList(Node root,ArrayList<Integer> al)
    {
        if(root==null)
        return;
        findList(root.left,al);
        al.add(root.data);
        findList(root.right,al);
    }
    
    public Node findingParentNode(Node root,int d)
    {
        if(root==null)
        return null;
        if(root.left!=null && root.left.data==d)
        return root;
        if(root.right!=null && root.right.data==d)
        return root;
        Node a = findingParentNode(root.left,d);
        Node b = findingParentNode(root.right,d);
        if(a!=null)
        return a;
        else if(b!=null)
        return b;
        else
        return null;
    }
    
   public Node correctBST(Node root)
   {
       if(root==null || (root.left==null && root.right==null))
       return root;
       ArrayList<Integer> al=new ArrayList<Integer>();
       findList(root,al);
       int f1=-1,f2=-1;
       for(int i=0;i<al.size();i++)
       {
           if(al.get(i)!=root.data)
           {
           if(i==0 && al.get(i)>al.get(i+1))
           {
               f1=al.get(i);
               al.remove(i);
           }
           else if(i!=0 && i!=al.size()-1 &&(al.get(i)>al.get(i+1) || al.get(i)<al.get(i-1)))
           {
               if(f1==-1)
               f1=al.get(i);
               else
               f2=al.get(i);
               al.remove(i);
           }
           else if(i==al.size()-1 && al.get(i)<al.get(i-1))
           {
               f2=al.get(i);
               al.remove(i);
           }
           }
       }
       if(f1==-1 && f2==-1)
       return root;
       Node a = findingParentNode(root,f1);
       Node b = findingParentNode(root,f2);
       Node c=null,d=null;

       if(a.left!=null && a.left.data==f1)
       c=a.left;
       else
       c=a.right;
       
       if(b.left!=null && b.left.data==f2)
       d=b.left;
       else
       d=b.right;
       
       int a1=c.data;
       c.data=d.data;
       d.data=a1;
       
       return root;
   }
}
