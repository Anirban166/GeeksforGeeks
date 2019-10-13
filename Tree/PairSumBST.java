import java.util.*;
import java.io.*;
import java.lang.*;
class Node {
    int data;
    Node left, right;
    Node(int data) {
        this.data = data;
        left = right = null;
    }
}
class PairSum {
    static Node insert(Node node, int data) {
        if (node == null) return new Node(data);
        if (node.data > data) node.left = insert(node.left, data);
        if (node.data < data) node.right = insert(node.right, data);
        return node;
    }
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int temp = 0;
            Node root = null;
            for (int i = 0; i < n; i++) {
                temp = sc.nextInt();
                root = insert(root, temp);
            }
            temp = sc.nextInt();
            if (new GFG().findPair(root, temp) == true)
                System.out.println("1");
            else
                System.out.println("0");
        }
    }
}

}
/*This is a function problem.You only need to complete the function given below*/
// User function Template for Java
/*/class Node
{
    int data;
    Node left, right;
    Node(int data)
    {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}*/
class GFG {
 public static boolean findP(Node root,int sum,HashSet<Integer> hs)
    {
        if(root==null)
        return false;
        if(hs.contains(sum-root.data))
        return true;
        hs.add(root.data);
        return findP(root.left,sum,hs)||findP(root.right,sum,hs);
    }
    static boolean findPair(Node root, int sum) {
        HashSet<Integer> hs=new HashSet<Integer>();
        return findP(root,sum,hs);
    }
}
