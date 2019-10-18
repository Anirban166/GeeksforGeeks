#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
struct trienode{
  trienode* bit[2];
ll cnt=0;
trienode(){
  bit[0]=NULL;bit[1]=NULL;
}
};

trienode* createnode(){
  struct trienode *temp=new trienode;
  return temp;
}
void insertnode(trienode * root,ll key,ll level){
for(ll i=30;i>=0;i--){
  ll p=(key>>i)&1;
    if(root->bit[p]==NULL){
      root->bit[p]=new trienode();
    
    }
    root=root->bit[p];
    root->cnt=root->cnt+1;
}
return ;
}

ll searchnode(trienode * root,ll key ,ll level){
ll ans=0;
for(ll i=30;i>=0;i--){
  ll p=((key>>i)&1);
  if(root->bit[(!p)]!=NULL &&root->bit[!p]->cnt>0){
root=root->bit[(!p)];
ans=ans+(1<<i);

  }
  else{
   root=root->bit[(p)]; 
  }
}  
return ans;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
ll t;
cin>>t;
while(t--){
  ll n;
  cin>>n;
  struct trienode * root=new trienode();
  ll a[n+1],b[n];
 f(i,0,n){
     cin>>b[i];
 }
 a[0]=0;
 f(i,1,n+1){
a[i]=a[i-1]^b[i-1];
 }


  ll maxindex=-1;
  vector<pair<ll,ll>>v;
  f(i,0,n+1){
  ll vale=a[i];
   ll j=0;
  while(vale!=0){
    vale=vale>>1;
    j++;
  }
  maxindex=max(maxindex,j);
  }
 trienode *ye=root;
f(i,0,n+1){
  insertnode(root,a[i],maxindex);
}
ll ans=0;
f(i,0,n+1){
  ll ppp=searchnode(root,a[i],maxindex);
 ans=max(ans,ppp);
}
cout<<ans<<endl;
}
}
