#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    //sliding window approach 
    //tried to do it in O(n)
    int numSubarraysWithSum1(vector<int>& A, int S) {
        int i,j,sum=0,count=0;
        unordered_map<int,int> m;
        m[0]=1;
        for( i=0,j=0;i<A.size();i++)
        {
           // cout<<sum<<endl;
            sum+=A[i];
            /*if(sum==S)
            {
                count++;
                
            }
            else if(sum>S)
            {
                sum-=A[j++];
                if(sum==S)
                    count++;
            }*/
            //cout<<sum-A[i]<<endl;   
             count+=m[sum-S];
            m[sum]++;
        }
        return count;
    }
    //return number of sum less than or equal to S
    int helper(vector<int> &A,int S)
    {
        if(S<0)return 0;
        int l=0,r=0,count=0;
        
        for(;r<A.size();r++)
        {
            if(A[r])S--;
            while(S<0)
            {
                if(A[l])S++;
                l++;
            }
            count+=(r-l+1);
        }
        return count;
    }
    
    int numSubarraysWithSum(vector<int>& A, int S) {
        //less than and equal to S - less than and equal to (S-1)=equal to sum S
		return helper(A,S)-helper(A,S-1);
    }
};

int main()
{
 Solution s;
 cout<<s.();
}

