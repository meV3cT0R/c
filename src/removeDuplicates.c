#include <removeDuplicates.h>
#include <stdio.h>
struct ListNode* deleteDuplicates(struct ListNode* head) {

    struct ListNode* curr = head,*temp,*prev=NULL;

    while(curr!=NULL && curr->next!=NULL) {       
        temp=curr->next;
        if(temp->val!=curr->val){ prev=curr; curr=curr->next; continue;}
        while(temp!=NULL && temp->val==curr->val) 
            temp=temp->next;
        if(temp==NULL) {
            if(prev==NULL) return NULL;
            prev->next=NULL;
            break;
        }
        curr->val=temp->val;
        curr->next=temp->next;
    }
    return head;
}