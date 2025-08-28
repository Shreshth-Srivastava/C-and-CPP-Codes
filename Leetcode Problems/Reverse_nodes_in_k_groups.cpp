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

// My Solution: Time Complexity --> O(N) ; Space Complexity --> O(N)

/*class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;

        ListNode* node = head;
        int lastNode = -1;
        while(node){
            addr.emplace_back(node);
            node = node->next;
        }

        int cnt = addr.size()/k;

        if(addr.size() % k != 0){
            lastNode = addr.size() - (addr.size() % k);
        }

        for(int i=0;cnt>0;i=i+k){
            reverseGroup(i, i+k-1);
            cnt--;
        }

        int start, end;

        for(int i=0;i<track.size();++i){
            start = track[i].first, end = track[i].second;
            int nextNode = i+1 < track.size() ? track[i+1].first : -1;
            addr[end]->next = nextNode != -1 ? addr[nextNode] : nullptr;
        }

        if(lastNode != -1){
            addr[end]->next = addr[lastNode];
        }

        return addr[k-1];
    }
private:
    vector<ListNode*> addr;
    // vector<pair<ListNode*, ListNode*>> track;
    vector<pair<int,int>> track;

    void reverseGroup(int start, int end){
        ListNode* node = addr[start];
        node->next = nullptr;

        node = addr[end];

        for(int i = end;node != addr[start];--i){
            node->next = addr[i-1];
            node = addr[i-1];
        }

        track.push_back({end, start});
    }
};*/

// NeetCode Solution: Time Complexity --> O(N) ; Space Complexity --> O(1)

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* groupPrev = dummy;

        while (true) {
            ListNode* kth = getKth(groupPrev, k);
            if (!kth) {
                break;
            }
            ListNode* groupNext = kth->next;

            ListNode* prev = kth->next;
            ListNode* curr = groupPrev->next;
            while (curr != groupNext) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            ListNode* tmp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = tmp;
        }
        return dummy->next;
    }

private:
    ListNode* getKth(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};

int main(){
    Solution sol;

    // ListNode fourth = ListNode(4);
    // ListNode third = ListNode(3, &fourth);
    // ListNode second = ListNode(2, &third);
    // ListNode head = ListNode(1, &second);

    // ListNode head = ListNode(1);

    ListNode sixth = ListNode(6);
    ListNode fifth = ListNode(5, &sixth);
    ListNode fourth = ListNode(4, &fifth);
    ListNode third = ListNode(3, &fourth);
    ListNode second = ListNode(2, &third);
    ListNode head = ListNode(1, &second);

    
    sol.reverseKGroup(&head, 2);
    return 0;
}