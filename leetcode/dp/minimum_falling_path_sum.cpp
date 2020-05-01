class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        if(A.size()==1)
            return A[0][0];
        
        for(int i=1;i<A.size();i++)
            for(int j=0;j<A[i].size();j++)
            {
                if(j==0)
                    A[i][j]+=min(A[i-1][j],A[i-1][j+1]);
                else if(j==A[i].size()-1)
                    A[i][j]+=min(A[i-1][j],A[i-1][j-1]);
                else
                    A[i][j]+=min(A[i-1][j-1],min(A[i-1][j],A[i-1][j+1]));
            }
        int res=INT_MAX;
        for(int j=0;j<A[0].size();j++)
            res=min(res,A[A.size()-1][j]);
        return res;
    }
};

