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

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return head;

        ListNode* node = head;
        ListNode* oddHead = nullptr;
        ListNode* evenHead = nullptr;
        ListNode* oddTail = nullptr;
        ListNode* evenTail = nullptr;
        bool odd = true;

        while(node != nullptr){
            if(!oddHead){
                oddHead = node;
                oddTail = oddHead;
                node = node->next;
                continue;
            }
            if(!evenHead){
                evenHead = node;
                evenTail = evenHead;
                node = node->next;
                continue;
            }
            if(odd){
                oddTail->next = node;
                oddTail = oddTail->next;
                node = node->next;
                oddTail->next = evenHead;
                odd = false;
            }
            else{
                evenTail->next = node;
                evenTail = evenTail->next;
                node = node->next;
                evenTail->next = nullptr;
                odd = true;
            }
        }

        if(evenHead != nullptr && evenHead == evenTail)
            evenTail->next = nullptr;

        if(oddHead == oddTail && evenHead == nullptr)
            oddTail->next = nullptr;

        return head;
    }
};