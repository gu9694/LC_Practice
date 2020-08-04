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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==nullptr)
            return false;
        if(root!=nullptr&&root->val==sum&&root->left==nullptr&&root->right==nullptr)
            return true;
        bool judge1=hasPathSum(root->left, sum-root->val);
        bool judge2=hasPathSum(root->right, sum-root->val);
        return judge1||judge2;
    }
};