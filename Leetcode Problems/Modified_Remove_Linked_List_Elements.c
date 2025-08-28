#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
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

struct ListNode *DeletionAtStart(struct ListNode *head)
{
    struct ListNode *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
struct ListNode *DeletionAtMid(struct ListNode *head, struct ListNode *p)
{
    struct ListNode *ptr;
    ptr = head;
    while (ptr->next != p)
        ptr = ptr->next;
    if (ptr->next != NULL)
        ptr->next = p->next;
    free(p);
    return ptr;
}
struct ListNode *DeletionAtEnd(struct ListNode *head)
{
    struct ListNode *ptr;
    struct ListNode *p;
    p = head->next;
    ptr = head;
    while ((p->next) != NULL)
    {
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = NULL;
    free(p);
    return head;
}
struct ListNode *removeElements(struct ListNode *head, int val)
{
    struct ListNode *p;
    struct ListNode *q;
    int nodeval;
    if (head == NULL)
        return NULL;
    while (head->next != NULL && head->val == val)
        head = DeletionAtStart(head);
    if (head->next != NULL && head->val != val)
    {
        p = head->next;
        q = p->next;
        nodeval = p->val;
        while (q != NULL)
        {
            if (nodeval == val)
            {
                p = DeletionAtMid(head, p);
                if (p->next != NULL)
                {
                    p = p->next;
                    q = p->next;
                    nodeval = p->val;
                }
            }
            else
            {
                if (p->next != NULL)
                {
                    p = p->next;
                    q = p->next;
                    nodeval = p->val;
                }
            }
        }
    }
    if (q == NULL && nodeval == val)
        head = DeletionAtEnd(head);
    if (head->val == val && head->next == NULL)
        return NULL;
    return head;
}

int main(void)
{
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

    third->val = 1;
    third->next = fourth;

    fourth->val = 1;
    fourth->next = NULL;

    head = removeElements(head, 1);
    LinkedListTraversal(head);

    return 0;
}