#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        if(S.size()==0)return {};
		char currChar=S[0];
        int currCharStart=0;
        vector<vector<int>> result;
		for (auto i=1;i<S.size();i++)
		{
			if(currChar!=S[i])
			{
				if(i-currCharStart>=3)
					result.push_back({currCharStart,i-1});
				currChar=S[i];
				currCharStart=i;
			}	
		}
		if(i-currCharStart>=3)
			result.push_back({currCharStart,i-1});
		
        return result;
    }
};

int main()
{
 Solution s;
 cout<<s.();
}

