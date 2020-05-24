#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
	
	void makeTumbler(int n)
	{
		int curr=1;
		int rows=0;
		int k=1,j=1;
		while(k<n)
			rows++,k=(j*((j++)+1))/2;
		
		
		for(int i=1;i<=rows;i++)
		{
			cout<<string(rows-i+1,' ');
			if(curr<10)cout<<" ";
			for(int j=0;j<i;j++)
				cout<<curr++<<" ";
			cout<<endl;
		}
	}
};

int main()
{
 Solution s;
 s.makeTumbler(30);
}

