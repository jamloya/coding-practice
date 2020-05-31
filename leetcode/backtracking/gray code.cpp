#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
	
	void fun(bitset<32> &current,vector<int> &result,int n)
	{
		if(n==0)
			result.push_back(current.to_ulong());
		else
		{
			fun(current,result,n-1);
			current.flip(n-1);
			fun(current,result,n-1);	
		}
	}
	
    vector<int> grayCode(int n) {
	  	bitset<32> current(0);
		vector<int> result;
		fun(current,result,n);
		return result;
		         
    }
};

int main()
{
 Solution s;
 cout<<s.();
}

