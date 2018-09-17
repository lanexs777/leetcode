// linked list [medium] #92

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL) return NULL;
        
        // 建立這個node的用意是為了避免當從第一個開始reverse時狀況
        ListNode* z=new ListNode(0);
        z->next=head;
        
        ListNode* pre=z;
        ListNode* start;
        ListNode* then;
        
        for(int i=0;i<m-1;i++)
            pre=pre->next;
        
        start=pre->next;
        then=start->next;
        
        // 利用類似 insert sort 的方式 進行reverse 
        // pre--start--then : 將then 一次一次的插入 pre & pre->next中間 再forward then 一格
        for(int i=0;i<n-m;i++) {
            start->next=then->next;
            then->next=pre->next;
            pre->next=then;
            then=start->next;
        }
        return z->next;
        
    }
};
