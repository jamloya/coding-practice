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
	   
	   bool checkForTarget(TreeNode* root1,int val,int target)
	   {
	   		if(root1==nullptr)
	   			return false;
	   			
	   		return root1->val+val==target?true: checkForTarget(root1->left,val,target) || checkForTarget(root1->right,val,target);
	   }
	   
	   //function prototype here
	   bool twosumbst(TreeNode* root1,TreeNode* root2,int target)
	   {
	   		if(root2==nullptr)
	   			return false;
	   		return checkForTarget(root1,root2->val,target) || twosumbst(root1,root2->left,target) || twosumbst(root1,root2->right,target);
	   }
};

int main()
{
	 Solution s;
	 TreeNode *root1=new TreeNode(2);
	 root1->left=new TreeNode(1);
	 root1->right=new TreeNode(4);
	 TreeNode *root2=new TreeNode(1);
	 root2->left=new TreeNode(0);
	 root2->right=new TreeNode(3);
	 clock_t t;
	 t=clock();
	 cout<<s.twosumbst(root1,root2,5);
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

