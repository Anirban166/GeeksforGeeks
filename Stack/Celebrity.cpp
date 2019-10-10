#include<bits/stdc++.h>
using namespace std;
#define MAX 501
int getId(int M[MAX][MAX],int n);
int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;
    }
}


/*This is a function problem.You only need to complete the function given below*/
// The task is to complete this function
// M[][]: input matrix
// n: size of matrix (n*n)
int getId(int M[MAX][MAX], int n)
{

  vector<int> v;
  int i, j, cnt;
  for (j = 0; j < n; j++){
    cnt = 0;
    for (i = 0; i < n; i++)
      if (M[i][j] == 1) cnt++;

    if (cnt >= n-1)
      v.push_back(j);
  }
  return (v.size() == 1) ? v[0] : -1;
}
