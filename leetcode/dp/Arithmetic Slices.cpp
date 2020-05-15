#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<int> dp(A.size(),0);
        if(A.size()<3)
        	return 0;
        int totalSlices=0;
        totalSlices=A[1]-A[0]==A[2]-A[1]?dp[2]=1:0;
        for(int i=3;i<A.size();i++)
       	{
       		dp[i]=A[i]-A[i-1]==A[i-1]-A[i-2]?dp[i-1]+1:0;
       		totalSlices+=dp[i];
		}
		return totalSlices;
    }
};

int main()
{
	Solution s;
	vector<int> A{1, 2, 3, 4};
	cout<<s.numberOfArithmeticSlices(A);
}
