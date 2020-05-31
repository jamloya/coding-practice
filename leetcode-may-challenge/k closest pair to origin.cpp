#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<float,pair<int,int>>> track;
        for(auto &i:points)
            track.push_back(make_pair((float)sqrt( i[0]*i[0]+i[1]*i[1] ),make_pair(i[0],i[1])));
        
        vector<vector<int>> result;
        
        sort(track.begin(),track.end(),[&](auto p1,auto p2){
            return p1.first<p2.first;
        });
        int i=0;
        while(result.size()<K)
            result.push_back({track[i].second.first,track[i++].second.second});
        
        return result;
            
    }
};

int main()
{
 Solution s;
 cout<<s.();
}

