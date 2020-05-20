#include<bits/stdc++.h>

using namespace std;

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    bool match(vector<char> &dictWord,string word,int allowedMistake)
    {
        
        for(auto i=0;i<dictWord.size();i++)
        {
            if(dictWord[i]==word[i])
                continue;
            if(allowedMistake--==0)
                return false;
        }
        
        return allowedMistake==0;
            
    }
    
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto &i:dict)
            dictionaryWords[i]=vector<char>{i.begin(),i.end()};
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for(auto &dictWord:dictionaryWords)
            if(dictWord.first.size()==word.size())
                if(match(dictWord.second,word,1))
                    return true;
        return false;
    }
    private:
        unordered_map<string,vector<char>> dictionaryWords;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */

int main()
{
 Solution s;
 cout<<s.();
}

