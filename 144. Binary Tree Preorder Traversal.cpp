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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* tmp=root;
        stack<TreeNode*> myst;
        while(tmp!=NULL || myst.empty()==false)
        {
            while(tmp!=NULL)
            {
                res.push_back(tmp->val);
                myst.push(tmp);
                tmp=tmp->left;
            }
            if(myst.empty()==false)
            {
                tmp=myst.top();
                myst.pop();
                tmp=tmp->right;
            }
        }
        return res;
    }
};