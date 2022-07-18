//leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev_node = nullptr;
        ListNode* curr_node = head;
        ListNode* next_node = head;
        
        while (curr_node != nullptr) {
            next_node = curr_node -> next;
            curr_node -> next = prev_node;
            prev_node = curr_node;
            curr_node = next_node;
        }
        
        return prev_node;
    }
};