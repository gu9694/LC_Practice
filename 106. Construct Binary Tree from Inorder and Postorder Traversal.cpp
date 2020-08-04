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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len=inorder.size();
        if(len==0)
            return nullptr;
        return dfs(inorder,postorder,0,len-1,0,len-1);
        
    }
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int il,int ir, int pl,int pr)
    {
        if(il>ir||pl>pr)
            return nullptr;
        TreeNode* root=new TreeNode(postorder[pr]);
        int i=0;
        for(i=il;i<inorder.size();i++)
        {
            if(inorder[i]==root->val)
                break;
        }
        
        root->left=dfs(inorder,postorder,il,i-1,pl,pl+i-il-1);
        root->right=dfs(inorder,postorder,i+1,ir,pl+i-il,pr-1);
        return root;
    }
};

//注意递归函数几个参数的index