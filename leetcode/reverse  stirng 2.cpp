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
	   
	   //function prototype here
	   vector<char> reverseString(vector<char> s)
	   {
	   		if(s.empty())
	   			return {};
	   		vector<char> result;
	   		for(int i=s.size()-1;i>=0;i--)
	   		{
	   			vector<char> temp;
	   			while(i>=0 && s[i]!=' ')
					temp.insert(temp.begin(),s[i]),i--;
				result.insert(result.end(),temp.begin(),temp.end());
				result.push_back(' ');
//				for(auto j:result)
//					cout<<j<<" ";
//				cout<<endl;
			}
			return result;
	   }
};

int main()
{
	 Solution s;
	 vector<char> sent{'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};
	 clock_t t;
	 t=clock();
	 for(auto i:s.reverseString(sent))
	 cout<<i;
	 t = clock() - t ;
	 double time_taken=((double)t)/CLOCKS_PER_SEC;
	 cout<<endl<<"Time Taken By your Function :"+to_string(time_taken);
	 return 0;
}

