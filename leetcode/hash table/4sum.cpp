#include<bits/stdc++.h>

using namespace std;

class Solution{

public:

    vector<vector<int> > fourSum(vector<int> &num, int target){
        vector<vector<int>> vvi;
        int n = num.size();
       
        if(n < 4) return  vvi;
        
        sort(num.begin(), num.end());        
        unordered_map<int, vector<pair<int, int>> > mp;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                mp[num[i]+num[j]].push_back(make_pair(i,j));
            }
        }
        
        for(int i = 0; i < n; i++)
	    	for(int j=i+1;j<n;j++)
	    	{
	    		int res=target-num[i]-num[j];
	    		if(mp.find(res)!=mp.end())
	    		{
	    			for(auto k:mp[res])
	    			{
	    				if(k.first!=i && k.first!=j  && k.second!=i && k.second!=j)
                        {
                            bool flag=true;
                            vector<int> temp{num[k.first],num[k.second],num[i],num[j]};
                            sort(temp.begin(),temp.end());
                           for(auto i:vvi)
                               if(i==temp)
                                   flag=false;
                            if (flag)
                                vvi.push_back(temp);
                        }
	    				
					}
	    		}
			}
        
       return vvi;
    }
  };
int main()
{
 Solution s;
 cout<<s.();
}

