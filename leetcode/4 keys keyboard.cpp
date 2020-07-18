//651 4 keys keyboard
//variation of 2 key keyboard

#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
	   Solution(){}
	   
	   //function prototype here
	   int fourKeysBoard(int n)
	   {
		   	vector<int> dp(n+1);
		   	
		   	for(int i=0;i<=n;i++)
		   	{
		   		dp[i]=i; //ith place can have max i number of A's.
				for(int j=1;j<i-2;j++) // i-2  -> represents the keys ( Ctrl-A + ctrl-C )
				{
					//dp[j] already holds the maximum number of A's.
					dp[i]=max(dp[i],dp[j]*(i-j-1)); //i-j-1 represent the total pastes we can do
				}	
			}
			
			return dp[n];
	   }
	   
};

int main()
{
	 Solution s;
	 clock_t t;
	 t=clock();
	 cout<<s.fourKeysBoard(7000);
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

