# 143
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
    void reorderList(ListNode* head) {
        if(!head|| !head->next || !head->next->next) return;
        
        // 1.find the middle
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next && fast->next->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* mid=slow->next;
        slow->next=NULL;// cut off the linkedlist
        ListNode* last=mid;
        ListNode* pre=NULL;
        // 2. turn the second linkedlist
        while(last) {
            ListNode* next=last->next;
            last->next=pre;
            pre=last;
            last=next;
        }
        
        // 3.insert the node
        while(head&&pre) {
            ListNode* next=head->next;
            head->next=pre;
            pre=pre->next;
            head->next->next=next;
            head=next;
        }
        
    }
};
