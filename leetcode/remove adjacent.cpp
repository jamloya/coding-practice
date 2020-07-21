#include<bits/stdc++.h>

using namespace std;

class TreeNode
{
 public:
	  int val;
	  TreeNode *left,*right;

 TreeNode(int value) : val(value),left(nullptr),right(nullptr){}
};

class Node
{
 public:
 		int val;
 		Node *next;
 		
  Node(int value) : val(value),next(nullptr) {}
};


class Solution{
public:
	   Solution(){}
	   
	   
	   //assuming there is no spaces in the string given
	   void removeadjacent(string s,string &result,int index,bool flag)
	   {
	   		if(index==s.size())
	   			return ;
	   		if(result.back()==s[index])
	   		{
			   removeadjacent(s,result,index+1,true);
			   return;
			}
	   		if(flag)
	   		{
	   			result.pop_back();
	   			removeadjacent(s,result,index,false);
			}
			else
			{
				result.push_back(s[index]);
				removeadjacent(s,result,index+1,false);
			}
	   }
	   
	   
	   //function prototype here
	   string removealladjacent(string s)
	   {
	   		if(s.empty())
	   			return "";
	   		string result=" ";
	   		removeadjacent(s,result,0,false);
	   		result.erase(result.begin());
	   		return result;
	   }
};

int main()
{
	 Solution s;
	 clock_t t;
	 t=clock();
	 cout<<s.removealladjacent("azxxzy");
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

