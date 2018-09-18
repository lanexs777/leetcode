# 138
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL) return NULL;
        
        RandomListNode* curr=head;
        RandomListNode* res=new RandomListNode(curr->label);
        RandomListNode* tmp=res;
        // create a list only with next;
        while(curr!=NULL && curr->next!=NULL) {
            curr=curr->next;
            tmp->next=new RandomListNode(curr->label);
            tmp=tmp->next;
        }
        //create the random pointers
        curr=head;
        tmp=res;
        RandomListNode* rando=curr->random;
        while(curr!=NULL) {
            rando=curr->random;
            if(rando==NULL) {
                tmp=tmp->next;
                curr=curr->next;
            }
            else {
                RandomListNode* counto=head;
                RandomListNode* countn=res;
                while(counto!=rando) {
                    counto=counto->next;
                    countn=countn->next;                    
                }
                tmp->random=countn;
                curr=curr->next;
                tmp=tmp->next;
            }     
        }
        return res;
    }
};
