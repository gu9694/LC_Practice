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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len=lists.size();
        if(!len)
            return nullptr;
        if(len==1)
            return lists[0];
        if(len==2)
            return merge(lists[0],lists[1]);
        ListNode* tmp=lists[0];
        for(int i=1;i<len;i++)
        {
            ListNode* second=lists[i];
            tmp=merge(tmp,second);
        }
        return tmp;
    }
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        ListNode* result=new ListNode(0);
        ListNode* res=result;
        ListNode* tmp1=l1;
        ListNode* tmp2=l2;
        while(tmp1&&tmp2)
        {
            if(tmp1->val<tmp2->val)
            {
                res->next=tmp1;
                tmp1=tmp1->next;
                res=res->next;
            }
            else
            {
                res->next=tmp2;
                tmp2=tmp2->next;
                res=res->next;
            }   
        }
        if(tmp1)
            res->next=tmp1;
        if(tmp2)
            res->next=tmp2;
        return result->next;
    }
};