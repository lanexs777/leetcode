# 61
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        if(!head->next) return head;
        
        int count=0;
        ListNode * cnt=head;
        while(cnt!=NULL) {
            count++;
            cnt=cnt->next;
        }
        
        k=k%count;
        
        for(int i=0;i<k;i++) {
            ListNode * curr=head;
            while(curr->next!=NULL) curr=curr->next;
            ListNode * pre=head;
            while(pre->next!=curr) pre=pre->next;
            pre->next=NULL;
            curr->next=head;
            head=curr;
        }
        return head;
    }
};
