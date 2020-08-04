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
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* tmp=root;
        stack<TreeNode*> myst;
        vector<int> res;
        while(tmp!=nullptr || myst.empty()==false)
        {
            while(tmp!=nullptr)
            {
                res.push_back(tmp->val);
                myst.push(tmp);
                tmp=tmp->right;
            }
            if(myst.empty()==false)
            {
                tmp=myst.top();
                myst.pop();
                tmp=tmp->left;
            }
        }
        int len=res.size();
        vector<int> final_res(len);
        for(int i=0;i<len;i++)
            final_res[i]=res[len-1-i];
        return final_res;
    }
};