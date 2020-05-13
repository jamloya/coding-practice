#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    	    vector<int> magazineAlphaCount(26,0);
    	    for(auto ch:magazine)
    	    	magazineAlphaCount[ch-'a']++;
    	    	
    	    for(auto ch:ransomNote)
    	    	{
    	    		#cout<<ch<<magazineAlphaCount[ch-'a'];
    	    		if (magazineAlphaCount[ch-'a']==0)
    	    			return false;
    	    		magazineAlphaCount[ch-'a']--;
				}
				return true;
    }
};

int main()
{
	Solution s;
	cout<<s.canConstruct("a","b");
	//cout<<s.canConstruct("aa","ab");
}
