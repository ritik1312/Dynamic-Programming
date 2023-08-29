#include <bits/stdc++.h>
using namespace std;

int cutRod(int price[], int n) {
    //unbounde knapsack problem
    int t[n+1][n+1];    // here weight is same as array size
    for(int i=0;i<=n;i++)
        t[i][0] = t[0][i] = 0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i<=j)
                t[i][j] = max(price[i-1] + t[i][j-i] , t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][n];
}

int main()
{
    int n;
    cin n;
    int price[n];
    for(int i=0;i<n;i++)
        cin>>price[i] ;
    
    cout << cutRod(price,n);
    return 0;
}