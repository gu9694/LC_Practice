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
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast -> next != NULL && fast -> next -> next != NULL ){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) 
                return true;
        }
        return false;
    }
};

//取一个快指针，每次走两步，慢指针每次走一步,如果两个指针可以相遇，含有环