#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define f(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
struct trienode{
    ll cnt;
    trienode*pointer[26];
    trienode(){
        cnt=0;
        f(i,0,26){
        pointer[i]=NULL;
    }
    }
};

void insert(trienode *root,string s){
trienode *temp=root;
for(ll i=0;i<s.length();i++){
    if(temp->pointer[s[i]-'a']==NULL){
        trienode * ne=new trienode();
        temp->pointer[s[i]-'a']=ne;
    }
    temp=temp->pointer[s[i]-'a'];
}
temp->cnt=temp->cnt+1;

}

void query(trienode *root,string s){
trienode *temp=root;
string st="";
ll i=0;
for(i=0;i<s.length();i++){
    if(temp->pointer[s[i]-'a']==NULL){
        break;
    }
    temp=temp->pointer[s[i]-'a'];
    st=st+char(s[i]);
}
if(temp->cnt==0||i!=s.length()){
    st=st+s[i];
    cout<<st<<endl;
    return ;
}
else{

    cout<<s<<" "<<temp->cnt+1<<endl;
}
}

int main(){

ll t;
cin>>t;
while(t--){
    ll n;
    cin>>n;
    string s[n];
    trienode *root=new trienode();
    string ss;
    f(i,0,n){
      cin>>s[i];
        query(root,s[i]);
        insert(root,s[i]);
         
    }
}
}
