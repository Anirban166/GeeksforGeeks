#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const pii delimiter={-5,-5};   //level delimiter used to differentiate between levels
const int row_move[8]= {-1, -1, -2, -2, 1, 1, 2, 2},
          column_move[8]= {-2,  2, -1,  1, 2,-2, 1,-1};

bool isvalid(pii p,int n){
    return (p.first>=0 && p.first<n && p.second>=0 && p.second<n);
}

int main()
 {
	int t;cin>>t;
	while(t--){
	    int n; cin>>n;
	    bool visited[n][n]={false};
	    queue<pii> q;
	    int s1,s2,d1,d2,moves=0; cin>>s1>>s2>>d1>>d2;
	    pii s={s1-1,s2-1},d={d1-1,d2-1};
	    q.push(s); q.push(delimiter); visited[s1-1][s2-1]=true;
	    while(!q.empty()){
	        pii a=q.front(); q.pop();  //inspect next element
	        if(a==d) break;            //if target reached, break
	        if(a==delimiter){          //if level delimiter reached
	            if(q.empty()){moves=-1;break;}  //if no more elements left
	            moves++;      //otherwise, adjust their moves value
	            q.push(delimiter);  //set next level delimiter
	            continue;
	        }
	        for(int i=0;i<8;i++){  //generate all positions knight can go
	            pii x={a.first+row_move[i],a.second+column_move[i]};
	            //check if knight can go the position or if its already visited
	            if(isvalid(x,n) && !visited[x.first][x.second]){
	                q.push(x);
	                visited[x.first][x.second]=true;
	            }
	        }
	    }
	    cout<<moves<<"\n";
	}
	return 0;
}
