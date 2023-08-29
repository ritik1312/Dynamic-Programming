#include <bits/stdc++.h>
using namespace std;

int t[101][101];

bool knapsack_unbounded(int val[],int wt[],int n,int W)
{
    if(W==0)
        return t[n][W] = 1;
    if(n==0)
        return t[n][W] = 0;
    if(wt[n-1]<=W)
        return t[n][W] = knapsack_unbounded(val,weight,n,W-wt[n-1]) | knapsack_unbounded(val,weight,n-1,W);
    else
        return t[n][W] = knapsack_unbounded(val,wt,n-1,W);
}

int main()
{
    int n,W;
    cin >> n;
    int val[n],weight[n];

    for(int i=0;i<n;i++)
        cin >> val[i];

    for(int i=0;i<n;i++)
        cin >> weight[i];

    cin >> W;   // weight capacity of bag

    memset(t,-1,sizeof(t));
    
    cout << knapsack_unbounded(val,weight,n,W);

    return 0;
}