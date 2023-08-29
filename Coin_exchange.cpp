#include <bits/stdc++.h>

using namespace std;

// max no. of ways to achieve coins sum with the given coins
// similar to count subset sum 
int coinSum(int coin[], int n, int sum)
{
    int t[n+1][sum+1];

    // if no coins then 0 ways
    for(int j=0;j<sum+1;j++)
        t[0][j] = 0;
    
    // if sum=0 then 1 way as coin 0 is not present
    for(int i=0;i<n+1;i++)
        t[i][0] = 1;
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(coin[i-1]<=j)
                t[i][j] = t[i][j-coin[i-1]] + t[i-1][j];
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}

// min no. of coins to needed to achieve coin sum
int coinSum2(int coin[],int n,int sum)
{
    int t[n+1][sum+1];

    // if no coins present then min coins needed to achieve sum > 0 = INFINITY
    for(int j=0;j<sum+1;j++)
        t[0][j] = INT_MAX-1;
    
    // but if sum = 0, then min no. of coins needed = 0
    for(int i=0;i<n+1;i++)
        t[i][0] = 0;

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(coin[i-1]<=j)
                t[i][j] = min(1 + t[i][j-coin[i-1]],t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}

int main()
{
    int n;
    cin >> n;
    int coin[n];
    int sum;
    for(int i=0;i<n;i++)
        cin >> coin[i];
    cin >> sum;

    cout << coinSum(coin,n,sum) << endl;
    cout << coinSum2(coin,n,sum);
    return 0;
}