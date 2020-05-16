#include<bits/stdc++.h>
using namespace std;
class Solution {
public:    
	//Greedy Approach
	/*int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(),clips.end());
        int count=0;
        for(int i=0,start=0,end=0;start<T;start=end,count++)
        {
			for(;i<clips.size() && clips[i][0]<=start;i++)
        		end=max(end,clips[i][1]);
        	if(start==end)
        		return -1;
    	}
    	return count;
	}*/
	
	//DP Approach
	int videoStitching(vector<vector<int>>& clips, int T) {
	sort(clips.begin(),clips.end());
	vector<int> dp(101,INT_MAX);
	dp[0]=0;
	for(auto currClip:clips)
	{
		for(int i=currClip[0];i<currClip[1];i++)
			dp[i+1]=min(dp[i+1],dp[currClip[0]]+1);
	}
	
	return dp[T]==INT_MAX?-1:dp[T];
	}
};

int main()
{
	Solution s;
	vector<vector<int>> clips{{0,2},{4,6},{8,10},{1,9},{1,5},{5,9}};
	cout<<s.videoStitching(clips,11);
}
