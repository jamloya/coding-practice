#include<bits/stdc++.h>
using namespace std;

float Round(float var) 
{ 
    float value = (int)(var * 100 + .5); 
    return (float)value / 100; 
}

class Solution {
public:
    bool isPerfectSquare(int num) {
		return fmod(Round(pow(exp(1),log(num)/2)),1)==0;	       
    }
};

int main()
{
	Solution s;
	cout<<s.isPerfectSquare(14);
}
