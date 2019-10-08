def main():
    T=int(input())
    while(T>0):
        n,m=map(int,input().split())
        mat=[[0 for j in range(m)] for i in range(n)]
        line1=[int(x) for x in input().strip().split()]
        
       
        k=0
        for i in range(n):
            for j in range (m):
                mat[i][j]=line1[k]
                k+=1
       
        k=0
        
        n,m=m,n
        spirallyTraverse(m,n,mat)
        
        
        print()
        
            
        
        T-=1
if __name__=="__main__":
    main()

''' ---------------------------------------------------------------------- '''

def spirallyTraverse(n, m, a) : 
    i = 0
    j = 0
    k = 2*n + 2*(m-2)
    c = 0
    
    if m == 0 or n == 0:
        return
    
    if m == 1 or n == 1:
        for i in a:
            for j in i:
                print(j, end = " ")
        return
    
    while c < k:
        print(a[i][j], end = " ")
        if i == n-1 and j > 0:
            j -= 1
        elif i<=j and j < m-1:
            j += 1
        elif j == m-1 and i < n-1:
            i += 1
        else:
            i -= 1
        c += 1

    spirallyTraverse(n-2, m-2, [a[i][1:-1] for i in range(1, n-1)]) 
