#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
  		sort(words.begin(),words.end(),
		  [&](string s1,string s2)->bool{return s1.length()<s2.length();
		  });      
		  
		  unordered_map<string,int> dp;
		  int longestChain=0;
		  for(auto word:words)
		  {
		  	for(int i=0;i<word.length();i++)
		  		dp[word]=max(dp[word],dp[word.substr(0,i)+word.substr(i)]+1);
		  	longestChain=max(longestChain,dp[word]);
		  }
		  return longestChain;
    }
};

int main()
{
	Solution s;
	vector<string> words{"a","b","ba","bca","bda","bdca"};
	cout<<s.longestStrChain(words);
}
