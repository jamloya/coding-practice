#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        bitset<32> numBits(0);
        int currIt=0;
        for(;num>0;num/=2,currIt++)
        	{
        		if(num%2==0)
        			numBits[currIt]=1;
			}
			//cout<<numBits<<endl;
        int complement=0;
        for(int i=31;i>=0;i--)
		{
			complement+=numBits.test(i)==1?pow(2,i):0;
		}
        return complement;
    }
};

int main()
{
	Solution s;
	cout<<s.findComplement(5);
}
