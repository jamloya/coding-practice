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
	   
	   TreeNode* find(TreeNode* root,int k,unordered_map<TreeNode*,TreeNode*> parent)
	   {
	   		if(root->val==k)
	   			return root;
	   		if(root->left)
	   		{
	   			parent[root->left]=root;
	   			TreeNode* left=find(root->left,k,parent);
				if(left)
	   				return left;
			}
			if(root->right)
			{
				parent[root->right]=root;
				TreeNode* right=find(root->right,k,parent);
				if(right)
					return right;
			}
			return nullptr;
	   }
	   
	   //function prototype here
	   TreeNode* nearestLeaf(TreeNode* root,int k)
	   {
	   		unordered_map<TreeNode*,TreeNode*> parent;
	   		unordered_set<TreeNode*> visited;
	   		
			// finding the target node and also storing the parents of the node
			//then do bfs on the root 
			//moving on both side i.e. downwards and upwards and the first leaf we found
			//is the nearest leaf
			
			TreeNode* targetNode=find(root,k,parent);
	   		queue<TreeNode*> bfs;   
			bfs.push(targetNode);
	   		visited.insert(targetNode);
	   		while(!bfs.empty())
	   		{
	   			TreeNode* current=bfs.front();
	   			bfs.pop();
	   			if( current->left==nullptr && current->right==nullptr )
	   				return current;
	   			
	   			if(current->left && visited.find(current->left)==visited.end() )
	   			{
	   				bfs.push(current->left);
					visited.insert(current->left);	
				}
				if(current->right && visited.find(current->right) == visited.end() )
				{
					bfs.push(current->right);
					visited.insert(current->right);
				}
				if(parent.find(current) == parent.end() && visited.find(parent[current])==visited.end() )
				{
					bfs.push(parent[current]);
					visited.insert(parent[current]);
				}
			}
			return nullptr;
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
	 cout<<s.nearestLeaf(root,2)->val;
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

