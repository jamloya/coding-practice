#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    
    //brute Force
    int fourSumCount1(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int count=0;
        for(auto i:A)
            for(auto j:B)
                for(auto k:C)
                    for(auto l:D)
                        count=count+(i+j+k+l==0?1:0);
        return count;
    }
    
    //O(n^2) Approach
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> sumAB;
        for(auto &i:A)
            for(auto &j:B)
                sumAB[i+j]++;
        int count=0;
        for(auto &c:C)
            for(auto &d:D)
                count+=(sumAB.find(-c-d)!=sumAB.end())?sumAB[-c-d]:0;
    return count;
    }
};

int main()
{
 Solution s;
 cout<<s.();
}

