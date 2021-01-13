/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int res = 1;
        if (root == nullptr) {
            return 0;
        } else {
            queue<pair<TreeNode*, unsigned long long>> myq;
            myq.push({root, 1});
            while(myq.empty() == false) {
                res = max(res, int(myq.back().second - myq.front().second + 1));
                unsigned long long len = myq.size();
                for (int i = 0; i < len; i ++) {
                    TreeNode* root = myq.front().first;
                    unsigned long long pos = myq.front().second;
                    myq.pop();
                    if (root -> left != nullptr) {
                        myq.push({root -> left, pos * 2});
                    }
                    if (root -> right != nullptr) {
                        myq.push({root -> right, pos * 2 + 1});
                    }
                }
            }
        }
        return res;
    }
};