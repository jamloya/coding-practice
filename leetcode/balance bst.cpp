#include<bits/stdc++.h>

using namespace std;
class TreeNode
{
 public:
	  int val;
	  TreeNode *left,*right;

 TreeNode(int value) : val(value),left(nullptr),right(nullptr){}
};

class Trie
{
	public:
		vector<Trie*> next;
		bool isWord;

	Trie()
	{
		next.resize(26,nullptr);
		isWord=false;
	}

	void add(string word)
	{
		Trie* root=this;
		for(auto character : word)
		{
			character=tolower(character);
			if(root->next[character-'a']==nullptr)
				root->next[character-'a']=new Trie();
			root=root->next[character-'a'];
		}
		this->isWord=true;
	}

	bool search(string word,bool checkSubstring=false)
	{
		Trie* root=this;
		for(auto character:word)
		{
			character=tolower(character);
			if(root->next[character-'a']!=nullptr)
				root=root->next[character-'a'];
			else
				return false;
		}
		if(checkSubstring==false)
			return root->isWord;
		else
			return true;
	}
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

bool isVowel(char c)
{
	 return c=='a' || c=='A' || c=='e' || c=='E' ||
	 c=='i' || c=='I' || c=='o' || c=='O' ||
	 c=='u' || c=='U' ;
}

class Solution{
public:
	   Solution(){}
	   
	   
	   //only works for a flatten binary search tree
	   void reshiftleft(TreeNode* root)
	   {
	   		
	   		TreeNode* temp=root->left;
	   		while(temp->right!=nullptr)
	   			{
	   				
				   temp=temp->right;
			}
	   		temp->right=root;
	   		temp=root->left;
	   		*root=*temp;
	   		//printPreOrder(root);
	   }
	   
	   void reshiftright(TreeNode* root)
	   {
	   		TreeNode* temp=root->right;
	   		while(temp->left!=nullptr)
	   			temp=temp->left;
	   		temp->left=new TreeNode(root->val);
	   		temp=root->right;
	   		*root=*temp;
	   }
	   
	   int helper(TreeNode* root)
	   {
	   		if(root==nullptr)
			   return 0;
	   		
	   		int l=helper(root->left);
	   		int r=helper(root->right);
	   		
	   		if( l-r > 1)
				reshiftleft(root);
			if( l-r < -1 )
				reshiftright(root);	   		
	   		return max(l,r)+1;

	   }
	   
	   
	   //function prototype here
	   TreeNode* balance(TreeNode* root)
	   {
	   		if(root==nullptr)
	   		{
	   			return root;	
			}
			helper(root);
			return root;
	   }

};

int main()
{
	 Solution s;
	 TreeNode* root=new TreeNode(4);
	 root->left=new TreeNode(3);
	 root->left->left=new TreeNode(2);
	 root->left->left->left=new TreeNode(1);
	 root->right=new TreeNode(5);
	 root->right->right=new TreeNode(6);
	 root->right->right->right=new TreeNode(7);
	 clock_t t;
	 t=clock();
	 root=s.balance(root);
	 printPreOrder(root);
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

