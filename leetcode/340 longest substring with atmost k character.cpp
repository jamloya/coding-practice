#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
	   Solution(){}
	   
	   //using the sliding Window Approach O(n)  
	   //function prototype here
		string LongestSubstring(string s,int k)
		{
			vector<int> count(26,0);
			int starting=0;
			int left=0,right=0;
			int maxSize=0;
			while(right<s.size())
			{
				if(count[s[right]-'a']++==0) k--;
				if(k<0)
				{
					while(left<right || k<0 )
					{
						if(--count[s[left]-'a']==0)
							k++;
						left++;
					}				
				}
				
				if(maxSize<right-left+1)
				{
					maxSize=right-left+1;
					starting=left;
				}
				right++;
			}
			return s.substr(starting,maxSize);
		}
};

int main()
{
	 Solution s;
	 clock_t t;
	 t=clock();
	 string str="eceeeeeeeeeeeeeeeeeeba";
	 cout<<s.LongestSubstring(str,2);
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

