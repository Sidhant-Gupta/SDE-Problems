// https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

struct Node* reverseList(struct Node *head)
{
    struct Node *curr=head,*prev=NULL,*ne=NULL;
    while(curr){
        ne=curr->next;
        curr->next=prev;
        prev=curr;
        curr=ne;
        
    }
    head=prev;
    return head;
}