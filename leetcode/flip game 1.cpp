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
	   vector<string> flipGame(string s)
	   {
	   		if(s.size()==0)
	   			return {};
	   			
	   		vector<string> nextMoves;
	   		
	   		for(int i(0);i<s.size()-1;i++)
	   		{
	   			if(s[i]=='+' && s[i+1]=='+')
	   			{
				   nextMoves.push_back(s);
					nextMoves.back()[i]=nextMoves.back()[i+1]='-';
				}
			}
			
			return nextMoves;
	   }
};

int main()
{
	 Solution s;
	 clock_t t;
	 t=clock();
	 for(auto i:s.flipGame("++++"))
	 	cout<<i;
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

