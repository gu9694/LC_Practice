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
    int closestValue(TreeNode* root, double target) {
        vector<int> res;
        mid(root,res);
        int len=res.size();
        if(target<=res[0])
            return res[0];
        if(target>=res[len-1])
            return res[len-1];
        int i=0;
        for(i=0;i<len-1;i++)
            if(res[i]<=target&&target<=res[i+1])
            {
                double first=abs(res[i]-target);
                double second=abs(res[i+1]-target);
                return first<second?res[i]:res[i+1];
            }
        return 0;
    }
    void mid(TreeNode* root,vector<int>& res)
    {
        if(root==nullptr)
            return;
        mid(root->left,res);
        res.push_back(root->val);
        mid(root->right,res);
        return;
        
    }
};