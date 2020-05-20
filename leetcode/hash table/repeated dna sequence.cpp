#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    //Sliding window approach
    //O(n)
    
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> tenChar;
        for(int i=0;i+9<s.size();i++)
        {
            tenChar[s.substr(i,10)]++;
        }
        vector<string> result;
        for(auto &i:tenChar)
            if(i.second>1)
                result.push_back(i.first);
        
        return result;
    }
};


int main()
{
 Solution s;
 cout<<s.();
}

