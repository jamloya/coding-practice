#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
/*	
	int fun(vector<int> &A,vector<int> &B,int ia,int ib)
	{
		if (ia==A.size())
			return 0;
		if (ib==B.size())
			return 0;
			
		return max(A[ia]==B[ib]?1+fun(A,B,ia+1,ib+1):0,max(fun(A,B,ia+1,ib),fun(A,B,ia,ib+1)));
	}
	
    int findLength(vector<int>& A, vector<int>& B) {
        return fun(A,B,0,0);
    }*/
    
     int findLength(vector<int>& A, vector<int>& B) {
        if(!A.size() || !B.size())
            return 0;
        vector<int> dp(B.size());
        int longestLength=0;
        for(int i=A.size()-1;i>=0;i--)
            for(int j=0;j<B.size();j++)
                longestLength=max(longestLength,dp[j]=A[i]==B[j]? 1 + (j!=B.size()-1 ? dp[j+1] : 0)  : 0);
        return longestLength;
    }
    
};
int main()
{
	Solution s;
	vector<int> A{1,2,3,2,1};
	vector<int> B{3,2,1,4,7};
	cout<<s.findLength(A,B);
}
