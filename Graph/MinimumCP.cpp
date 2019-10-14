#include<bits/stdc++.h>
using namespace std;
bool safe(int i,int j,int n)
{
    if(i<0||j<0||i>=n||j>=n)
    return false;
    return true;
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int i,j,mat[n][n];
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<n;j++)
	        cin>>mat[i][j];
	    }
	    vector<int> v[n*n+2];
	    int k=1,d=n*n,s=1;
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<n;j++)
	        {
	            
	                if(safe(i,j+1,n))
	                v[k].push_back(k+1);
	                
	                if(safe(i,j-1,n))
	                v[k].push_back(k-1);
	                
	                if(i<n-1&&safe(i+1,j,n))
	                v[k].push_back(k+n);
	                
	                if(i>0&&safe(i-1,j,n))
	                v[k].push_back(k-n);
	            k++;
	        }
	    }
	    int distance[n*n+2];
	    for(i=0;i<n*n+2;i++)
	    distance[i]=INT_MAX;
	    set<pair<int ,int>> st;
	   
	   st.insert(make_pair(mat[0][0],1));
	   distance[s]=mat[0][0];
	    
	    
	    while(!st.empty())
	    {
	        auto temp = *st.begin(); 
            st.erase(st.begin()); 
	        for(auto it=v[temp.second].begin();it!=v[temp.second].end();++it)
	        {
	            int dis=distance[temp.second]+mat[(*it-1)/n][(*it-1)%n];
	           if(distance[(*it)]>dis)
	            {
	                if(distance[(*it)]!=INT_MAX)
	                    st.erase(st.find(pair<int,int>(distance[(*it)],(*it))));
	               distance[(*it)]=dis;
	               st.insert(make_pair(dis,*it));
	            }
	        }
	    }
	    cout<<distance[d]<<endl;
	}
	return 0;
}
