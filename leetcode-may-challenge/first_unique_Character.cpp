#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>> m;
        
        for(int i=0;i<s.length();i++)
        {
            if(m.find(s[i])!=m.end())
                m[s[i]]={m[s[i]].first,m[s[i]].second+1};
            else
                m[s[i]]={i,1};
        }
        int index=INT_MAX;
        for(auto i:m)
            if(i.second.second == 1 && i.second.first<index)
                index=i.second.first;
        return index==INT_MAX?-1:index;
    }
};

int main()
{
	Solution s;
	cout<<s.firstUniqChar("leetcode");
}
