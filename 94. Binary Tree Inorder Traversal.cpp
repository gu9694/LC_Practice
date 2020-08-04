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
        TreeNode* tmp=root;
        stack<TreeNode*> myst;
        vector<int> res;
        while(tmp!=NULL||myst.empty()==false)
        {
            while(tmp!=NULL)
            {
                myst.push(tmp);
                tmp=tmp->left;
            }
            if(myst.empty()==false)
            {
                tmp=myst.top();
                res.push_back(tmp->val);
                myst.pop();
                tmp=tmp->right;
            }
        }
        return res;
    }
};