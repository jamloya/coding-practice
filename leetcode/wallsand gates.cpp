/*
	You are given a m x n 2D grid initialized with these three possible values.
	
	-1 - A wall or an obstacle.
	0 - A gate.
	INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
	Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
	
	Example:
	
	Given the 2D grid:
	
	INF  -1  0  INF
	INF INF INF  -1
	INF  -1 INF  -1
	  0  -1 INF INF
	1
	2
	3
	4
	After running your function, the 2D grid should be:
	
	  3  -1   0   1
	  2   2   1  -1
	  1  -1   2  -1
	  0  -1   3   4
*/

#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;

class TreeNode
{
 public:
	  int val;
	  TreeNode *left,*right;

 TreeNode(int value) : val(value),left(nullptr),right(nullptr){}
};




class Solution{
public:
	   Solution(){}
	   
	   void dfs(vector<vector<int>> &grid,int currRow,int currCol,int dist,vector<vector<bool>> visited)
	   {
	   		if(currRow<0 || currCol<0 ||currRow>=grid.size() || currCol>=grid[0].size() || grid[currRow][currCol]==-1  || grid[currRow][currCol]==-1 || visited[currRow][currCol] )
	   			return;
	   		visited[currRow][currCol]=1;
	   		
	   		grid[currRow][currCol]=min(grid[currRow][currCol],dist);
	   		dfs(grid,currRow+1,currCol,dist+1,visited);
	   		dfs(grid,currRow-1,currCol,dist+1,visited);
	   		dfs(grid,currRow,currCol-1,dist+1,visited);
	   		dfs(grid,currRow,currCol+1,dist+1,visited);
	   }
	   
	   //function prototype here
	   void wallsAndGates(vector<vector<int>> &grid)
	   	{
	   		if(grid.size()==0)
	   			return;
	   		vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),0));
	   		for(int i=0;i<grid.size();i++)
	   			for(int j=0;j<grid[0].size();j++)
	   				if(grid[i][j]==0)
	   				{
	   					grid[i][j]=INF;
	   					dfs(grid,i,j,0,visited);
	   					grid[i][j]=0;
					}
		} 
};

int main()
{
	 vector<vector<int>> grid {{INF,  -1 , 0 , INF},{INF ,INF, INF , -1},{INF , -1 ,INF , -1},{0 , -1 ,INF ,INF}};
	 Solution s;
	 clock_t t;
	 t=clock();
	 s.wallsAndGates(grid);
	 for (auto i:grid)
	 {
	 	for(auto j:i)
	 		cout<<j<<" ";
	 	cout<<endl;
	 }
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

