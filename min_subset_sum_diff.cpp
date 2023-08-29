#include <bits.stdc++.h>

using namespace std;

int minDiff(int arr[], int n)  { 
    // Your code goes here
    int S=0,sum;
    
   
    for(int i=0;i<n;i++)
        S+=arr[i];
    
    // S1+S2 = S and find min |S1 - S2| = min |S-2*S1|
    // S1<S/2 and S2>S/2. 
    // We need to find all possible S1 values and determine min|S1-2*S1| for them
    
    sum = S/2;
    
    bool t[n+1][sum+1];
    for(int i=0;i<=n;i++)
        t[i][0]=true;
    for(int j=1;j<sum+1;j++)
        t[0][j] = false;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum+1;j++)
        {
            if(arr[i-1]<=j)
                t[i][j] = t[i-1][j-arr[i-1]] | t[i-1][j];
            else
                t[i][j] = t[i-1][j];
        }
    }
    
    int min_diff = 100001;
    for(int j=0;j<=sum;j++){
        if(t[n][j]){
            if(S-2*j < min_diff)
                min_diff = S-2*j;
        }
    }
    return min_diff;
}

int main()
{
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    return 0;
}