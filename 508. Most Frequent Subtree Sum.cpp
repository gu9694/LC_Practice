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
    int TreeSum(TreeNode* root, unordered_map<int, int>& mymap) {
        int sum = 0;
        if (root == NULL) {
            return 0;
        } else {
            sum = root -> val + TreeSum(root -> left, mymap) + TreeSum(root -> right, mymap);
            mymap[sum] ++;
        }
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> mymap;
        TreeSum(root, mymap);
        vector<int> res;
        int max = 0;
        for (auto i : mymap) {
            if (i.second > max) {
                max = i.second;
            }
        }
        for (auto i : mymap) {
            if (i.second == max) {
                res.push_back(i.first);
            }
        }
        return res;
    }
};