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
    ListNode* reverseList(ListNode* head) {
        ListNode* res=NULL;
        ListNode* current;
        ListNode* tmp=NULL;
        if(head==NULL||head->next==NULL)
            return head;
        current = head;
        
        while(current!=NULL)
        {
            tmp=current->next;
            current->next=res;
            res=current;
            current=tmp;
        }
        return res;
    }
};