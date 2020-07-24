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
	   
	   //function prototype here
	   int minimumKnightMoves(int x,int y)
	   {
	   		vector<pair<int,int>> dir{ {-1,2},{1,2},{2,1},{2,-1},{-1,-2},{1,-2},{-2,1},{-2,-1} };
	   		queue<pair<int,int>> bfs;
	   		bfs.push({0,0});
	   		int step=0;
	   		while(true)
	   		{
	   			int size=bfs.size();
				while(size--)
				{
					pair<int,int> current=bfs.front();bfs.pop();
					
					if(current.first==x && current.second==y)
						return step;
					for(auto direction:dir)
						bfs.push({ current.first+direction.first, current.second+direction.second });				
				}
				step++;
			}
	   		return -1;
	   }
	   
};

int main()
{
	 Solution s;
	 clock_t t;
	 t=clock();
	 cout<<s.minimumKnightMoves(5,5);
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

