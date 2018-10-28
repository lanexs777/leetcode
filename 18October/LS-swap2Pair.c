# 24
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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL) return head;
        ListNode tmp(0);
        tmp.next=head;
        ListNode* pre=&tmp;
        ListNode* curr=head;
        
        while(curr && curr->next) {
            pre->next=curr->next;
            pre=pre->next;
            curr->next=pre->next;
            pre->next=curr;
            curr=curr->next;
            pre=pre->next;
        }
        return tmp.next;
    }
};
