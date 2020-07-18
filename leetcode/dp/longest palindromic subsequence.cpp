#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
	int helper(string &s,int l,int r,vector<vector<int>> &mem)
	{
		if(l==r)
			return 1;
		if(l>r)
			return 0;
		if(mem[l][r]!=0)
			return mem[l][r];
			
		return mem[l][r]= s[l]==s[r] ?2+helper(s,l+1,r-1,mem):max(helper(s,l+1,r,mem),helper(s,l,r-1,mem));
	}
	
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> mem(s.size(),vector<int>(s.size()));
		return helper(s,0,s.size()-1,mem);
    }
};

int main()
{
 Solution s;
 cout<<s.();
}

