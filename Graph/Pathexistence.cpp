#include <iostream>
#include <queue>
using namespace std;

typedef pair<int,int> ipair;

int main() 
{

	int test;
	cin>>test;
	while(test--){
	int N;
	cin>>N;
	int i,j;
	int sr,sc,der,dec;
	int graph[N][N];
	bool vis[N][N];

	queue<ipair> pq;
	for(int i=0;i<N;i++){
	    for(int j=0;j<N;j++){
	        cin>>graph[i][j];
	        vis[i][j]=false;
	    }
	}
	for(int i=0;i<N;i++){
	    for(int j=0;j<N;j++){
	        if(graph[i][j]==1){
	            sr=i;
	            sc=j;
	        }
	        if(graph[i][j]==2){
	            der=i;
	            dec=j;
	        }
	       
	    }
	}
	int dr[4]={-1,1,0,0};
	int dc[4]={0,0,-1,1};
	
	pq.push(make_pair(sr,sc));
	while(!pq.empty()){
	    int r=pq.front().first;
	    int c=pq.front().second;
	    pq.pop();
	    vis[r][c]=true;
	    for(int i=0;i<4;i++){
	        int rr=r+dr[i];
	        int cc=c+dc[i];
	        if(rr<0 or cc<0)continue;
	        if(rr>=N or cc>=N)continue;
	        if(graph[rr][cc] and !vis[rr][cc]){
	            pq.push(make_pair(rr,cc));
	        }
	    }
	}
	cout<<vis[der][dec]<<"\n";
	}

	return 0;
}
