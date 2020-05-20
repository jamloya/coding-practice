#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<int> levelfriends;
        unordered_set<int> visited;
        levelfriends.push_back(id);
        visited.insert(id);
        while(level--)
        {
            vector<int> thisLevel;
            for(auto i:levelfriends)
            {
                for(auto j:friends[i])
                    if(visited.insert(j).second)
                        thisLevel.push_back(j);
            }
            levelfriends=thisLevel;
        }
        unordered_map<string,int> m;
        for(auto i:levelfriends)
            for(auto j:watchedVideos[i])
                m[j]++;
        set<pair<int,string>> result;
        for(auto i:m)
            result.insert({i.second,i.first});
        vector<string> res;
        for(auto i:result)
            res.push_back(i.second);
        return res;
    }
};
int main()
{
 Solution s;
 cout<<s.();
}

