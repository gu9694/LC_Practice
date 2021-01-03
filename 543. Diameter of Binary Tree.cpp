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
private:
    int len = 0;
public:
    int depth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        } else {
            int left = depth(root -> left);
            int right = depth(root -> right);
            len = max(len, left + right);
            return max(left, right) + 1;
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = depth(root);
        return len;
    }
};