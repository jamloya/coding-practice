#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    string covnverttolower(string s){
        return accumulate(s.begin(),s.end(),string(" "),[&](string s1,char c){return s1+(char)tolower(c);});
    }
    
    string defyVowel(string s)
    {
         return accumulate(begin(s), end(s), string(""), [](string k, char c) { return k +
    (char)(string("aeiou").find(tolower(c)) != string::npos ? '*' : tolower(c)); });
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        
        
        for (auto &w:wordlist)
            stringmap.insert({w,w}),stringmap.insert({covnverttolower(w),w}),stringmap.insert({defyVowel(w),w});
       
        
        vector<string> result;
        //sorry allow me i have aproblem with ternary operators i use it unneccasirily
        for(auto &q:queries)
            result.push_back(stringmap.find(q)!=stringmap.end()?stringmap[q]:(stringmap.find(covnverttolower(q))!=stringmap.end()?stringmap[covnverttolower(q)]:(stringmap.find(defyVowel(q))!=stringmap.end()?stringmap[defyVowel(q)]:"")));
        return result;
    }
    
    private:
    unordered_map<string,string> stringmap;
};
int main()
{
 Solution s;
 cout<<s.();
}




