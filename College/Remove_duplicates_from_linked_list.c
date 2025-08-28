#include<stdio.h>
#include<Stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* RemoveDuplicates(struct Node* head){
    struct Node *ptr,*p,*dup;
    ptr = head;
    while(ptr != NULL && ptr->next != NULL){
        p = ptr;
        while(p->next != NULL){
            if(ptr->data == p->next->data){
                dup = p->next;
                p->next = p->next->next;
                free(dup);
            }
            else p = p->next;
        }
        ptr = ptr->next;
    }
    return head;
}

struct Node *Insertion(struct Node*head,int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    ptr->next = NULL;
    ptr->data = data;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    return head;
}


void LinkedListTraversal(struct Node* head){
    struct Node* ptr = head;
    while(ptr != NULL){
        printf("\n%d",ptr->data);
        ptr = ptr->next;
    }
}

int main(void){
    int a,b,flag = 0;
    struct Node *head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 0;
    head->next = NULL;
    while(1){
        printf("\n------------------------|");
        printf("\n\tMenu");
        printf("\n------------------------|");
        printf("\n1. Insert a value");
        printf("\n2. Stop");
        printf("\nEnter your choice: ");
        scanf("%d",&a);
        if(a == 2) break;
        else{
            if(a == 1){
                if(flag == 0){
                    printf("\nEnter the value that you want to insert: ");
                    scanf("%d",&b);
                    head->data = b;
                    flag++;
                }
                else{
                    printf("\nEnter the value that you want to insert: ");
                    scanf("%d",&b);
                    head = Insertion(head,b);
                }
            }
            else printf("\n!!!Invalid Input!!!");
        }
    }
    printf("\nInputted linked list:-");
    LinkedListTraversal(head);
    head = RemoveDuplicates(head);
    printf("\nLinked list after the removal of duplicates:-");
    LinkedListTraversal(head);
    return 0;
}