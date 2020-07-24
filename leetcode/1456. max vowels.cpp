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
	   int maxVowels(string s,int k)
	   {
	   		if(k>s.size())
	   			return 0;
	   			
	   			
	   		int vowels=0,ans=0;
			for(int i=0;i<k;i++)
				if(isVowel(s[i]))
					vowels++;
			ans=max(ans,vowels);
			for(int j=0;j<k+s.size();j++)
			{
				vowels-=isVowel(s[j]);
				vowels+=isVowel(s[j+k]);
				ans=max(ans,vowels);
		  	}	   		
		  	return ans;
	   }
};

int main()
{
	 Solution s;
	 clock_t t;
	 t=clock();
	 cout<<s.maxVowels("abciidefeee",3);
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

