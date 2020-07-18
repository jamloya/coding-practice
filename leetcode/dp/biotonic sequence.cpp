#include<bits/stdc++.h>

using namespace std;

int lis(vector<int> &nums)
{
    vector<int> dp(nums.size(),1);
    vector<int> dp1(nums.size(),1);
    for(int i=1;i<nums.size();i++)
        for(int j=0;j<i;j++)
            if(nums[i]>nums[j])
                dp[i]=max(dp[i],dp[j]+1);
    for(int i=nums.size()-2;i>=0;i--)
        for(int j=nums.size()-1;j>i;j--)
            if(nums[j]>nums[i])
                dp1[i]=max(dp1[i],dp1[j]+1);
                
    int result=0;
    for(int i=0;i<nums.size();i++)
        result=max(result,dp[i]+dp1[i]-1);
    return result;
}

int main()
{
 Solution s;
 cout<<s.();
}

