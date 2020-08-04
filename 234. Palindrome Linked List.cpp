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
    bool isPalindrome(ListNode* head) {
        vector<int> res;
        ListNode* tmp=head;
        while(tmp!=nullptr)
        {
            res.push_back(tmp->val);
            tmp=tmp->next;
        }
        int len=res.size();
        int left=0;
        int right=len-1;
        while(left<right)
        {
            if(res[left]!=res[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};