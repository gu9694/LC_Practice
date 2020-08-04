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
    int minDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int res=helper(root);
        return res;
    }
    
    int helper(TreeNode* cur)
    {
        if(cur==nullptr)
            return 0;
        if(cur->left==nullptr&&cur->right==nullptr)
            return 1;
        if(cur->left==nullptr&&cur->right!=nullptr)
            return 1+helper(cur->right);
        if(cur->left!=nullptr&&cur->right==nullptr)
            return 1+helper(cur->left);
        if(cur->left!=nullptr&&cur->right!=nullptr)
        {
            int dep=min(helper(cur->left),helper(cur->right));
            return dep+1;
        }
        return 0;
    }
};