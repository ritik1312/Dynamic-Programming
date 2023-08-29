#include <bits/stdc++.h>
using namespace std;

int count_subset(vector<int> &v,int sum)
{
    int n=v.size();
    int t[n+1][sum+1];

    for(int j=1;j<sum+1;j++)
        t[0][j] = 0;

    int count = 1;
    t[0][0] = 1;
    for(int i=1;i<n+1;i++)
    {
        if(v[i-1] == 0)
            count = count<<1;
        t[i][0] = count;
    }
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(v[i-1]<=j)
                t[i][j] = t[i-1][j-v[i-1]] + t[i-1][j];
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}

int main()
{
    int n,sum;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    cin >> sum;

    cout << count_subset(v,sum);
    return 0;
}