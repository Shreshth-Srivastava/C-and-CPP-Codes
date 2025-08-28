#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *reverse(struct Node *ptr)
{
    struct Node *prev;
    struct Node *current;
    struct Node *next;
    prev = ptr;
    current = ptr;
    next = ptr->next;
    ptr->next = NULL;
    current = next;
    while (current->next != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    if (current->next == NULL)
    {
        current->next = prev;
    }
    return current;
}

void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("\n%d", ptr->data);
        ptr = ptr->next;
    }
}

void View(struct Node *head, int p)
{
    if (p == 0)
        printf("\nThe Stack is empty");
    else
    {
        if (p == 1)
            printf("\n%d <--Top", head->data);
        else
        {
            head = reverse(head);
            printf("\n%d <--Top", head->data);
            LinkedListTraversal(head->next);
            head = reverse(head);
        }
    }
    printf("\n");
}

struct Node *InsertionAtEnd(struct Node *head, int val)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ptr;
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    p->data = val;
    ptr->next = p;
    p->next = NULL;
    return head;
}

int Push(struct Node *head, int p)
{
    int x;
    printf("\nEnter the value that you want to insert in the Stack: ");
    scanf("%d", &x);
    if (p == 0)
    {
        head->data = x;
        p++;
    }
    else
    {
        head = InsertionAtEnd(head, x);
        p++;
    }
    return p;
}

int Pop(struct Node *head, int p)
{
    struct Node *ptr;
    ptr = head;
    if (p == 0)
        printf("\n!!Stack Underflow!!");
    else
    {
        if (p == 1)
            p--;
        else
        {
            while (ptr->next->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = NULL;
            p--;
        }
    }
    printf("\n");
    return p;
}

int main(void)
{
    struct Node *head;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->next = NULL;
    int flag = 1, a = 0, p = 0;
    while (flag != 0)
    {
        printf("\nStack Operations: ");
        printf("\n1. View");
        printf("\n2. Push");
        printf("\n3. Pop");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &a);
        if (a == 1)
            View(head, p);
        if (a == 2)
            p = Push(head, p);
        if (a == 3)
            p = Pop(head, p);
        if (a == 4)
            flag = 0;
    }
    return 0;
}