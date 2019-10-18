#include<iostream>
#include<queue>
#include<map>
using namespace std;

bool valid(int x,int y,int m,int n)
{
    if (x>=0 && x<m && y>=0 && y<n) return true;
    return false;
}

int main()
{
    int t,m,n,x,y;
    cin>>t;
    while (t--)
    {
        cin>>m>>n;
        int arr[m][n];
        for (int i=0; i<m; i++) 
        {
            for (int j=0; j<n; j++) cin>>arr[i][j];
        }
        cin>>x>>y;
        if (arr[x][y]==0 || arr[0][0]==0) {   cout<<"-1\n";   continue;  }
        queue<pair<int,int> > q;
        q.push(make_pair(0,0));
        map<pair<int,int>,int> mp;
        int ans = -1;
        mp[make_pair(0,0)] = 0;
        while (q.empty()==false)
        {
            pair<int,int> temp = q.front();
            q.pop();
            int a=temp.first,b=temp.second;
            if (a==x && b==y)  {    ans=mp[temp];    break;  } 
            if ((valid(a-1,b,m,n)) && arr[a-1][b]==1)
            { 
               mp[pair<int,int>(a-1,b)] = mp[temp]+1;
               q.push(make_pair(a-1,b));  
            }
            if ((valid(a+1,b,m,n)) && arr[a+1][b]==1)
            { 
               mp[pair<int,int>(a+1,b)] = mp[temp]+1;
               q.push(make_pair(a+1,b));  
            }
            if ((valid(a,b-1,m,n)) && arr[a][b-1]==1)
            { 
               mp[pair<int,int>(a,b-1)] = mp[temp]+1;
               q.push(make_pair(a,b-1));  
            }
            if ((valid(a,b+1,m,n)) && arr[a][b+1]==1)
            { 
               mp[pair<int,int>(a,b+1)] = mp[temp]+1;
               q.push(make_pair(a,b+1));  
            }
            arr[a][b]=0;
        }
        cout<<ans<<"\n";
    }
	return 0;
}
