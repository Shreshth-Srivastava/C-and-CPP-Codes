#include<stdio.h>
#include<stdlib.h>

struct ListNode{
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

struct ListNode *InsertionAtEnd(struct ListNode *head, int data)
{
    struct ListNode *ptr = (struct ListNode *)malloc(sizeof(struct ListNode));
    ptr->val = data;
    struct ListNode *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head = l1;
    int a,b,c,d,e = 0;
    while(l1->next != NULL && l2->next != NULL){
        a = l1->val;
        b = l2->val;
        c = a+b+e;
        d = c%10;
        e = c/10;
        if(c>=10){
            l1->val = d;
            l1 = l1->next;
            l2 = l2->next;
        }
        else{
            l1->val = c;
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    if(l1->next == NULL && l2->next == NULL){
        a = l1->val;
        b = l2->val;
        c = a+b+e;
        d = c%10;
        e = c/10;
        if(c>=10){
            l1->val = d;
            InsertionAtEnd(l1, e);
            return head;
        }
        else{
            l1->val = c;
            return head;
        }
    }
    if(l1->next == NULL && l2->next != NULL){
        a = l1->val;
        b = l2->val;
        c = a+b+e;
        d = c%10;
        e = c/10;
        if(c>=10){
            l1->val = d;
            l2 = l2->next;;
        }
        else{
            l1->val = c;
            l2 = l2->next;
        }
        while(l2->next != NULL){
            b = l2->val;
            c = b+e;
            d = c%10;
            e = c/10;
            if(c>=10){
                InsertionAtEnd(l1, d);
                l2 = l2->next;
            }
            else{
                InsertionAtEnd(l1, c);
                l2 = l2->next;
            }
        }
        if(l2->next == NULL){
            b = l2->val;
            c = b+e;
            d = c%10;
            e = c/10;
            if(c>=10){
                InsertionAtEnd(l1, d);
                InsertionAtEnd(l1, e);
                return head;
            }
            else{
                InsertionAtEnd(l1, c);
                return head;
            }
        }
    }
    if(l1->next != NULL && l2->next == NULL){
        a = l1->val;
        b = l2->val;
        c = a+b+e;
        d = c%10;
        e = c/10;
        if(c>=10){
            l1->val = d;
            l1 = l1->next;
        }
        else{
            l1->val = c;
            l1 = l1->next;
        }
        while(l1->next != NULL){
            a = l1->val;
            c = a+e;
            d = c%10;
            e = c/10;
            if(c>=10){
                l1->val = d;
                l1 = l1->next;
            }
            else{
                l1->val = c;
                l1 = l1->next;
            }
        }
        if(l1->next == NULL){
            a = l1->val;
            c = a+e;
            d = c%10;
            e = c/10;
            if(c>=10){
                l1->val = d;
                InsertionAtEnd(l1, e);
                return head;
            }
            else{
                l1->val = c;
                return head;
            }
        }
    }
    return head;
}

int main(void){
    struct ListNode *head1;
    struct ListNode *second1;
    struct ListNode *third1;
    struct ListNode *fourth1;
    struct ListNode *fifth1;
    struct ListNode *sixth1;
    struct ListNode *seventh1;

    head1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    second1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    third1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    fourth1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    fifth1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    sixth1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    seventh1 = (struct ListNode *)malloc(sizeof(struct ListNode));

    head1->val = 9;
    head1->next = second1;
    second1->val = 9;
    second1->next = third1;
    third1->val = 9;
    third1->next = fourth1;
    fourth1->val = 9;
    fourth1->next = fifth1;
    fifth1->val = 9;
    fifth1->next = sixth1;
    sixth1->val = 9;
    sixth1->next = seventh1;
    seventh1->val = 9;
    seventh1->next = NULL;
   
    struct ListNode *head2;
    struct ListNode *second2;
    struct ListNode *third2;
    struct ListNode *fourth2;

    head2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    second2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    third2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    fourth2 = (struct ListNode *)malloc(sizeof(struct ListNode));

    head2->val = 9;
    head2->next = second2;
    second2->val = 9;
    second2->next = third2;
    third2->val = 9;
    third2->next = fourth2;
    fourth2->val = 9;
    fourth2->next = NULL;
    head1 = addTwoNumbers(head1, head2);
    LinkedListTraversal(head1);
    return 0;
}