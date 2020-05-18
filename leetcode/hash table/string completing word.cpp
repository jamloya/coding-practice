#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char,int> licensePlateChar,wordChar;
        for(auto ch:licensePlate)
        	if(isalpha(ch))
				licensePlateChar[tolower(ch)]++;
        string result(16,' ');
        for(auto i:words)
        {
        	bool flag=true;
        	wordChar.clear();
        	for(auto ch:i)
        		wordChar[ch]++;
        	for(auto it:licensePlateChar)
        	{	//cout<<it.first;
				if(wordChar.find(it.first)!=wordChar.end())
				{
					if(wordChar[it.first]<it.second)
						flag=false;
				}
				else
				{
					//cout<<flag<<endl;
					flag=false;
				}
			}
			//cout<<flag<<endl;
			result=flag?result.size()>i.size()?i:result:result;
		}
        return result;
    }
};


int main()
{
 Solution s;
 vector<string> words{"step", "steps", "stripe", "stepple"};
 cout<<s.shortestCompletingWord("1s3 PSt",words);
}

