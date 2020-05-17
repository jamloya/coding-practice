#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
	    unordered_map<int,pair<int,int>> indexes;
		unordered_map<int,int> count;
		vector<pair<int,int>> maximum;
		for(int i=0;i<nums.size();i++)
		{	
			if(indexes.find(nums[i])!=indexes.end())
				indexes[nums[i]].second=i;
			else
				indexes[nums[i]]={i,i};
			count[nums[i]]++;
			//maximum.push_back(make_pair(count[nums[i]],nums[i]));
		}
		for(auto i:count)
			maximum.push_back(make_pair(i.second,i.first));
		sort(maximum.begin(),maximum.end(),
		[&](pair<int,int> p1,pair<int,int> p2){
			return p1.first==p2.first?indexes[p1.second].second-indexes[p1.second].first < indexes[p2.second].second-indexes[p2.second].first:p1.first>p2.first;
			
		});
		return abs(indexes[maximum[0].second].first - indexes[maximum[0].second].second ) + 1 ; 
    }
};

int main()
{
 Solution s;
 vector<int> nums{2,1,1,2,1,3,3,3,1,3,1,3,2};
 cout<<s.findShortestSubArray(nums);
}

