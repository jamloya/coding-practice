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
	   int res=0;
	   
	   //O(n) -time 
	   //o(n) -space (stack used)  in worst case
	   //assuming that there are no negative number in tree
	   //if there  are change this to helper function  and value passed as argument prev make it atleast so it has diffrence two with the root value
	   int longestConsecutiveSequence(TreeNode* root,int curr=1,int prev=INT_MIN)
	   {
	   		if(root==nullptr)
	   			return res;
			
			curr=prev+1==root->val?curr+1:1;
			res=max(res,curr);
			
			longestConsecutiveSequence(root->left,curr,root->val);
			longestConsecutiveSequence(root->right,curr,root->val);
			return res;
	   }
};

int main()
{
	 Solution s;
	 clock_t t;
	 t=clock();
	 TreeNode* root=new TreeNode(1);
	 root->right=new TreeNode(3);
	 root->right->left=new TreeNode(2);
	 root->right->right=new TreeNode(4);
	 root->right->right->right=new TreeNode(5);
	 cout<<s.longestConsecutiveSequence(root);
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

