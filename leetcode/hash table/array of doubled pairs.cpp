#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        
        unordered_map<int,int> keepTrack;
        
        for(auto &i:A)
            keepTrack[i]++;
        
        sort(A.begin(),A.end(),[](int a,int b){return abs(a)<abs(b);});
        
        for(auto &i:A)
        {
            if(keepTrack[i]==0)
                continue;
            if(keepTrack[2 * i]==0)
                return false;
            keepTrack[2*i]--,keepTrack[i]--;
                
        }
       
        return true;
        
    }
};

int main()
{
 Solution s;
 cout<<s.();
}

