#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    bool checkPrefix(string s1,string s2)
    {
       
        return s1.find(s2)==0?true:false;
    }
    
    int isPrefixOfWord(string sentence, string searchWord) {
        unordered_set<string> words;
        vector<pair<string,int>> wordIndex;
        int i=1;
        stringstream ss(sentence);
        string word;
        for(;ss>>word;i++)
            if(words.find(word)==words.end())
                wordIndex.push_back({word,i});
        
        for(auto i:wordIndex)
            if(checkPrefix(i.first,searchWord))
                return i.second;
        
        return -1;
        
    }
};

int main()
{
 Solution s;
 cout<<s.();
}

