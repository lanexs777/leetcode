// linked-list [medium] #328
#include<iostream>                                                                            
using namespace std;

class Solition {
    public:
        ListNode* oddEvenList(List* head) {
            if(head==NULL || head->next==NULL) 
                return head;
            ListNode* evenhead=head->next;
            ListNode* cureven=evenhead;
            ListNode* curodd=head;
            
            while(cureven->next != NULL) {
                curodd->next=curodd->next->next;
                curodd=curodd->next;

                if(cureven->next->next==NULL)
                    break;
                cureven->next=cureven->next->next;
                cureven=cureven->next;

            };
            
        }

};
