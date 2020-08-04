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
    bool isBalanced(TreeNode* root) {
         if(root==NULL)
             return true;
        else
        {
            int hl=height(root->left);
            int hr=height(root->right);
            return (abs(hl-hr)<=1&&isBalanced(root->left)&&isBalanced(root->right));
        }
    }
private:
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        else
        {
            return max(height(root->left),height(root->right))+1;
        }
    }
};


//高度判断函数
//两个递归