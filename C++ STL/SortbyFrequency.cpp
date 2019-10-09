#include <bits/stdc++.h>
using namespace std;
int a[1000000];
void sortByFreq(int arr[],int n);

int main() 
{
	int t;
	cin >> t;
	while(t--){  
	    int n;
	    cin >> n;
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    sortByFreq(a,n);
	    cout << endl;
	}
	return 0;
}

void sortByFreq(int arr[],int n)
{
    int hash[61]={0};
    for(int i=0;i<n;i++)
        hash[arr[i]]++;
        
    multimap<int,int,greater <int>> m;
    for(int i=0;i<61;i++)
    {
        if(hash[i]>0)
            m.insert(make_pair(hash[i],i));
    }
    multimap<int,int>::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        int j = it->first;
        while(j--)
            cout<<it->second<<" ";
    }
    
}
