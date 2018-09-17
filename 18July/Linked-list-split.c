/** #725
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> ans;
        
        //count the number of the linked-list
        int count=0;
        ListNode* tmp=root;
        while(tmp){
            count++;
            tmp=tmp->next;            
        };
        
        int per[k]={0};
        //set the length of each part
        for(int i=0;i<count;i++) {
            int who=i%k;
            per[who]=per[who]+1;
        }
        ListNode* none=NULL;
        ListNode* cut=root;
        
        //split the linked-list
        for(int i=0;i<k;i++) {
            ListNode* comp=cut;
            //when the length is zero.
            if(per[i]==0){
                ans.push_back(none);
                continue;
            }
            for(int j=0;j<per[i]-1;j++) {
                cut=cut->next;
            }
            ListNode* tail=cut;
            cut=cut->next;
            tail->next=NULL;
            ans.push_back(comp);            
            
        }      
        return ans;
    }
};
