//leetcode.com/problems/reverse-nodes-in-k-group/

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
    void reverse(ListNode* start, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* curr = start;
        ListNode* next = start -> next;
        while (prev != end) {
            curr -> next = prev;
            prev = curr;
            curr = next;
            if (next != nullptr)
                next = next -> next;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head -> next == nullptr || k == 1)
            return head;
        ListNode* start = head;
        ListNode* end = head;
        for (int i = 1; i <= k - 1; ++i) {
            end = end -> next;
            if (end == nullptr)
                return head;
        }
        ListNode* nextHead = reverseKGroup(end -> next, k);
        reverse(start, end);
        start -> next = nextHead;
        return end;
    }
};