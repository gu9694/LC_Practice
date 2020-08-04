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
    ListNode* swapPairs(ListNode* head) {
        ListNode* res=new ListNode(0);
        ListNode* respre=res;
        ListNode* tmp=head;
        if(head==nullptr||head->next==nullptr)
            return head;
        while(tmp!=nullptr&&tmp->next!=nullptr)
        {
            int first=tmp->next->val;
            int second=tmp->val;
            ListNode* fst=new ListNode(first);
            respre->next=fst;
            respre=respre->next;
            ListNode* snd=new ListNode(second);
            respre->next=snd;
            respre=respre->next;
            tmp=tmp->next->next;
        }
        respre->next=tmp;
        return res->next;
    }
};