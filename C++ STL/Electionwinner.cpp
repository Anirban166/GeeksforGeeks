void winner(string arr[],int n)
{
    map<string,int> umap;
    string tmp;
    int max = INT_MIN;
    for(int i=0;i<n;i++)
        umap[arr[i]]++;
    for(auto x:umap) {
        if(x.second>max) {
            max = x.second;
            tmp = x.first;
        }
    }
    cout<<tmp<<" "<<max;
}

//Given an array of names (consisting of lowercase characters) of candidates in an election. 
//A candidate name in array represents a vote casted to the candidate. 
//Print the name of candidate that received Max votes. If there is tie, print lexicographically smaller name.
