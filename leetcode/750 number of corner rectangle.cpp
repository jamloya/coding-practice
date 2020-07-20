#include<bits/stdc++.h>

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
	   
	   //function prototype here
	   int countCornerRectangles(vector<vector<int>>& grid) {
	   		int rowSize=grid.size(),colSize=grid[0].size(),numberOfRect=0;
	   		for(int currentRow=0;currentRow<rowSize;currentRow++)
	   		{
	   			for(int currentCol=0;currentCol<colSize;currentCol++)
			    {
				 	if(grid[currentRow][currentCol]==0)
					 	continue;
						 
					for(int nextCurrentRow=currentRow+1;nextCurrentRow<rowSize;nextCurrentRow++) 
					{
						if(grid[nextCurrentRow][currentCol]==0)
							continue;
							
						for(int nextCurrentCol=currentCol+1;nextCurrentCol<colSize;nextCurrentCol++)
							numberOfRect+=grid[currentRow][nextCurrentCol]==1 && grid[nextCurrentRow][nextCurrentCol];
					} 	
				}	
			}
	   		return numberOfRect;
	   }
	   
};

int main()
{
	 Solution s;
	 vector<vector<int>> grid{{1, 1, 1, 1, 1},{1, 1, 1, 1, 1},{1, 1, 1, 1, 1},{1, 1, 1, 1, 1}};
	 clock_t t;
	 t=clock();
	 cout<<s.countCornerRectangles(grid);
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

