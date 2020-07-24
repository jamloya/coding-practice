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
	   
	   int find(int x,vector<int> parent)
	   {
	   		if(x==parent[x])
	   			return x;
	   		return find(parent[x],parent);
	   }
	   
	   //function prototype here
	   string smallestString(string s,vector<vector<int>> pairs)
	   {
	   		if(s.size()==0)
	   			return "";
	   			
	   		vector<int> parent;
	   		for(int i=0;i<s.size();i++)
	   			parent.push_back(i);
	   			
	   		for(int i=0;i<pairs.size();i++)
	   		{
	   			int first=find(pairs[i][0],parent);
				int second=find(pairs[i][1],parent);
				if(first!=second)	
					parent[first]=second;
			}
			
			vector<vector<int>> cycles(s.size());
			
			for(auto i(0);i<s.size();i++)
				cycles[find(i,parent)].push_back(i);
				
			for(auto curr:cycles)
			{
				string cycleString="";
				for(auto i:curr)
					cycleString+=s[i];
				sort(cycleString.begin(),cycleString.end());
				
				for(auto i(0);i<curr.size();i++)
					s[curr[i]]=cycleString[i];
				
			}
			
			return s;
			
	   }
};

int main()
{
	 Solution s;
	 clock_t t;
	 t=clock();
	 cout<<s.smallestString("dcab",{{0,3},{1,2},{0,2}});
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

