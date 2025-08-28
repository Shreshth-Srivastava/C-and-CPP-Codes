#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Better Solution
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        
        return false;
    }
};

//My Solution
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         if(head == NULL || head->next == NULL) return false;
//         else{
//             struct ListNode* ptr1 = head;
//             struct ListNode* ptr2 = head->next;
//             while(ptr2 != NULL){
//                 ptr1 = ptr1->next;
//                 if(ptr2->next != NULL){
//                     ptr2 = ptr2->next->next;
//                     if(ptr1 == ptr2) return true;
//                 }
//                 else return false;
//             }
//             return false;
//         }
//     }
// };