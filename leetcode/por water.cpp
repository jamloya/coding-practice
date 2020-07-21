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

class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        while (V--) drop(heights, K);
        return heights;    
    }
private:
    void drop(vector<int>& heights, int K) {
        int best = K;
        for (int d = -1; d <= 1; d += 2) {
            int i = K + d;
            while (i >= 0 && i < heights.size() && heights[i] <= heights[i - d] ) 
			{
                if (heights[i] < heights[best]) best = i;
                i += d;
            }
            if (best != K) break;
        }
        ++heights[best];
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

