#include<bits/stdc++.h>
using  namespace std;
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
  		int xDiff=coordinates[1][0]-coordinates[0][0],
		  yDiff=coordinates[1][1]-coordinates[0][1];      
    
		for(int i=2;i<coordinates.size();i++)
		{
			if((coordinates[i][0]-coordinates[0][0])*yDiff 
			!= xDiff*(coordinates[i][1] - coordinates[0][1]))
            	return false;
		}
		return true;
	}
};

int main()
{
	vector<vector<int>> points{{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}};
 	Solution s;
	cout<<s.checkStraightLine(points);
}
