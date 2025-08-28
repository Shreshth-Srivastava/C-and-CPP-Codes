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

// Solution without using extra space

/*class Solution {
public:
    void reorderList(ListNode* head) {
        if (head->next == NULL) {
            return;
        }
        
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = NULL;
        
        ListNode* l1 = head;
        ListNode* l2 = reverse(slow);
        
        merge(l1, l2);
    }
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = curr->next;
        
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    void merge(ListNode* l1, ListNode* l2) {
        while (l1 != NULL) {
            ListNode* p1 = l1->next;
            ListNode* p2 = l2->next;
            
            l1->next = l2;
            if (p1 == NULL) {
                break;
            }
            l2->next = p1;
            
            l1 = p1;
            l2 = p2;
        }
    }
};*/

// Improved Version

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return; // Check if the list is too short to reorder

        vector<ListNode*> arr;
        ListNode* ptr = head;

        // Push all nodes to the vector
        while(ptr != nullptr) {
            arr.push_back(ptr);
            ptr = ptr->next;
        }

        int n = arr.size();
        for(int i = 0; i < n / 2; i++) {
            // Link nodes in the desired order
            arr[i]->next = arr[n - 1 - i];
            arr[n - 1 - i]->next = arr[i + 1];
        }
        // Set the last node's next to null to terminate the list
        arr[n / 2]->next = nullptr;
    }
};

// My Solution

/*class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> arr;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        int n = 0;
        while(ptr2 != NULL){
            arr.push_back(ptr2);
            ptr2 = ptr2->next;
            n++;
        }
        for(int i=0;i<n/2;i++){
            ptr1 = arr[i];
            ptr2 = arr[n-1-i];
            ListNode* prev = ptr1;
            ptr1 = ptr1->next;
            prev->next = ptr2;
            ptr2->next = ptr1;
        }
        arr[n / 2]->next = nullptr;
    }
};*/

int main(){
    Solution sol;
    ListNode third = ListNode(4);
    ListNode second = ListNode(3, &third);
    ListNode first = ListNode(2, &second);
    ListNode head = ListNode(1, &first);
    sol.reorderList(&head);
    return 0;
}