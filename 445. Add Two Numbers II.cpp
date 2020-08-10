/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<long long int> s1;
        stack<long long int> s2;
        while(l1!=nullptr)
        {
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2!=nullptr)
        {
            s2.push(l2->val);
            l2=l2->next;
        }
        ListNode* res=new ListNode(0);
        int sum=0;
        while(s1.empty()==false||s2.empty()==false)
        {
            if(s1.empty()==false)
            {
                sum+=s1.top();
                s1.pop();
            }
            if(s2.empty()==false)
            {
                sum+=s2.top();
                s2.pop();
            }
            res->val=sum%10;
            ListNode* head=new ListNode(sum/10);
            sum=sum/10;
            head->next=res;
            res=head;
        }
        return res->val==0?res->next:res;
    }
};