//function that merges three sorted arrays A,B and C as vectors using sort for vectors:

Vector mergeThree(Vector& A, Vector& B, Vector& C) 
{ 
    //Your code here
    vector<int> v;
    for(int i=0;i<A.size();i++)
        v.push_back(A[i]);
        
        for(int i=0;i<B.size();i++)
        v.push_back(B[i]);
    
        for(int i=0;i<C.size();i++)
        v.push_back(C[i]);
        
        sort(v.begin(),v.end());
        return v;
} 
