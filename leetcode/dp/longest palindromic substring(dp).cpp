//do the dp approach

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
         int n=s.size();
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        
        int maxlength=1,start=0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                maxlength=2;
                start=i;}
        }
        
       
        for(int k=3;k<=n;k++)
        {
            
            for(int j=0;j<n-k+1;j++)
            {
                
                int currIndex=j+k-1;
               // cout<<currIndex;
                if(s[currIndex]==s[j] && dp[j+1][currIndex-1])
                {
                    dp[j][currIndex]=1;
                    start=j;
                    maxlength=k;
                }
               // cout<<1<<endl;
            }
        }
        return s.substr(start,maxlength);
    }
};