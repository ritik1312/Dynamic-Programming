#include <iostream>
using namespace std;

//Matrix Chain Multiplication

// Memoization
int t[101][101];
int solve(int arr[],int i,int j)
{
    if(i>=j)
        return 0;
    if(t[i][j]!=-1)
        return t[i][j];
    int temp;
    int min_cost = INT_MAX;
    for(int k=i;k<j;k++)
    {
        temp = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        min_cost = min(temp,min_cost);
    }
    return t[i][j] = min_cost;
}


int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];

    memset(t,-1,sizeof(t));
    cout << solve(arr,1,N-1) << endl;
    return 0;
}