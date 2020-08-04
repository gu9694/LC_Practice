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
	ListNode* partition(ListNode* head, int x) {
        ListNode* more=new ListNode(0);
        ListNode* less=new ListNode(0);
        ListNode* more_record=more;
        ListNode* less_record=less;
        ListNode* tmp=head;
        while(tmp!=nullptr)
        {
            if(tmp->val<x)
            {
                less_record->next=tmp;
                less_record=less_record->next;
            }
            if(tmp->val>=x)
            {
                more_record->next=tmp;
                more_record=more_record->next;
            }
            tmp=tmp->next;
        }
        less_record->next=more->next;
        more_record->next=nullptr;
        return less->next;
        
    }
};