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
    int result=0;
    
    bool checkpalindrome(vector<int> &path)
    {
        int odd=0;
        for(auto &i:path)
            odd+=(i%2);
        return odd<=1;
    }
    
    void fun(TreeNode *root,vector<int> &path)
    {
        if(!root->left && !root->right)
            result+=checkpalindrome(path)?1:0;
        
        if(root->left)
        {
            path[root->left->val]++;
            fun(root->left,path);
            path[root->left->val]--;
        }
        if(root->right)
        {
            path[root->right->val]++;
            fun(root->right,path);
            path[root->right->val]--;
        }
    }
    
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> path(10,0);
        path[root->val]++;
        fun(root,path);
        return result;
    }
};

int main()
{
 Solution s;
 cout<<s.();
}

