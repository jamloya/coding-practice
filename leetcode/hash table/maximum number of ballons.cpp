#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int maxNumberOfBalloons(string text) {
  		vector<int> count(26,0);
		  for(auto ch:text)
		  	count[ch-'a']++;
		return min(count['b'-'a'],min(count['a'-'a'],min(count['l'-'a']/2,min(count['o'-'a'],count['n'-'a']))));    
    }
};

int main()
{
 Solution s;
 cout<<s.maxNumberOfBalloons("nlaebolko");
}

