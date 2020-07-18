/*
	Question:Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, 
	repeat until the tree is empty.

*/

#include<bits/stdc++.h>

using namespace std;


class TreeNode{
public:
	int val;
	TreeNode* left,*right;;
	
	TreeNode(int val){
		this->val=val;
		this->left=nullptr;
		this->right=nullptr;
	}
};

class Solution{
public:
	   Solution(){}
	   
	   vector<vector<int>> result;
	   int dfs(TreeNode* root)
	   {
	   		if(root==nullptr)
	   			return 0;
	   			
	   		int l=dfs(root->left);
	   		int r=dfs(root->right);
	   		int reverseDepth=max(l,r);
	   		if(result.size()==reverseDepth)
	   			result.push_back({root->val});
	   		else
	   			result[reverseDepth].push_back(root->val);
	   		return reverseDepth+1;
	   		
	   }
	   
	   //function prototype here
	   vector<vector<int>> findLeaves(TreeNode* root)
	   {
	   		dfs(root);
	   		return result;
	   }
	   
};

int main()
{
	 Solution s;
	 
	 TreeNode *root=new TreeNode(1);
	 root->left=new TreeNode(2);
	 root->right=new TreeNode(3);
	 root->left->left=new TreeNode(4);
	 root->left->right=new TreeNode(5);
	 clock_t t;
	 t=clock();
	 for(auto i:s.findLeaves(root))
	 {
	 	for(auto j:i)
	 		cout<<j<<" ";
	 		
	 	cout<<endl;
	 }
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

