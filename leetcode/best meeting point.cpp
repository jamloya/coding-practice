// #296 best meeting point


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
	   
	   
	   //Brute force-go with the dfs approach whenever you encounter a one do dfs and store the distancee to other coordinates from that point and at end just traverse and find the minimum
	   
	   
	   //this is more optimal approach
	   //function prototype here
	   int bestPoint(vector<vector<int>> &coords)
	   {
	   		vector<int> rowsOnes,colOnes;
	   		for(int i=0;i<coords.size();i++)
	   			for(int j=0;j<coords[0].size();j++)
	   				if(coords[i][j]==1)
	   					rowsOnes.push_back(i),colOnes.push_back(j);
	   					
	   		sort(rowsOnes.begin(),rowsOnes.end());
	   		sort(colOnes.begin(),colOnes.end());
	   		
	   		int size=rowsOnes.size();
	   		int middleX=rowsOnes[size/2],middleY=colOnes[size/2];
	   		
	   		int result=0;
	   		for(auto i:rowsOnes) result+=abs(i-middleX);
	   		for(auto i:colOnes) result+=abs(i-middleY);
	   		
	   		return result;
	   }	
};

int main()
{
	vector<vector<int>> coords{{1,0,0,0,1},{0,0,0,0,0},{0,0,1,0,0}};
	 Solution s;
	 clock_t t;
	 t=clock();
	 cout<<s.bestPoint(coords);
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

