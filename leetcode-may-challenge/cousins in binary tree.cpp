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
    
    int getLevel(TreeNode* root,int x,int depth)
    {
        if(root==nullptr)
            return 0;
        if(root->val==x)
            return depth;
        int l=getLevel(root->left,x,depth+1);
        return l==0?getLevel(root->right,x,depth+1):l;
    }
    
    TreeNode* getParent(TreeNode *root,int x)
    {
        if (root==nullptr)
            return nullptr;
        
        if(root->left!=nullptr && root->left->val==x)
            return root;
        
        if(root->right!=nullptr && root->right->val==x)
            return root;
        
        TreeNode* parent=getParent(root->left,x);
        return parent==nullptr?getParent(root->right,x):parent;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        //cout<<getLevel(root,x,0)<<getLevel(root,y,0);
        return getLevel(root,x,0)==getLevel(root,y,0) && getParent(root,x)!=getParent(root,y);
    }
};
