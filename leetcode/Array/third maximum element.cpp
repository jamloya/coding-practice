#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
  		int firstMax=INT_MIN,secondMax=-INT_MIN,thirdMax=INT_MIN;
		  for(int i:nums)
		  	{
		  		if(firstMax<i)
		  		{
		  			thirdMax=secondMax;
		  			secondMax=firstMax;
		  			firstMax=i;
				}
				else if(secondMax<i && firstMax!=i)
				{
					thirdMax=secondMax;
		  			secondMax=i;
				}
				else if(thirdMax<i && secondMax!=i && firstMax!=i)
				{
					thirdMax=i;
				}
				cout<<firstMax<<secondMax<<thirdMax<<endl;
			}
			//cout<<firstMax<<secondMax<<thirdMax;
			return thirdMax!=-1?thirdMax:firstMax;      
    }
};

int main()
{
 Solution s;
 vector<int> nums{2,2,3,1};
 cout<<s.thirdMax(nums);
}

