# 25
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k==1) return head;
        ListNode *dummy=new ListNode(-1);
        ListNode *pre=dummy;
        ListNode *curr=head;
        
        dummy->next=head;
        int i=0;
        while(curr) {
            ++i;
            if(i%k==0) {
                // reverse group
                pre=reverseOneGroup(pre, curr->next);
                curr=pre->next;
            }
            else {
                curr=curr->next;
            }
        }
        return dummy->next;
    }
    
    ListNode* reverseOneGroup(ListNode* pre, ListNode* next) {
        ListNode *last=pre->next;
        ListNode *curr=last->next;
        
        while(curr!=next) {
            last->next=curr->next;
            curr->next=pre->next;
            pre->next=curr;
            curr=last->next;
        }
        return last;
    }
};
