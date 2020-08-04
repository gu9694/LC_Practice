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
    int countNodes(TreeNode* root) {
        vector<int> res;
        dfs(root,res);
        return res.size();
    }
    void dfs(TreeNode* root, vector<int>& res)
    {
        if(root==nullptr)
            return;
        else
        {
            res.push_back(1);
            dfs(root->left,res);
            dfs(root->right,res);
        }
    }

};