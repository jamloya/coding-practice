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
	   
	   bool check(vector<int> count)
	   {
	   		int allowed=1;
	   		for(auto i:count)
	   			allowed-=i%2;
	   		return allowed>=0;
	   }
	   
	   void helper(TreeNode* root,vector<int> &count,int &numberOfPaths)
	   {
	   		count[root->val]++;
	   		if(root->left)
			   helper(root->left,count,numberOfPaths);
	   		if(root->right)
				helper(root->right,count,numberOfPaths);
			if(root->right==nullptr && root->left==nullptr)
	   			if(check(count))
	   				numberOfPaths++;		
	   		count[root->val]--;
	   }
	   
	   //function prototype here
	   int pseduPalindromePath(TreeNode* root)
	   {
	   		if(root==nullptr)
	   			return 0;
	   		int numberOfPaths=0;
	   		vector<int> count(10,0);
	   		helper(root,count,numberOfPaths);
	   		return numberOfPaths;
	   }
};

int main()
{
	 Solution s;
	 TreeNode* root=new TreeNode(2);
	 root->left=new TreeNode(3);
	 root->left->left=new TreeNode(3);
	 root->left->right=new TreeNode(1);
	 root->right=new TreeNode(1);
	 root->right->right=new TreeNode(1);
	 clock_t t;
	 t=clock();
	 cout<<s.pseduPalindromePath(root);
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

