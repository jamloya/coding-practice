#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
		sort(pairs.begin(),pairs.end(),
		[&](vector<int> p1,vector<int> p2){return p1[0]<p2[0];
		});        
		
		vector<int> dp(pairs.size(),1);
		int result=1;
		for(int i=1;i<pairs.size();i++)
		{
			for(int j=0;j<i;j++)
				if(pairs[j][1]<pairs[i][0])
					dp[i]=max(dp[i],dp[j]+1);
				result=max(result,dp[i]);
		}
		return result;
    }
};


int main()
{
	Solution s;
	vector<vector<int>> pairs{{1,2}, {2,3}, {3,4}};
	cout<<s.findLongestChain(pairs);
}
