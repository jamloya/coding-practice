#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
	
	int binarySearch(int start,int end,vector<int> &nums,int target)
	{
		if(start>=end)
			return -1;
		int mid=(start+end)/2;
		return nums[mid]==target?mid:nums[mid]>target?binarySearch(start,mid,nums,target):binarySearch(mid+1,end,nums,target);
	}
	
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0;i<numbers.size()-1;i++)
        {	
			int result=binarySearch(i+1,numbers.size(),numbers,target-numbers[i]);
			if(result!=-1)
				return {i+1,result+1};
    	}
	}
};


int main()
{
 Solution s;
 vector<int> nums{{5,25,75}};
for(auto i:s.twoSum(nums,100))
{
	cout<<i<<endl;
}
}

