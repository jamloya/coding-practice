#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int currMaxCount=0;
        int currMax;
        for(auto &i:nums)
        {
            if ( currMaxCount==0 )
                currMax=i;
            currMaxCount+= currMax == i ? 1 : -1;
        }
        return currMax;
    }
};

int main()
{
	vector<int> nums{2,2,1,1,1,2,2};
	Solution s;
	cout<<s.majorityElement(nums);
}
