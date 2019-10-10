void QueueStack :: push(int x) {
    q1.push(x);
}
/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
    if (q1.empty())
        return -1;
    int *back = &q1.back();
    
    while (!q1.empty() && &q1.front() != back) {
        q1.push(q1.front());
        q1.pop();
    }
    int res = q1.front();
    q1.pop();
    return res;
}
