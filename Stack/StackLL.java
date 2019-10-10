class StackNode
{
    int data;
    StackNode next;
    StackNode(int a)
    {
       data = a;
       next = null;
    }
}

class MyStack {
    // Note that top is by default null
    // in Java
    StackNode top;
    void push(int a) {
        // Add your code here
        StackNode temp = top;
        StackNode sn = new StackNode(a);
        sn.next = top;
        top = sn;
    }
    int pop() {
        // Add your code here
        if(top == null)
            return -1;
        else{
            StackNode temp = top;
            int x = top.data;
            top = top.next;
            temp.next = null;
            return x;
        }
    }
}
