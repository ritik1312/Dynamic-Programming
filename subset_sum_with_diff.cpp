// Count no. of subset pairs (from partition) that has diffrence of their sum equal to 'diff' given.

#include <bits/stdc++.h>
using namespace std;

int count_subset_diff(vector<int> nums,diff)
{
    int S=0;
    for(int num:nums)
        S+=num;
    
    if((S+diff)%2==1)
        return 0;
    
    int sum = (S+diff)/2;
    int n=nums.size();
    
    int t[n+1][sum+1];
    for(int j=0;j<sum+1;j++)
        t[0][j] = 0;
    
    int count=1;
    t[0][0] = 1;
    for(int i=1;i<n+1;i++)
    {
        if(nums[i-1]==0)
            count = count<<1;   //for handling zeros
        t[i][0] = count;
    }
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(nums[i-1]<=j)
                t[i][j] = t[i-1][j-nums[i-1]]+t[i-1][j];
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}

int main(){
    int n,diff;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    
    cin >> diff;

    cout << count_subset_diff(v,diff);
    return 0;
}