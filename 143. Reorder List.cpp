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
    void reorderList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
            return;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=nullptr&&fast->next->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* l1=head;
        ListNode* l2=slow->next;
        slow->next=nullptr;
        ListNode* l2r=reverse(l2);
        while(l2r!=nullptr)
        {
            ListNode* tmp=l1->next;
            l1->next=l2r;
            l2r=l2r->next;
            l1->next->next=tmp;
            l1=tmp;
        }

    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* res=nullptr;
        if(head==nullptr||head->next==nullptr)
            return head;
        ListNode* cur=head;
        while(cur!=nullptr)
        {
            ListNode* tmp=cur->next;
            cur->next=res;
            res=cur;
            cur=tmp;
        }
        return res;
    }
};

//翻转链表
//插入链表