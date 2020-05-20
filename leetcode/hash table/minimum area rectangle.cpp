#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
       unordered_map<int,unordered_set<int>> mp;
        
        for(auto &i:points)
            mp[i[0]].insert(i[1]);
        int result=INT_MAX;
        for(auto i=0;i<points.size();i++)
            for(auto j=i;j<points.size();j++)
            {
               
                if(points[i][0]==points[j][0] || points[i][1]==points[j][1])
                    continue;
                if(mp[points[i][0]].find(points[j][1])!=mp[points[i][0]].end() && mp[points[j][0]].find(points[i][1])!=mp[points[j][0]].end())
                    result=min(result,abs(points[i][0]-points[j][0])*abs(points[i][1]-points[j][1]));
                
            }
        return result==INT_MAX?0:result;
    }
};

int main()
{
 Solution s;
 cout<<s.();
}

