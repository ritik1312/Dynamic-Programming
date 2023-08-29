#include <iostream>
using namespace std;

int t[100][100];

int knapsack(int val[], int wt[], int W, int n)
{
    if(t[n][W]!=-1)
        return t[n][W];
    if(n==0 || W==0)
        return t[n][W] = 0;
    if(wt[n-1]<=W)
        return t[n][W] = max(val[n-1]+knapsack(val,wt,W-wt[n-1],n-1) , knapsack(val,wt,W,n-1));
    else
        return t[n][W] = knapsack(val,wt,W,n-1);
}

int main()
{
    // Given n items, value of each item and its weight. And a bag of maxm capacity W.
    int n,W;
    int val[n],wt[n];

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> val[i];
    
    for(int i=0;i<n;i++)
        cin >> wt[i];

    cin >> W;

    // To maximise profit or cost while choosing items to fill the bag.
    // Only 1 instance of item can be either added to bag (1) or not (0)
    
    memset(t,-1,sizeof(t));

    // Recursion + Memoiztion (Top down approach)
    cout << knapsack(val,wt,W,n) << endl;

    // Bottom up approach - Tabulation
    for(int i=0;i<n;i++)
        t[i][0]=0;
    for(int j=0;J<W;j++)
        t[0][j]=0;
    // Base case initialisation

    for(int i=1; i<n+1; i++){
        for(int j=1; j<W+1; j++){
            if(wt[i-1]<=j)
                t[i][j] = max(val[i-1]+t[i-1][j-wt[i-1]], t[i-1][j]);
            else
                t[i][j] = t[i-1][j];
        }
    }
    cout << t[n][W] << "\n";
    return 0;
}