#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
       vector<pair<int,int>> numberIndex;
	   for(int i=0;i<nums.size();i++)
	   	for(auto element:nums[i])
		   numberIndex.push_back({element,i}); 
		   
		sort(numberIndex.begin(),numberIndex.end());
		
		int count=0,range=INT_MAX;
        int j=0;
		vector<int> visit(nums.size(),0);
		vector<int> res(2);
		for(int i=0;i<numberIndex.size();i++)
		{
			
			while(count<nums.size() && j<numberIndex.size())
			{
				if(visit[numberIndex[j].second]==0)
					count++;
				visit[numberIndex[j].second]++;
				j++;
                
			}
			//cout<<numberIndex[j-1].first<<" "<<numberIndex[i].first<<endl;
			if(count==nums.size() && numberIndex[j-1].first-numberIndex[i].first < range)
			{
				range=numberIndex[j-1].first-numberIndex[i].first;
				res[0]=numberIndex[i].first;
				res[1]=numberIndex[j-1].first;
			}
			visit[numberIndex[i].second]--;
			if(visit[numberIndex[i].second]==0)
				count--;
		}
		return res;
    }
};

int main()
{
 Solution s;
 cout<<s.();
}

