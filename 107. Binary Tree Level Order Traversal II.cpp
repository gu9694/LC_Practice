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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr)
            return res;
        queue<TreeNode*> myq;
        myq.push(root);
        while(myq.empty()==false)
        {
            vector<int> tmp;
            int len=myq.size();
            for(int i=0;i<len;i++)
            {
                TreeNode* cur=myq.front();
                myq.pop();
                tmp.push_back(cur->val);
                if(cur->left!=nullptr)
                    myq.push(cur->left);
                if(cur->right!=nullptr)
                    myq.push(cur->right);
                
            }
            res.push_back(tmp);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

//queue不能用下标访问！！！！
//如果怕tmp不能清空的问题，就在每次while开始后定义tmp 定义在循环体内部