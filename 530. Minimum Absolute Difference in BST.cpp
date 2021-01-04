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
    void find(TreeNode* root, unordered_map<int, int>& mymap, int& res) {
        if (root == NULL) {
            return;
        } else {
            for (auto i : mymap) {
                if (abs(i.first -  root -> val) < res) {
                    res = abs(i.first - root -> val);
                }
            }
            mymap[root -> val ++];
            find(root -> left, mymap, res);
            find(root -> right, mymap, res);
        }
        return;
    }
    int getMinimumDifference(TreeNode* root) {
        unordered_map<int, int> mymap;
        int res = INT_MAX;
        find(root, mymap, res);
        return res;
    }
};