#include<bits/stdc++.h>

using namespace std;
//Priority Queue approach
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        priority_queue<int,vector<int>,greater<int>> pq;  //to arrange the element in increasing order
        for(auto &i:primes)
            pq.push(i);
        int curr,count=1;
        //pq.push(1);
        while(count<n)
        {
            curr=pq.top();
            pq.pop();
            
            if(curr!=pq.top())
            {
                count++;
                for(auto i:primes)
                    if((long long)i*curr<INT_MAX)
                        pq.push(i*curr);
            }
            else if(pq.size()==0)
            {
                count++;
                for(auto i:primes)
                    pq.push(i*curr);
            }
        }
        return curr;
    }
};

//lets go with a dp approach
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> pointers(primes.size(),0);
        vector<int> nextCoeff(primes.size(),1);  
        vector<int> dp(n);
        
        dp[0]=1;
        
        for(int i=0;i<n;i++)
        {
        	long long minimum=*min_element(nextCoeff.begin(),nextCoeff.end());
        	dp[i]=minimum;
        	for(int j=0;j<primes.size();j++)
        	{
        		if(nextCoeff[j]==minimum)
        		{
        			nextCoeff[j]=primes[j]*dp[pointers[j]++];
				}
			}
        	
		}
        return dp[n-1];
    }
};

int main()
{
 Solution s;
 cout<<s.();
}

