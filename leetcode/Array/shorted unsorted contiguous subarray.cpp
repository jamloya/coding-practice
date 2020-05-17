#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
  		int start=0;
  		vector<int> copy;
  		copy=nums;
		sort(nums.begin(),nums.end());
		 while(start<nums.size() && copy[start]==nums[start])start++;
		 int end=nums.size()-1;
		 while(end>0 && copy[end]==nums[end])end--;
		 if(end<start)return 0;
		 return end-start+1;     
    }
};

int main()
{
 Solution s;
 vector<int> nums{2, 6, 4, 8, 10, 9, 15};
 cout<<s.findUnsortedSubarray(nums);
}

