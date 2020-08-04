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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n==0)
            return {};
        res=helper(1,n);
        return res;
    }
    vector<TreeNode*> helper(int start, int end)
    {
        vector<TreeNode*> res;
        if(start>end)
            return {nullptr};
        if(start==end)
        {
            TreeNode* cur=new TreeNode(start);
            res.push_back(cur);
            return res;
        }
        if(start<end)
        {
            for(int i=start;i<=end;i++)
            {
                vector<TreeNode*> l=helper(start,i-1);
                vector<TreeNode*> r=helper(i+1,end);
                for(int m=0;m<l.size();m++)
                    for(int n=0;n<r.size();n++)
                    {
                        TreeNode* tmp=new TreeNode(i);
                        tmp->left=l[m];
                        tmp->right=r[n];
                        res.push_back(tmp);
                    }
            }
        }
        return res;
    }
};

//分治法