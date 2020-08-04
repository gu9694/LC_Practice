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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(root,sum,res,tmp);
        return res;
    }
    
    void dfs(TreeNode* cur, int sum,vector<vector<int>>& res,vector<int>& tmp )
    {
        if(cur==nullptr)
            return;
        tmp.push_back(cur->val);
        if(sum==cur->val&&cur->left==nullptr&&cur->right==nullptr)
            res.push_back(tmp);
        if(cur->left!=nullptr)
            dfs(cur->left,sum-cur->val,res,tmp);
        if(cur->right!=nullptr)
            dfs(cur->right,sum-cur->val,res,tmp);
        tmp.pop_back();
        return;
    }
    
};

//和dfs差不多 4个参数