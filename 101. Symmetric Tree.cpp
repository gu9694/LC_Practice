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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        bool res=cmproot(root->left,root->right);
        return res;
    }
    
    bool cmproot(TreeNode *p, TreeNode *q)
    {
        if(p==NULL&&q==NULL)
            return true;
        if(p!=NULL&&q==NULL)
            return false;
        if(p==NULL&&q!=NULL)
            return false;
        if(p->val!=q->val)
            return false;
        if(p->val==q->val)
        {
            bool a1=cmproot(p->left,q->right);
            bool a2=cmproot(p->right,q->left);
            bool res= a1&&a2;
            return res;
        }
        return true;
    }
};