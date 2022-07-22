//leetcode.com/problems/partition-list/

#include <bits/stdc++.h>
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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head -> next == nullptr)
            return head;
        
        ListNode* lesser_head = new ListNode(-1);
        ListNode* greater_head = new ListNode(-1);
        ListNode* lesser = lesser_head;
        ListNode* greater = greater_head;
        
        while (head) {
            if (head -> val < x) {
                lesser -> next = head;
                lesser = lesser -> next;
            } else {
                greater -> next = head;
                greater = greater -> next;
            }
            head = head -> next;
        }
        
        greater -> next = nullptr;
        lesser -> next = greater_head -> next;
        delete greater_head;
        return lesser_head -> next;
    }
};