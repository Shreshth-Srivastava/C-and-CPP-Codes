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

// Brute Force But Simple Approach: Time Complexity --> O(nlogn) ; Space Complexity --> O(n)

// class Solution {    
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         vector<int> nodes;
//         for (ListNode* lst : lists) {
//             while (lst) {
//                 nodes.push_back(lst->val);
//                 lst = lst->next;
//             }
//         }
//         sort(nodes.begin(), nodes.end());

//         ListNode* res = new ListNode(0);
//         ListNode* cur = res;
//         for (int node : nodes) {
//             cur->next = new ListNode(node);
//             cur = cur->next;
//         }
//         return res->next;
//     }
// };

// Divide-and-Conquer Approach: Time Complexity --> O(nlogk) ; Space Complexity --> O(k)

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }

        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;
            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1) < lists.size() ? lists[i + 1] : nullptr;
                mergedLists.push_back(mergeList(l1, l2));
            }
            lists = mergedLists;
        }
        return lists[0];
    }

private:
    ListNode* mergeList(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if (l1) {
            tail->next = l1;
        }
        if (l2) {
            tail->next = l2;
        }

        return dummy.next;
    }
};