#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void dfs(int a[51][51],bool vis[51][51],int i,int j,int n,int m)
{
    if(i<0||i>=n||j<0||j>=m||a[i][j]==0||vis[i][j]==true)
    {
        return;
    }
    vis[i][j]=true;
    dfs(a,vis,i,j+1,n,m);
    dfs(a,vis,i,j-1,n,m);
    dfs(a,vis,i+1,j,n,m);
    dfs(a,vis,i-1,j,n,m);
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m,i,j;
	    string str;
	    cin>>n>>m;
	    int a[51][51];
	    for(i=0;i<n;i++)
	    {
	        cin>>str;
	        for(j=0;j<str.size();j++)
	        {
	            if(str[j]=='X')
	            {
	                a[i][j]=1;
	            }
	            else
	            {
	                a[i][j]=0;
	            }
	        }
	    }
	    bool vis[51][51];
	    int count=0;
	    memset(vis,false,sizeof(vis));
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<m;j++)
	        {
	            if(a[i][j]==1&&vis[i][j]==false)
	            {
	                dfs(a,vis,i,j,n,m);
	                count++;
	            }
	        }
	    }
	    cout<<count;
	    cout<<endl;
	}
	return 0;
}
