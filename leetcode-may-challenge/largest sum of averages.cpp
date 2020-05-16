#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    double fun(vector<int> &sum,vector<int> &A,int start,int k,vector<vector<double>> &dp)
    {//return ((double)(sum[len-1] - sum[s] + A[s]) / (len-s));
        if(dp[start][k]!=0)return dp[start][k];
        if(k==1){
            dp[start][k]= ((double)(sum[A.size()-1]-sum[start]+A[start])/(A.size()-start));
            return dp[start][k];
        }
        
        for(int i=start;i+k<=A.size();i++)
        {dp[start][k]=max(dp[start][k],((double) (sum[i] - sum[start] + A[start]) / (i - start + 1)) +fun(sum, A, i+1,k-1,dp));}
        return dp[start][k];
    }
    
    

    double largestSumOfAverages(vector<int>& A, int K) {
        vector<int> sum(A.size(),0);
        vector<vector<double>> dp(A.size(),vector<double>(K+1,0));
        for(int i=0;i<A.size();i++)
        	sum[i]=A[i]+(i>0?sum[i-1]:0);
        return fun(sum,A,0,K,dp);
    }
};


int main()
{
	Solution s;
	vector<int> num{9,1,2,3,9};
	cout<<s.largestSumOfAverages(num,3);
}
