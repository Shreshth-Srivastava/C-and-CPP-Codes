#include<stdio.h>
#include<stdlib.h>

struct queue{
    int data;
    struct queue *next;
};

struct queue *Pop(struct queue *head){
    printf("\nPopped element: %d",head->data);
    head = head->next;
    return head;
}

void LinkedListTraversal(struct queue *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct queue *Push(struct queue *head,int data){
    struct queue *ptr = (struct queue *)malloc(sizeof(struct queue));
    ptr->data = data;
    struct queue *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

int main(void){
    int n = 0,a = 0,tracker = 0,temp;
    struct queue *head = (struct queue*)malloc(sizeof(struct queue));
    head->next = NULL;
    while(1){
        printf("\n|-------------------|");
        printf("\n\tMenu");
        printf("\n|-------------------|");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. View");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&a);
        if(a == 4){
            break;
        }
        else{
            if(a == 1){
                printf("\nEnter the data that you want to push: ");
                scanf("%d",&temp);
                if(tracker == 0){
                    head->data = temp;
                    tracker++;
                }
                else{
                    head = Push(head,temp);
                    tracker++;
                }
            }
            else{
                if(a == 2){
                    if(tracker == 0) printf("\n!!!Queue Underflow!!!\n");
                    else{
                        if(tracker == 1){
                            printf("\nPopped element: %d",head->data);
                            tracker--;
                        }
                        else{
                            head = Pop(head);
                            tracker--;
                        }
                    }
                }
                else {
                    if(tracker == 0) printf("\nNo elements in queue");
                    else LinkedListTraversal(head);
                }
            }
        }
    }
    return 0;
}