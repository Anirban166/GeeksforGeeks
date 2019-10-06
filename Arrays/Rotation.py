def reverse(arr, first, last):
    total  = last - first + 1
    for x in range(total//2):
        arr[first+x], arr[last-x] = arr[last-x], arr[first+x]

def rotateArr(A,D,N):
    reverse(A, 0, D-1)
    reverse(A, D, N-1)
    reverse(A, 0, N-1)
