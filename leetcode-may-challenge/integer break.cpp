#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
  		vector<int> dp(n+1);
		  dp[0]=0;
		  if(n==1)
		  	dp[1]=0;
		  if(n==2)
		  	dp[2]=1;
		  if (n==3)
		  	dp[3]=2;
		  if(n==4)
		  	dp[4]=4
		  for(int i=4;i<=n;i++)
		  	dp[i]=3*max(i-3,dp[i-3]);
			  
		return dp[n];   
    }
};

int main()
{
	Solution s;
	cout<<s.integerBreak(2);
}
