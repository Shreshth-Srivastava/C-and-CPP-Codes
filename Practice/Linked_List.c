#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void LinkedListTraversal(struct Node*head){
    struct Node* ptr = head;
    while(ptr != NULL){
        printf("\n%d",ptr->data);
        ptr = ptr->next;
    }
}

void InsertionAtEnd(struct Node* head,int val){
    struct Node* ptr = head;
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    p->data = val;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = p;
    p->next = NULL;
}

int main(void){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    int a;
    head->next = NULL;
    printf("\n--------------------------------------------------");
    printf("\nInsertion At End");
    printf("\n--------------------------------------------------");
    printf("\nEnter the value that you want to insert: ");
    scanf("%d",&a);
    InsertionAtEnd(head,a);
    LinkedListTraversal(head);
    return 0;
}