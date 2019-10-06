def reverse(arr, first_index, last_index):
  for x in range(first_index, (first_index + last_index + 1)//2):
    temp = arr[x]
    index = last_index - 1 - x + first_index
    arr[x] = arr[index]
    arr[index] = temp

def pairs(N, K):
  l = 0
  while N > l:
    f = l
    l = l + min(N-l, K)
    yield (f, l)

def reverseInGroups(A,N,K):
  for first_index, last_index in pairs(N, K):
    reverse(A, first_index, last_index)
  return A
