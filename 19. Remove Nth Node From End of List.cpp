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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp=head;
        int len=0;
        if(head==nullptr)
            return head;
        while(tmp!=nullptr)
        {
            len++;
            tmp=tmp->next;
        }
        
        int target=len-n;//the one in front of target node
        
        if(len==n)
            return head->next;
        tmp=head;
        int cur=1;
        while(cur<target)
        {
            cur++;
            tmp=tmp->next;
        }
        tmp->next=tmp->next->next;
        return head;
    }
};

//len求出链表长度
//target=len-n 需要在第target个节点停下 从第1个节点开始