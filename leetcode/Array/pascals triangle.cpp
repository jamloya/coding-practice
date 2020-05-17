#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i=0;i<numRows;i++)
        {
        	result.push_back(vector<int>(i+1,1));
        	for(int j=1;j<i;j++)
        		result[i][j]=result[i-1][j]+result[i-1][j+1];
		}
		return result;
    }
};

int main()
{
 Solution s;
 cout<<s.();
}

