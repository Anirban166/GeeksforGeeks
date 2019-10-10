	//Iterative Function which returns number of nodes :
	static int GetCountIterative(Node head)
    {
       Node t = head;
       int count = 0;
       while (null != t) 
       {
           t = t.next;
           count++;
       }
       return count;
    }
	
	//Recursive Function which returns number of nodes :
	static int GetCountRecursive(Node head)
    {
      if(head == null) 
      return 0;
      else 
      {
       return 1 + GetCountRecursive(head.next);
      }
    }
