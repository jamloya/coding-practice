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
	   bool flipGame2(string s)
	   {

	   		for(int i(0);i<s.size()-1;i++)
	   		{
	   			if(s[i]=='+' && s[i+1]=='+')
	   			{
	   				if(!flipGame2(s.substr(0,i)+"--"+s.substr(i+2)))
	   					return true;
				}
			}
			
			return false;
	   }
};

int main()
{
	 Solution s;
	 clock_t t;
	 t=clock();
	 cout<<s.flipGame2("------");
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

