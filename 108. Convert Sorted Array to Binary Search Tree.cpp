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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* res;
        res=arrange(nums,0,nums.size()-1);
        return res;
    }
private:
    TreeNode* arrange(vector<int>& nums, int start,int end)
    {
        if(start>end)
            return NULL;
        TreeNode* res=new TreeNode(0);
        res->val=nums[(start+end)/2];
        res->left=arrange(nums, start, (start+end)/2-1);
        res->right=arrange(nums,(start+end)/2+1,end);
        return res;
    }
};