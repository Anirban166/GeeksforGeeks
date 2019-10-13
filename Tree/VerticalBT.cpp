{
//Initial Template for Java
import java.util.*;
import java.lang.*;
import java.io.*;
class Node
{
    int data, hd;
    Node left, right;
    
    Node(int key)
    {
        data = key;
        left = right = null;
        hd = Integer.MAX_VALUE;
    }
}
class driver_class
{
    public static void main (String[] args)throws IOException {
        // Scanner sc = new Scanner(System.in);
        // int t = sc.nextInt();
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        
        while(t-- > 0)
        {
            HashMap<Integer, Node> m = new HashMap<Integer, Node>();
            int n = Integer.parseInt(read.readLine());
            Node root = null;
            String str[] = read.readLine().replace("  ", " ").trim().split(" ");
            int k = 0;
            while(n-- > 0)
            {
                int n1 = Integer.parseInt(str[k++]);
                int n2 = Integer.parseInt(str[k++]);
	        	char lr= str[k++].charAt(0);
				
                
                Node parent = m.get(n1);
                if (parent == null)
                {
                    parent = new Node(n1);
                    m.put(n1, parent);
                    if (root == null)
                        root = parent;
                }
                Node child = new Node(n2);
                if (lr == 'L')
                    parent.left = child;
                else
                    parent.right = child;
                m.put(n2, child);
            }
            
            BinaryTree obj = new BinaryTree();
            obj.verticalOrder(root);
            System.out.println();
        }
    }
}

}
/*This is a function problem.You only need to complete the function given below*/
//User function Template for Java
/*class Node
{
    int data;
    Node left, right;
    
    Node(int key)
    {
        data = key;
        left = right = null;
        hd = Integer.MAX_VALUE;
    }
}*/


class BinaryTree
{
    
    static void verticalOrder(Node root)
    {
        if(root==null)
          return;
      Queue<Node> q=new LinkedList<>();
      Map<Integer,List<Integer>> map=new TreeMap<>();
      ArrayList<Integer> l=new ArrayList<>();
      int hd=0;
      root.hd=hd;
      q.add(root);
      
      while(!q.isEmpty())
      {
          Node temp=q.poll();
          hd=temp.hd;
          insertIntoMultiMap(map, hd, temp.data);
          
          if(temp.left!=null)
          {
              temp.left.hd=hd-1;
              q.add(temp.left);
          }
          if(temp.right!=null)
          {
              temp.right.hd=hd+1;
              q.add(temp.right);
          }
      }
    
    List<Integer> list=new ArrayList<>();
       Set<Map.Entry<Integer, List<Integer>>> set = map.entrySet();
       
        Iterator<Map.Entry<Integer,List<Integer>>> itr=set.iterator();
        while(itr.hasNext())
        {
            Map.Entry<Integer,List<Integer>> e=itr.next();
             list=(e.getValue());
           print(list);
        }
        
    }
   static void print(List<Integer> list)
    {   
        Iterator<Integer> itr2=list.iterator();
        while(itr2.hasNext())
        {
            System.out.print(itr2.next()+" ");
        }
        
    }
    static void insertIntoMultiMap(Map<Integer,List<Integer>> map,
	                                      Integer key, Integer value) {
		if (!map.containsKey(key)) {
			map.put(key, new ArrayList<>());
		}
		map.get(key).add(value);
	}
}
