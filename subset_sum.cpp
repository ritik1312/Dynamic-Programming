#include <bits/stdc++.h>
using namespace std;

bool is_subset_sum(vector<int> &v,int target)
{
    bool t[n+1][target+1];
    
    for(int i=0;i<n+1;i++)
        t[i][0]=true;
    for(int j=1;j<target+1;j++)
        t[0][j]=false;

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<target+1;j++)
        {
            if(v[i-1]<=j)
                t[i][j] = t[i-1][j-v[i-1]] | t[i-1][j];
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][target];
}

int main()
{
    // Given an array of non negative integers. Find if there exists a subset of array with the given sum 'target'
    int n;
    int target;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    
    cin >> target;
    cout << is_subset_sum(v,target);

    return 0; 
}