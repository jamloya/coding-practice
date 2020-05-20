#include<bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int result;
    void helper(TreeNode* root,int &k)
    {
        if(root==nullptr)
            return ;
        helper(root->left,k);
        if(--k==0)result=root->val;
        helper(root->right,k);
        
    }
    
    
    int kthSmallest(TreeNode* root, int k) {
        helper(root,k);
        return result;
    }
};

int main()
{
 Solution s;
 cout<<s.();
}

