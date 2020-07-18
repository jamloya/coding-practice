/*
    keep track of increasing sum and then decreasing sum for each index 
    also need to check if we have found the first decreasing sequence
*/
#include<bits/stdc++.h>
using namespace std;

int maxSS(vector<int> &nums)
{
    vector<int> inc(nums.size(),0),dec(nums.size(),0);
    dec[0]=inc[0]=nums[0];
    int result=0,flag=0;
    for(int i=1;i<nums.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(nums[j]>nums[i])
                dec[i]=max(dec[i],inc[j]+nums[i]),flag=1;

            else if (nums[j]<nums[i] && flag)
                inc[i]=max(inc[i],dec[j]+nums[i]);
        }
        result=max({result,inc[i],dec[i]});
    }
    return result;
}

int main()
{
    vector<int> nums{4, 8, 2, 5, 6, 8} ;
    cout<<maxSS(nums);
}
