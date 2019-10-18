#include<iostream>
using namespace std;
void printExitpoint(int **arr,int m,int n)
{
    int direction = 0,i=0,j=0;
    int previ = 0,prevj=0;
    while(i<m && j<n && i>=0 && j>=0)
    {
        //cout<<" hello: "<<" "<<i<<" "<<j<<endl;
        previ = i; prevj =j;
        if(arr[i][j]==1)
        {
            direction = (direction+1)%4;
            arr[i][j] = 0;
        }
        
        if(direction==0)
            j++;
        else if(direction==1)
            i++;
        else if(direction==2)
            j--;
        else if(direction==3)
            i--;
    }
    cout<<previ<<" "<<prevj<<endl;
}
int main()
 {
	//code
    int t,N,**arr,M,i,j;
    cin>>t;
    while(t--)
    {
        cin>>M>>N;
        arr = new int*[M];
        for(i=0;i<M;i++)
            arr[i] = new int[N];
        for(i=0;i<M;i++)
            for(j=0;j<N;j++)
                cin>>arr[i][j];
        printExitpoint(arr,M,N);
    }
	return 0;
}
