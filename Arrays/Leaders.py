def leaders(A,N):
    _leaders = []
    for x in range(N-1, -1, -1):
        if x == N-1 or A[x] >= _leaders[-1]:
            _leaders.append(A[x])
    return reversed(_leaders)
