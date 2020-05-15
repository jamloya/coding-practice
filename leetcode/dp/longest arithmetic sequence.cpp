class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        unordered_map<int,unordered_map<int,int>> dp;
        int longestSeq=0;
        
        for(int i=0;i<A.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff=A[i]-A[j];
                dp[i][diff] = dp[j].count(diff) > 0 ? dp[j][diff] + 1 : 2;
                longestSeq=max(longestSeq,dp[i][diff]);
            }
        }
        
        return longestSeq;
    }
};
