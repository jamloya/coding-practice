#include<bits/stdc++.h>
#define us unordered_set<char> 

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
    	us jewels;
    	for (auto ch:J)
    		jewels.insert(ch);
    		
    	int result;
    	for (auto ch:S)
    		result+=jewels.find(ch)==jewels.end()?0:1;
    	return result;
    }
};

int main()
{
	Solution s;
	cout<<s.numJewelsInStones("aA","aAAbBBBBB");
	return 0;
}
