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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<int> res;
        midorder(root,res);
        int len=res.size();
        if(p->val==res[len-1])
            return nullptr;
        for(int i=0;i<len-1;i++)
        {
            if(res[i]==p->val)
            {
                TreeNode* output=new TreeNode(res[i+1]);
                    return output;
            }
        }
        return nullptr;
    }
    
    void midorder(TreeNode* root, vector<int>& res)
    {
        if(root==nullptr)
            return;
        midorder(root->left,res);
        res.push_back(root->val);
        midorder(root->right,res);
        return;
    }
};