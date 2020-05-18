#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    	if(p.size()>s.size())
    		return {};
        vector<int> result,countS(26,0),countP(26,0);
        for(auto &ch:p)
        	countP[ch-'a']++;
        for(int i=0;i<p.size();i++)
        {
        	countS[s[i]-'a']++;
		}
		if(countP==countS)
			result.push_back(0);        

		for(int i=1;i+p.size()-1<s.size();i++)	
        {
        	countS[s[i-1]-'a']--;
        	countS[s[i-1+p.size()]-'a']++;
        	if(countP==countS)
        		result.push_back(i);
		}
		return result;
    }
};

int main()
{
 Solution s;
 
 for (auto i:s.findAnagrams("eidbaooo","ab"))
 {
 	cout<<i;
 }
}

