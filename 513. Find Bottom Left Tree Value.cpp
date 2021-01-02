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
    void post(TreeNode* root, unordered_map<int, vector<int>>& mymap, int level) {
        if (root == nullptr) {
            return;
        } else {
            post(root -> left, mymap, level + 1);
            mymap[level].push_back(root -> val);
            post(root -> right, mymap, level + 1);
            return;
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        unordered_map<int, vector<int>> mymap;
        int level = 0;
        post(root, mymap, level);
        int bottom = 0;
        for (auto i : mymap) {
            bottom = max(bottom, i.first);
        }
        int res = 0;
        for (auto i : mymap) {
            if (i.first == bottom) {
                res = i.second[0];
            }
        }
        return res;
    }
};