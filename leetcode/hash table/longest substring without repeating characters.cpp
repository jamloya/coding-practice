#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	//O(n)
	//try to do with a sliding window approach
    int lengthOfLongestSubstring(string s) {
	      int maxLength=1;
	      if(s.size()==0) return 0;
	      string result;
	      result.push_back(s[0]);
	      //cout<<result;
	      for(int i=1;i<s.size();i++)
	      {
	      	
	      	size_t found=result.find(s[i]);
	      	
	      	if(found!=string::npos)
	      		result=result.substr(found+1);
	      	//cout<<result;
	      	//cout<<found<<endl;
			result+=s[i];
	      	int size=result.length();
	      	maxLength=max(maxLength,size);
		  }
		  return maxLength;
    }
};

int main()
{
 Solution s;
 cout<<s.lengthOfLongestSubstring("bbbb");
}

