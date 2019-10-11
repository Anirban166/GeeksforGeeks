def GenerateBinary(n):
    for i in range(1,n+1):
        j=bin(i)
        print(j[2:],end=" ")
