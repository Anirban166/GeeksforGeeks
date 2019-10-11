#include<bits/stdc++.h>
using namespace std;
class LRUCache
{
public:
    LRUCache(int );
 
    int get(int );
 
    void set(int , int );
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    LRUCache *l  = new LRUCache(n);
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        string a;
        cin>>a;
        if(a=="SET")
        {
            int aa,bb;
            cin>>aa>>bb;
            l->set(aa,bb);
        }else if(a=="GET")
        {
            int aa;
            cin>>aa;
            cout<<l->get(aa)<<" ";
        }
    }
    cout<<endl;
    }
}


/*This is a function problem.You only need to complete the function given below*/
/*The structure of the class is as follows 
class LRUCache
{
public:
    LRUCache(int );
    int get(int );
    void set(int , int );
};*/
//---------------------------------------------------------
int maxSize;
list<pair<int,int>> dq;
unordered_map<int, list<pair<int,int>> :: iterator> ma; 
LRUCache::LRUCache(int N)
{maxSize = N;
dq.clear();
ma.clear();
}
void LRUCache::set(int x, int y) 
{
     if(ma.find(x) == ma.end())
    {
       if(dq.size() == maxSize)
       {
           int Lx = dq.back().first;
           int Ly = dq.back().second;
           dq.pop_back();
           dq.push_front({x,y});
           ma.erase(Lx);
           ma[x] =dq.begin();
       }
       else{
           dq.push_front({x,y});
      
            ma[x] = dq.begin();
       }
    }
    else{
        auto it = ma.find(x);
        dq.erase(it->second);
        dq.push_front({x,y});
   
        ma[x]=dq.begin();
    }
}
int LRUCache::get(int x)
{
    if(ma.find(x) == ma.end())
    {
        return -1;
    }
    auto it = ma.find(x);
    int d  = (*(it->second)).second;
    dq.erase(it->second);
    dq.push_front({x,d});
    ma[x] = dq.begin();
    return d;
}
