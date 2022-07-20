//leetcode.com/problems/odd-even-linked-list/

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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd_end = nullptr;
        ListNode* odd_start = nullptr;
        ListNode* even_end = nullptr;
        ListNode* even_start = nullptr;
        int index = 1;
        
        for (ListNode* curr = head; curr != nullptr; curr = curr -> next) {
            if (index % 2) {
                if (odd_start == nullptr) {
                    odd_start = curr;
                    odd_end = curr;
                } else {
                    odd_end -> next = curr;
                    odd_end = odd_end -> next;
                }
                ++index;
            } else {
                if (even_start == nullptr) {
                    even_start = curr;
                    even_end = curr;
                } else {
                    even_end -> next = curr;
                    even_end = even_end -> next;
                }
                ++index;
            }
        }
        
        if (even_end == nullptr || odd_end == nullptr)
            return head;
        
        odd_end -> next = even_start;
        even_end -> next = nullptr;
        return odd_start;
    }
};