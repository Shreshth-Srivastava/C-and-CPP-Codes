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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* prev = head;
        ListNode* node = prev->next;

        while(node != nullptr){
            int val = gcd(prev->val, node->val);
            ListNode *temp = new ListNode(val, node);

            prev->next = temp;
            prev = node;
            node = node->next;
        }
        return head;
    }
private:
    int gcd(int a, int b){
        int temp;

        if(b>a){
            temp = b;
            b = a;
            a = temp;
        }

        while(true){
            temp = a%b;
            a = b;
            b = temp;
            if(temp == 0){
                return a;
            }
        }
        
        return 0;
    }
};

int main(){
    Solution sol;
    ListNode d = ListNode(3, nullptr);
    ListNode c = ListNode(10, &d);
    ListNode b = ListNode(6, &c);
    ListNode a = ListNode(18, &b);
    sol.insertGreatestCommonDivisors(&a);
    return 0;
}