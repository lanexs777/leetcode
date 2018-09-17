//linked-list [medium] #817
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */ 
 // 利用set的快速搜功能，一個一個得再linked-list裡面搜尋
 // flag 表示是否連續 
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        set<int> s(G.begin(), G.end());
        ListNode* cur=head;
        int flag=0; //detect consecutive or not
        int res=0;  //count how many components.
        
        while(cur){
              if(s.count(cur->val) && !flag){ //找到且不連續時
                  res++;
                  flag=1;
              }
              else if(!s.count(cur->val) && flag){ //沒找到且原本連續時
                  flag=0;
              }
              cur=cur->next;  
        };
        return res;
    }
};
