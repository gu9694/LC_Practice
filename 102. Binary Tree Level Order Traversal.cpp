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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> myq;
        if(root==nullptr)
            return res;
        myq.push(root);
        while(myq.empty()==false)
        {
            int cur_num=myq.size();
            vector<int> cur_node;
            for(int i=0;i<cur_num;i++)
            {
                TreeNode* t=myq.front();
                myq.pop();
                cur_node.push_back(t->val);
                if(t->left!=nullptr)
                    myq.push(t->left);
                if(t->right!=nullptr)
                    myq.push(t->right);
                
            }
            res.push_back(cur_node);
        }
        return res;
            
    }
};

//bfs的条件就是while不为空
//queue pop除队头元素 front取队头元素引用