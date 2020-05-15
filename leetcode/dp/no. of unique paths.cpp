#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n,vector<int>(m,1));
        
        for(int i=1;i<n;i++)
        	for (int j=1;j<m;j++)
        		dp[i][j]=dp[i][j-1]+dp[i-1][j];
        		
        return dp[n-1][m-1];
    }
};

int main()
{
	Solution s;
	cout<<s.uniquePaths(7,3);
}
