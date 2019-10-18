#include<iostream>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
	    int k;
	    cin >> k;
	    string s;
	    cin >> s;
	    int sum=0;
	    int level=-1;
	    int n=s.length();
	    for(int i=0;i<n;i++){
	        if(s[i]=='('){
	            ++level;
	            continue;
	        }
	        else if(s[i]==')'){
	            --level;
	            continue;
	        }
	        if(level==k){
	            int x=s[i]-48;
	            ++i;
	            while(i<n && s[i]!='(' && s[i]!=')'){
	                x=x*10+(s[i]-48);
	                ++i;
	            }
	            sum+=x;
	            --i;
	        }
	    }
	    cout << sum << endl;
	}
	return 0;
}
