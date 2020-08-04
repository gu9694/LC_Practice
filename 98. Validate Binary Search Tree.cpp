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
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)
            return true;
        bool res= dfs(root,LONG_MIN,LONG_MAX);
        return res;
    }
    bool dfs(TreeNode* root, long long int min, long long int max)
    {
        if(root==nullptr)
            return true;
        if(root->val>=max||root->val<=min)
            return false;
        bool a=dfs(root->left,min,root->val);
        bool b=dfs(root->right,root->val,max);
        return a&&b;
    }
};

\\注意判断的条件
\\第二种方法是判断中序遍历是否递增