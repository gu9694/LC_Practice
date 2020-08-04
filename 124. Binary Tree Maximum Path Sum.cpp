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
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        dfs(root,res);
        return res;
    }
    
    int dfs(TreeNode* root,int& res)
    {
        if(root==nullptr)
            return 0;
        int left=max(0,dfs(root->left,res));
        int right=max(0,dfs(root->right,res));
        res=max(res,left+right+root->val);
        return max(left,right)+root->val;
    }
};

//dfs返回值是以当前节点为结束点的最大值
//要更新两个东西 res保存最终的结果，return保存以当前节点为终点的最大路径