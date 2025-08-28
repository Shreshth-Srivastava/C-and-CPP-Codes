#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = head;
        ListNode* current = head->next;
        ListNode* nxt = current->next;
        prev->next = NULL;
        if(nxt == NULL){
            current->next = prev;
        }
        else{
            while(nxt != NULL){
                current->next = prev;
                prev = current;
                current = nxt;
                nxt = nxt->next;
            }
            current->next = prev;
        }
        return current;
    }
};

int main(){
    return 0;
}