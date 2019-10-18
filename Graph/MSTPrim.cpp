#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V,int E,vector<vector<int> > graph);
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int V,E;
        cin>>V>>E;
        vector< vector<int> > graph(V,vector<int>(V,INT_MAX));
        while(E--)
        {
            int u,v,w;
            cin>>u>>v>>w;
            u--,v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }
        cout<<spanningTree(V,E,graph)<<endl;
    }
    return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX
int min_vertex(int key[], bool vis[], int V){
    int min=INT_MAX, vertex;
    for(int i=0;i<V;i++){
        if(vis[i]==false && key[i]<min){
            vertex=i;
            min=key[i];
        }
    }
    return vertex;
}
int spanningTree(int V,int E,vector<vector<int> > graph){
    int parent[V];
    bool vis[V];
    int key[V];
    for(int i=0;i<V;i++) key[i]=INT_MAX,vis[i]=false;
    key[0]=0;
    parent[0]=-1;
    for(int i=0;i<V-1;i++){
        int u=min_vertex(key,vis,V);
        vis[u]=true;
        for(int v=0;v<V;v++){
            if(graph[u][v]!=INT_MAX && vis[v]==false && graph[u][v]<key[v]){
                key[v]=graph[u][v];
                parent[v]=u;
            }
        }
    }
    int weight=0;
    for(int i=1;i<V;i++){
        weight+=graph[i][parent[i]];
    }
    return weight;
}
