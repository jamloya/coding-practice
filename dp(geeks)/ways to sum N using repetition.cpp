#include<bits/stdc++.h>

using namespace std;


class Solution 
{
public:
	int result=0;
	void helper(vector<int> &nums,int target,int sum)
	{
		if(sum==target)
		{
			result++;
			return;
		}	
		if(sum>target)
			return;	
		for(int i=0;i<nums.size();i++)
		{
			helper(nums,target,sum+nums[i]);
		}
	}
	
	int numWays(vector<int> &nums,int sum)
	{
		helper(nums,sum,0);
		return result;
	}	
};

int main()
{
 Solution s;
 vector<int> nums{1,5,6};
 
 cout<<s.numWays(nums,0);

}

