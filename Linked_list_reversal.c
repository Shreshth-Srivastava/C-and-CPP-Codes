#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node* reverse(struct Node *ptr){
    struct Node *prev;
    struct Node *current;
    struct Node *next;
    prev = ptr;
    current = ptr;
    next = ptr->next;
    ptr->next = NULL;
    current = next;
    while(current->next != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    if(current->next == NULL){
        current->next = prev;
    }
    return current;
}

int main(void){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;
    second->data = 3;
    second->next = third;
    third->data = 5;
    third->next = fourth;
    fourth->data = 7;
    fourth->next = fifth;
    fifth->data = 9;
    fifth->next = NULL;
    head = reverse(head);
    LinkedListTraversal(head);
    return 0;
}