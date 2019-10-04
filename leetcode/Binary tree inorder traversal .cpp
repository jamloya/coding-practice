/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* current=root;
        int i=0;
        
        while(current !=NULL)
        {    
            if(current->left==NULL)
            {   //cout<<++i<<current->val<<"H"<<endl;
                result.push_back(current->val);
                current=current->right;
            }
            else
            { //cout<<++i<<current->val<<"L"<<endl;
                TreeNode* pre=current->left;
                while(pre->right!=NULL)
                {
                    pre=pre->right;
                }
                pre->right=current;
                TreeNode* temp=current;
                current=current->left;
                temp->left=NULL;
            }
        }
        return result;
    }
};
