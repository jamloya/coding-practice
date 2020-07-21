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
	   
	   
	   TreeNode* helper(TreeNode* root)
	   {
	   		if(root==nullptr)
	   			return nullptr;
	   			
	   		TreeNode* newRoot=new TreeNode(root->val);
	   		newRoot->left=helper(root->right);
	   		newRoot->right=helper(root->left);
	   		return newRoot;
	   }
	   
	   //function prototype here
	   TreeNode* mirror(TreeNode* root)
	   {
	   		if(!root)
	   			return nullptr;
	   		return helper(root);
	   }
};

int main()
{
	 Solution s;
	 TreeNode* root=new TreeNode(1);
	 root->left=new TreeNode(3);
	 root->right=new TreeNode(2);
	 root->right->left=new TreeNode(5);
	 root->right->right=new TreeNode(4);
	 clock_t t;
	 t=clock();
	 printPreOrder(root);
	 cout<<endl;
	 TreeNode* mirrorRoot=s.mirror(root);
	 printPreOrder(mirrorRoot);
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

