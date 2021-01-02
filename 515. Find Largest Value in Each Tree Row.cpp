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
        if (!root) {
            return;
        } else {
            if (!mymap[level].size()) {
                mymap[level].push_back(root->val);
            }
            else {
                mymap[level][0] = max(root -> val, mymap[level][0]);
            }
            post(root -> left, mymap, level + 1);
            post(root -> right, mymap, level + 1);
            return;
        }
        return;
    }
    vector<int> largestValues(TreeNode* root) {
        unordered_map<int, vector<int>> mymap;
        vector<int> res;
        vector<int> level;
        post(root, mymap, 0);
        for (auto i :mymap) {
            level.push_back(i.first);
        }
        sort(level.begin(), level.end());
        for (auto i : level) {
            res.push_back(mymap[i][0]);
        }
        return res;
    }
};