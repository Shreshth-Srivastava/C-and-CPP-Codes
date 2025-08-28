#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void LinkedListTraversal(struct ListNode *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->val);
        ptr = ptr->next;
    }
}

struct ListNode *DeletionAtStart(struct ListNode *head){
    struct ListNode *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct ListNode *DeletionAtMid(struct ListNode *head, struct ListNode *p){
    struct ListNode *ptr;
    ptr = head;
    while(ptr->next != p) ptr = ptr->next;
    ptr->next = p->next;
    free(p);
    return ptr->next;
}

struct ListNode *DeletionAtEnd(struct ListNode *head){
    struct ListNode *ptr;
    struct ListNode *p;
    p = head->next;
    ptr = head;
    while(p->next != NULL) {
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = NULL;
    free(p);
    return head;
}

struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *p;
    if(head == NULL) return NULL;
    while(head->next != NULL && head->val == val) head = DeletionAtStart(head) ;
    if(head->val != val && head->next != NULL){
        p = head->next;
    }
    while(p->next != NULL){
        if(p->val == val){
            p = DeletionAtMid(head, p);
        }
        else{
            p = p->next;
        }
    }
    if(p->next == NULL && p->val == val) head = DeletionAtEnd(head) ;
    if(head->val == val && head->next == NULL) return NULL;

    return head;
}

int main(void){
    struct ListNode *head;
    struct ListNode *second;
    struct ListNode *third;
    struct ListNode *fourth;

    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    second = (struct ListNode *)malloc(sizeof(struct ListNode));
    third = (struct ListNode *)malloc(sizeof(struct ListNode));
    fourth = (struct ListNode *)malloc(sizeof(struct ListNode));

    head->val = 1;
    head->next = second;

    second->val = 2;
    second->next = third;

    third->val = 6;
    third->next = fourth;

    fourth->val = 6;
    fourth->next = NULL;

    head = removeElements(head, 6);
    LinkedListTraversal(head);
    
    return 0;
}