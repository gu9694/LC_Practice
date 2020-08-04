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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL)
            return true;
        if(p==NULL&&q!=NULL)
            return false;
        if(p!=NULL&&q==NULL)
            return false;
        if(p->val!=q->val)
            return false;
        else if(p->val==q->val)
        {
            bool l=isSameTree(p->left,q->left);
            bool r=isSameTree(p->right,q->right);
            return (l&&r);
        }
        return true;
    }
};

//注意第二和第三个if判断语句 不能忽略第二和第三个直接跳到第四个if
