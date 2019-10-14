#include<bits/stdc++.h>
using namespace std;
int t,r,c;
int arr[100][100],pre[100][100];
bool vis[100][100];

bool check()
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]==1)
            return true;
            
        }
    }
    return false;
}
bool isnotequal()
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]!=pre[i][j])
            return true;
        }
    }
    return false;
}

int main()
{
    
cin>>t;
while(t--)
{
cin>>r>>c;
memset(vis,false,sizeof(vis));
int count=0;
for(int i=0;i<r;i++)
{
    for(int j=0;j<c;j++)
    {
        cin>>arr[i][j];
    }
}


  while(isnotequal() && check())
  {
      
      for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
           pre[i][j]=arr[i][j];
           
        }
    }
    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
           if(arr[i][j]==2)
           vis[i][j]=true;
           
        }
    }
      
      
      count++;
      for(int i=0;i<r;i++)
      {
          for(int j=0;j<c;j++)
          {
              if(arr[i][j]==2 && vis[i][j])
              {
                  if(i+1<r && arr[i+1][j]==1)
                  {
                      arr[i+1][j]=2;
                  }
                  if(i-1>=0 && arr[i-1][j]==1)
                  {
                      arr[i-1][j]=2;
                  }
                  if(j+1<c && arr[i][j+1]==1)
                  {
                      arr[i][j+1]=2;
                  }
                  if(j-1>=0 && arr[i][j-1]==1)
                  {
                      arr[i][j-1]=2;
                  }
              }
          }
      }   
  }
 
if(check())
{
    cout<<-1<<endl;
}
else 
{
    cout<<count<<endl;
}
}

}
//-----------------------------------OR:
#include<bits/stdc++.h>
using namespace std;
class Point
{
	public:
	int x;
	int y;
	int time;
	Point()
	{
		x=0;
		y=0;
		time=0;
	}
	Point(int f,int s,int t)
	{
		x=f;
		y=s;
		time=t;
	}
	bool safe(int x,int y,int m,int n)
	{
		if(x>=0 && x<m && y>=0 && y<n)
		return true;
		else
		return false;
	}
	int BFS(int arr[][100],int m,int n)
	{queue<Point> q;
		int ftime=0;
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(arr[i][j]==2)
				{
					
					
					Point p(i,j,0);
					q.push(p);
				}
			}
		}
		while(!q.empty())
		{
			Point temp=q.front();
			int x=temp.x;
			int y=temp.y;
			int t=temp.time;
			ftime=max(ftime,t);
			if(safe(x-1,y,m,n) && arr[x-1][y]==1)
			{
				Point pu;
				pu.x=x-1;
				pu.y=y;
				pu.time=t+1;
				arr[x-1][y]=2;
				q.push(pu);
				//cout<<"pushed"<<endl;
			}
			if(safe(x+1,y,m,n) && arr[x+1][y]==1)
			{
				Point pu;
				pu.x=x+1;
				pu.y=y;
				pu.time=t+1;
				q.push(pu);
				arr[x+1][y]=2;;
				//cout<<"pushed"<<endl;
			}
			if(safe(x,y+1,m,n) && arr[x][y+1]==1)
			{
				Point pu;
				pu.x=x;
				pu.y=y+1;
				pu.time=t+1;
				q.push(pu);
				arr[x][y+1]=2;;
				//cout<<"pushed"<<endl;
			}
			if(safe(x,y-1,m,n) && arr[x][y-1]==1)
			{
				Point pu;
				pu.x=x;
				pu.y=y-1;
				pu.time=t+1;
				q.push(pu);
				arr[x][y-1]=2;
				//cout<<"pushed"<<endl;
			}
			q.pop();
			//cout<<"popped"<<endl;
}
		return ftime;
	}
};
	int main()
	{
		int t;
		cin>>t;
		while(t--)
		{
		int m,n;
		cin>>m>>n;
		int arr[100][100];
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
			cin>>arr[i][j];
			}
		}
		Point p;
		int ans=p.BFS(arr,m,n);
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				//cout<<arr[i][j]<<" ";
				if(arr[i][j]==1)
				{
					ans=-1;
					break;
				}
				//ft=max(ft,arr[i][j]);
			}
			//cout<<endl;
		}
		cout<<ans<<endl;
	}
		return 0;
	}
