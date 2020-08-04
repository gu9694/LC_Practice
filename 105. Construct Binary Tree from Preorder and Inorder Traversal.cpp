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
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int pl, int pr,
                 int il, int ir)
    {
        if(pl>pr||il>ir)
            return NULL;
        //find root
        int root=preorder[pl];
        int i=0;
        for(i=il;i<=ir;i++)
        {
            if(inorder[i]==root)
                break;
        }
        TreeNode* cur=new TreeNode(root);
        cur->left=dfs(preorder,inorder,pl+1,pl+i-il,il,i-1);
        cur->right=dfs(preorder,inorder,pl+i-il+1,pr,i+1,ir);
        return cur;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len=preorder.size();
        if(len==0)
            return NULL;
        TreeNode* res=dfs(preorder,inorder,0,len-1,0,len-1);
        return res;
        
    }
};

//一道稍微有点难度的dfs问题
//关键是两个数组的转换
//preorder 3 9 20 15 7
//inorder 9 3 15 20 7
//preorder的第0个元素永远是root
//根据preorder[0]划分inorder 形成左子树 右子树
//在inorder中找到的根的位置 再在preorder中进行左右子树的划分
