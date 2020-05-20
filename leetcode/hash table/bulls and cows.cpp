#include<bits/stdc++.h>

using namespace std;

class Solution {
public:/*
    string getHint(string secret, string guess) {
        unordered_map<char,unordered_set<int>> indexesOfSecret;
        for(auto i=0;i<secret.size();i++)
            indexesOfSecret[secret[i]].insert(i);
        int A=0,B=0,c=0;
        
        for(int i=0;i<guess.size();i++)
        {   indexesOfSecret.find(guess[i])!=indexesOfSecret.end()?indexesOfSecret[guess[i]].find(i)!=indexesOfSecret[guess[i]].end()?A++,indexesOfSecret[guess[i]].erase(i):B++,indexesOfSecret[guess[i]].erase(i):c++;
        indexesOfSecret[guess[i]].size()==0?indexesOfSecret.erase(guess[i]):c++;
        }
        return to_string(A)+"A"+to_string(B)+"B";
    }*/
    string getHint(string secret, string guess) {
        int A=0,B=0;
        
        vector<int> digits(10,0);
        
        if(secret.size()!=guess.size()) return "0A0B";
        for(int i=0;i<guess.size();i++)
        {
            if(guess[i]==secret[i])
                A++;
            else
            {
                if(++digits[secret[i]-'0']<=0)B++;
                if(--digits[guess[i]-'0']>=0)B++;
            }
        }
        return to_string(A)+"A"+to_string(B)+"B";
    }
    
};

int main()
{
 Solution s;
 cout<<s.();
}

