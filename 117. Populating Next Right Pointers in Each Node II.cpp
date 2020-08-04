/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr)
            return root;
        queue<Node*> myq;
        myq.push(root);
        while(myq.empty()==false)
        {
            int len=myq.size();
            if(len==1)
            {
                Node* cur=myq.front();
                myq.pop();
                if(cur->left!=nullptr)
                {
                    myq.push(cur->left);
                }
                if(cur->right!=nullptr)
                {
                    myq.push(cur->right);
                }
                cur->next=nullptr;
            }
            else
            {
                for(int i=0;i<len-1;i++)
                {
                    Node* cur=myq.front();
                    if(cur->left!=nullptr)
                    {
                        myq.push(cur->left);
                    }
                    if(cur->right!=nullptr)
                    {
                        myq.push(cur->right);
                    }
                    myq.pop();
                    cur->next=myq.front();
                }

                Node* last=myq.front();
                if(last->left!=nullptr)
                {
                    myq.push(last->left);
                }
                if(last->right!=nullptr)
                {
                    myq.push(last->right);
                }
                myq.pop();
                last->next=nullptr;
            }
        }
        return root;
    }
};