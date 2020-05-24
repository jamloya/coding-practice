#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    unordered_set<char> vowel{'a','e','i','o','u'};
    int checkVowels(vector<char> &s)
    {
        int numberOfVowels=0;
        for(auto &ch:s)
            if(vowel.find(ch)!=vowel.end())
                numberOfVowels++;
        return numberOfVowels;
    }
    
    int maxVowels(string s, int k) {
        
        if(s.size()<k)
            return 0;
        vector<char> slidingWindow(s.begin(),s.begin()+k);
        int result=checkVowels(slidingWindow);
        int res=result;
        char first=s[0];
        for(int i=k;i<=s.size();i++)
        {
            //cout<<first<<endl;
            result-=vowel.find(first)!=vowel.end()?1:0;
            result+=vowel.find(s[i])!=vowel.end()?1:0;
            res=max(res,result);
            first=s[i-k+1];
        }
        return res;
    }
};

int main()
{
 Solution s;
 cout<<s.();
}

