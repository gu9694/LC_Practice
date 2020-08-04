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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<int> res;
        dfs(root,res,0);
        return res;
    }
private:
    void dfs(TreeNode* root,vector<int>& res, int level)
    {
        if(root==NULL)
            return;
        if(level==res.size())
            res.push_back(root->val);
        dfs(root->right,res,level++);
        dfs(root->left, res,level++);
    }
};