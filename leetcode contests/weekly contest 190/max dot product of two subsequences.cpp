#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    //dp approach
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(),vector<int>(nums2.size()));
        for(int i=0;i<nums1.size();i++)
            for(int j=0;j<nums2.size();j++)
            {
                dp[i][j] = nums1[i]*nums2[j];
                dp[i][j] += i && j ? max(0,dp[i-1][j-1]) : 0;
                //cout<<dp[i][j]<<endl;
                dp[i][j]=max({dp[i][j],i?dp[i-1][j]:INT_MIN,j ? dp[i][j-1]:INT_MIN});
                
            }
            return dp[nums1.size()-1][nums2.size()-1];
    }
};

int main()
{
 Solution s;
 cout<<s.();
}

