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
        unordered_map<int,int> mymap;
        if(head==nullptr||head->next==nullptr)
            return head;
        ListNode* tmp=head;
        while(tmp!=nullptr)
        {
            int cur=tmp->val;
            mymap[cur]++;
            tmp=tmp->next;
        }
        vector<int> num;
        for(auto i:mymap)
        {
            if(i.second==1)
                num.push_back(i.first);
        }
        sort(num.begin(),num.end());
        ListNode* res=new ListNode(0);
        ListNode* cur=res;
        int len=num.size();
        for(int i=0;i<len;i++)
        {
            ListNode* now=new ListNode(num[i]);
            cur->next=now;
            cur=cur->next;
        }
        cur->next=nullptr;
        return res->next;
    }
};