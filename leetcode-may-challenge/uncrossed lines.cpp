#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    vector<vector<int>> dp;//using memoization
    int fun(vector<int> &A,vector<int> &B,int i,int j)
    {
        if(i==A.size())
            return 0;
        if(j==B.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=A[i]==B[j]?1+fun(A,B,i+1,j+1):max(fun(A,B,i+1,j),fun(A,B,i,j+1));
    }
    
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        dp=vector<vector<int>>(A.size(),vector<int>(B.size(),-1));
        return fun(A,B,0,0);
    }
};

int main()
{
 Solution s;
 cout<<s.();
}

