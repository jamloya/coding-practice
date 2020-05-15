#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
    	int sum=0,preMin=0,preMax=0,minSum=INT_MAX,maxSum=INT_MIN;
    	for(auto number:A)
			maxSum=max(maxSum,preMax=max(number,preMax+number)),minSum=min(minSum,preMin=min(number,preMin+number)),sum+=number;
		
		return maxSum<0 ? maxSum : max(maxSum,sum-minSum); 
    }
};

int main()
{
	Solution s;
	vector<int> nums{3,-2,2,-3};
	 cout<<s.maxSubarraySumCircular(nums);
}
