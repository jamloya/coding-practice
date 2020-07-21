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


void printPreOrder(TreeNode* root)
{
	 if(root==nullptr) return;
	 cout<<root->val<<" ";
	 printPreOrder(root->left),printPreOrder(root->right);
}


class Solution{
public:
	   Solution(){}
	   
	   pair<int,bool> isBalanced(TreeNode* root)
	   {
	   		if(root==nullptr)
	   			return {0,true};
	   		pair<int,bool> left=isBalanced(root->left);
	   		pair<int,bool> right=isBalanced(root->right);
	   		
	   		if(abs(left.first-right.first)>1 || (!left.second && !right.second))
	   			return {max(left.first,right.first)+1,false};
	   		return {max(left.first,right.first)+1,left.second && right.second};
	   }
	   
	   //function prototype here
	   bool isHeightBalanced(TreeNode* root)
	   {
	   		if(root==nullptr)
	   			return true;
	   		return isBalanced(root).second;
	   }
};

int main()
{
	 Solution s;
	 clock_t t;
	 t=clock();
	 TreeNode* root=new TreeNode(1);
	 root->left=new TreeNode(3);
	 root->right=new TreeNode(2);
	 root->right->left=new TreeNode(5);
	 root->right->right=new TreeNode(4);
	 //root->right->right->right=new TreeNode(9);
	 //root->right->right->right->right=new TreeNode(9);
	 cout<<s.isHeightBalanced(root);
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

