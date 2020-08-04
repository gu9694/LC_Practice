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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current;
        current=head;
        while(current!=nullptr)
        {
            ListNode* runner=current->next;
            while(runner!=nullptr&&runner->val==current->val)
            {
                runner=runner->next;
            }
            current->next=runner;
            current=current->next;
        }
        return head;
    }
};