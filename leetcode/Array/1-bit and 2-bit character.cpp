#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool flag=true;
		for(int i=0;i<bits.size();i++)
        {
        	if(bits[i]==1)
        		flag=false,i++;
        	else
        		flag=true;
		}
		return flag;
    }
};

int main()
{
 Solution s;
 vector<int> bits{1, 0, 1,0};
 cout<<s.isOneBitCharacter(bits);
}

