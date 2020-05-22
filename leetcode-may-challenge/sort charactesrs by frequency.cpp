#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        
        for(auto ch:s)
            m[ch]++;
        
        map<int,vector<string>,greater<int>> m1;
        
        for(auto i:m)
        {
            string a="";
            for(int j=0;j<i.second;j++)
                a+=i.first;
            m1[i.second].push_back(a);
        }
        
        string res="";
        for(auto i:m1)
            for(auto j:i.second)
                res+=j;
        return res;
    }
};

int main()
{
 Solution s;
 cout<<s.();
}

