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
	    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        	if(dominoes.empty())
        		return 0;
        	unordered_set<pair<int,int>> uSet;
        	int numberOfPairs=0
        	for(auto domino:dominoes)
        	{
        		if(uSet.find(domino)!=uSet.end())
        			numberOfPairs++;
        		else
        		{
        			uSet.insert({domino[1],domino[0]});
        			uSet.insert({domino[0],domino[1]});
				}
			}
			return numberOfPairs;
    	}
};

int main()
{
	 Solution s;
	 clock_t t;
	 t=clock();
	 cout<<s.();
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

