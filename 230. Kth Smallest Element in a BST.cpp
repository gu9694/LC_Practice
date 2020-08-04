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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        dfs(root,res);
        //sort(res.begin(),res.end());
        return res[k-1];
    }
    
    void dfs(TreeNode* root, vector<int>& res)
    {
        if(root==nullptr)
            return;
        dfs(root->left,res);
        res.push_back(root->val);
        dfs(root->right,res);
        return;
    }
};

//BST中序遍历输出为排序数组