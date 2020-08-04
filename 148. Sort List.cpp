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
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* slow;
        ListNode* fast;
        slow= head;
        fast= head;
        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* mid= slow->next;
        slow->next=NULL;
        ListNode* fh=sortList(head);
        ListNode* sh=sortList(mid);
        ListNode* res=merge(fh,sh);
        return res;
    }
private:
    ListNode* merge(ListNode* l1,ListNode *l2)
    {
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode res(0);
        ListNode* p=&res;
        while(l1!=NULL&&l2!=NULL)
        {
            if(l1->val<l2->val)
            {
                p->next=l1;
                l1=l1->next;
                p=p->next;
            }
            else
            {
                p->next=l2;
                l2=l2->next;
                p=p->next;
            }
        }
        if(l1!=NULL)
            p->next=l1;
        if(l2!=NULL)
            p->next=l2;
        return res.next;
    }
};

//递归的方法

//快慢指针的使用，目的是找到中点进行分割

//fast->next!=NULL&&fast->next->next!=NULL
//两个判断条件都不能少且位置不能变

//注意链表节点初始化的方法 ListNode sum(0)

//第二个函数返回值是return res.next 
//return res->next会报错不知道是为什么...