/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        vector<int> res;
        ListNode* tmp=head;
        while(tmp!=nullptr)
        {
            res.push_back(tmp->val);
            tmp=tmp->next;
        }
        reverse(res,m,n);
        ListNode* l2=new ListNode(0);
        ListNode* cur=l2;
        for(int i=0;i<res.size();i++)
        {
            ListNode* newnode=new ListNode(res[i]);
            cur->next=newnode;
            cur=cur->next;
        }
        cur->next=nullptr;
        return l2->next;
    }
    
    void reverse(vector<int>& res,int m, int n)
    {
        while(m<n)
        {
            swap(res[m-1],res[n-1]);
            m++;
            n--;
        }
    }
};