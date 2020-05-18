#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        
        unordered_set<string> keepTrack(words.begin(),words.end());
        string result="";
        for(auto i:words)
        {
        	if (result.length() > i.length() or (result.length() == i.length() and result < i))
                continue;
        	bool flag=false;
            for(int j=1;j<=i.size();j++)
  				if(keepTrack.find(i.substr(0,j))==keepTrack.end())
				  flag=true;
			result=!flag?i:result;
			//result=flag?result.size()<=i.size()?result.size()==i.size()?min(result,i):i:result:result; 
			
			keepTrack.insert(i);      
        }
        return result;;
    }
};

int main()
{
 Solution s;
 vector<string> words{"a", "banana", "app", "appl", "ap", "apply", "apple"};
 cout<<s.longestWord(words
 );
}

