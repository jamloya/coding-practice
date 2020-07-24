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
	   vector<int> processQueries(vector<int> queries ,int m)
	   {
	   		vector<int> initialPerm,processedResult;
	   		for(int i=1;i<=m;i++)
	   			initialPerm.push_back(i-1);
	   		
	   		for(int i=0;i<queries.size();i++)
	   		{
	   			int currentPos=initialPerm[queries[i]-1];
				processedResult.push_back(currentPos);
				for(int j=0;j<currentPos;j++)
					initialPerm[j]++;
				initialPerm[queries[i]-1]=0;	
			}
			return processedResult;
	   }
};

int main()
{
	 Solution s;
	 clock_t t;
	 t=clock();
	 for(auto i:s.processQueries({7,5,5,8,3},8))
	 	cout<<i<<" ";
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

