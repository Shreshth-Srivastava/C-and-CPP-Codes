#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

//My Solution 0ms 

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head;
    struct ListNode* ptr;
    if(list1 == NULL) head = list2;
    else if(list2 == NULL) head = list1;
    else{
        if(list1->val < list2->val){
            head = list1;
            list1 = list1->next;
            ptr = head;
        }
        else{
            head = list2;
            list2 = list2->next;
            ptr = head;
        }
        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                ptr->next = list1;
                list1 = list1->next;
                ptr = ptr->next;
            }
            else{
                ptr->next = list2;
                list2 = list2->next;
                ptr = ptr->next;
            }
        }
        if(list1 != NULL){
            ptr->next = list1;
        }
        if(list2 != NULL){
            ptr->next = list2;
        }
    }
    return head;
}

int main(void){
    struct ListNode* list1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* list11 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* list12 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* list2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* list21 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* list22 = (struct ListNode*)malloc(sizeof(struct ListNode));
    list1->val = 5;
    list1->next = NULL;

    list11->val = 2;
    list11->next = list12;

    list12->val = 4;
    list12->next = NULL;

    list2->val = 1;
    list2->next = list21;

    list21->val = 3;
    list21->next = list22;

    list22->val = 4;
    list22->next = NULL;

    list2 = mergeTwoLists(list1,list2);
    struct ListNode* ptr = list2;
    while(ptr != NULL){
        printf("\n%d",ptr->val);
        ptr = ptr->next;
    }
    return 0;
}