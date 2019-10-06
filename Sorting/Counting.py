def countingSort(s,n):
  l=[]
  for i in range(n):
    l.append(s[i])
    l.sort()
    s1=""
  print(s1.join(l),end=" ")
