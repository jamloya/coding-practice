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
	   
	   pair<int,int> dfs(TreeNode* root,double &max_avg)
	   {
	   		if(root==nullptr)
	   			return {0,0};
	   		
	   		pair<int,int> left=dfs(root->left,max_avg);
	   		pair<int,int> right=dfs(root->right,max_avg);
	   		
	   		pair<int,int> current{0,0};
	   		current.first=left.first+right.first+root->val;
	   		current.second=left.second+right.second+1;
	   		
	   		max_avg=max(max_avg, (double) current.first/current.second );
	   		return current;
	   }
	   
	   //function prototype here
	   double maximumAverageSubtree(TreeNode* root) {
	   		if(!root)
	   			return 0.0;
	   		double max_avg=0;
	   		dfs(root,max_avg);
	   		return max_avg;
	   }
};

int main()
{
	 Solution s;
	 TreeNode* root=new TreeNode(7);
	 root->left=new TreeNode(6);
	 root->right=new TreeNode(6);
	 clock_t t;
	 t=clock();
	 cout<<s.maximumAverageSubtree(root);
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

