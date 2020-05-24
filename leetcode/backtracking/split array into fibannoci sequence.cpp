#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    
    bool fun(string &S,int start,vector<int> &result)
    {
        if(start==S.size() && result.size()>2)
            return true;
        
     long num=0;
        for(int i=start;i<S.size();i++)
        {
            num= num * 10 + (S[i] - '0');
            
            if(num>INT_MAX) return false;
            
            if(S[start]=='0' && i>start ) return false;
            
            if(result.size()<2 || num == ((long long)result.back() + (long long)result[result.size()-2]))
            {
                result.push_back(num);
                if(fun(S,i+1,result))
                    return true;
                result.pop_back();
            }
        }
        return false;
    }
    
    
    vector<int> splitIntoFibonacci(string S) {
        vector<int> res;
        
        fun(S,0,res);
        return res;
    }
};

int main()
{
 Solution s;
 cout<<s.();
}

