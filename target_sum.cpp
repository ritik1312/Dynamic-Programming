#include <bits.stdc++.h>
using namespace std;


// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.


int findTargetSumWays(vector<int>& nums, int target) 

{
    target = abs(target);
    int S=0;
    int zeros=0;
    for(int num:nums)
        S+=num;
    
    // to partition array into 2 subsets with sums 
    // S1(+ sign nums) and S2(-sign nums) such that S1-S2 = target
    // S1+S2 = S and S1-S2=target
    // need to find count of subset sum S1 or S2.
    if((S+target)%2==1)
        return 0;
    
    int sum = (S+target)/2;
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
    int n;
    int target;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    
    cin >> target;
    cout << findTargetSumWays(v,target);
    return 0;
}