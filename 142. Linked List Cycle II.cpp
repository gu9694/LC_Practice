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
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr)
            return head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* res=head;
        while(fast->next!=nullptr&&fast->next->next!=nullptr)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            {
                while(slow!=res)
                {
                    res=res->next;
                    slow=slow->next;
                }
                return res;
            }
        }
        return nullptr;
    }
};