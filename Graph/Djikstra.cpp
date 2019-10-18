#include<bits/stdc++.h>
using namespace std;
void dijkstra(vector<vector<int>> , int ,int );
int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        dijkstra(g, s, V);
        cout<<endl;
       }
        return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/

int findmin(int*distance,bool* visited,int V)
{
    int minVertex = -1;
	for(int i = 0; i < V; i++){
		if(!visited[i] && (minVertex == -1 ||  distance[i] < distance[minVertex])){
			minVertex = i;
		}
	}
	return minVertex;
}

void dijkstra(vector<vector<int>> graph, int src, int V)
{
    int*distance = new int[V];
    bool*visited  = new bool[V];
    for(int i=0;i<V;i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[src] = 0;
    for(int i=0;i<V-1;i++)
    {
        int minVertex = findmin(distance,visited,V);
        visited[minVertex] = true;
        for(int j=0;j<V;j++)
        {
            if(graph[minVertex][j] != 0 && !visited[j])
            {
                int dist = distance[minVertex] + graph[minVertex][j];
                if(dist < distance[j])
                distance[j] = dist;
            }
        }
    }
    for(int i=0;i<V;i++)
    cout<<distance[i]<<" ";
   // cout<<endl;
}
  
