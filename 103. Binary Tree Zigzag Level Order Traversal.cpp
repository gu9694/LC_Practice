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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr)
        {
            return res;
        }
        queue<TreeNode*> myq;
        myq.push(root);
        int mark=1;
        while(myq.empty()==false)
        {
            vector<int> tmp;
            int len=myq.size();
            for(int i=0;i<len;i++)
            {
                TreeNode* cur=myq.front();
                tmp.push_back(cur->val);
                myq.pop();
                if(cur->left!=nullptr)
                    myq.push(cur->left);
                if(cur->right!=nullptr)
                    myq.push(cur->right);
            }
            if(mark%2==0)
                reverse(tmp.begin(),tmp.end());
            mark++;
            res.push_back(tmp);
        }
        return res;

    }
};

//bfs
//reverse函数