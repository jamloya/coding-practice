#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum=0,minimum=INT_MAX;
        for(auto i:nums)
        	{
        		sum+=i;
        		minimum=min(minimum,sum);
			}
        //cout<<sum;
        return minimum>=0?1:abs(minimum)+1;
    }
};

int main()
{
 Solution s;
 vector<int> nums{-3,2,-3,4,2};
 cout<<s.minStartValue(nums);
}

