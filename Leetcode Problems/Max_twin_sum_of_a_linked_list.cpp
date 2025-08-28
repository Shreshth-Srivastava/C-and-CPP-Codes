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

// Better Solution: Time Complexity --> O(N) ; Space Complexity --> O(1) ??

class Solution {
public:
    int pairSum(ListNode* head) {
        int i = 0;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = NULL;
        while(slow){
            ListNode* next = slow->next;
            slow ->next = prev;
            prev = slow;
            slow = next;
        }
        int sum = 0;
        ListNode* temp = head;
        while(temp && prev){
            sum = max(temp->val+prev->val,sum);
            temp= temp->next;
            prev = prev->next;
        }
        return sum;
    }
};

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(N)

/*class Solution {
public:
    int pairSum(ListNode* head) {
        int res = INT_MIN;

        vector<int> arr;
        ListNode* node = head;

        while(node != nullptr){
            arr.push_back(node->val);
            node = node->next;
        }

        int l = 0, r = arr.size() - 1;

        while(l < r){
            res = max(res, (arr[l] + arr[r]));
            l++;r--;
        }

        return res;
    }
};*/