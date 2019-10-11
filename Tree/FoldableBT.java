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
class Foldable_Tree
{
     public static void insert(Node root,int a,int a1,char lr)
    {
        if(root==null)
        {
            return;
        }
        if(root.data==a)
        {
            switch(lr)
            {
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
    
     public static void main (String[] args) 
    {
         Scanner sc=new Scanner(System.in);
          int t=sc.nextInt();
          
           while(t-->0){
            int n=sc.nextInt();
            if(n==0)
            {
                System.out.println(0);
                continue;
            }
            Node root = null;
            for(int i=0;i<n;i++)
            {
                int a=sc.nextInt();
                int a1=sc.nextInt();
                char lr=sc.next().charAt(0);
                if(i==0)
                {
                    root=new Node(a);
                    switch(lr)
                    {
                        case 'L':root.left=new Node(a1);
                        break;
                        case 'R':root.right=new Node(a1);
                        break;
                    }
                }
                else
                {
                    insert(root,a,a1,lr);
                }
            }
            
            GFG gfg = new GFG();
            boolean val = gfg.isFoldable(root);
            if(val == true)
              System.out.println("Yes");
            else
              System.out.println("No");
           }
    }
    
    public static void mirror(Node node)
    {
        if(node == null)
           return;
        else
        {
            Node temp;
            
            mirror(node.left);
            mirror(node.right);
            
            temp = node.left;
            node.left = node.right;
            node.right = temp;
        }
        
    }
}
}
/*This is a function problem.You only need to complete the function given below*/
/*
node class of the binary tree
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
class GFG
{
    static Foldable_Tree obj = new Foldable_Tree();
    
    public static boolean foldable(Node r1,Node r2)
    {
        if(r1==null && r2==null)
        return true;
        if(r1==null || r2==null)
        return false;
        return foldable(r1.left,r2.right)&&foldable(r1.right,r2.left);
    }
    
    public static boolean isFoldable(Node root)
    {
        if(root==null)
        return true;
       return foldable(root.left,root.right);
    }
}
