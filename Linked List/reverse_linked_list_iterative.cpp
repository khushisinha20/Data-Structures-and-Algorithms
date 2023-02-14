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
        if (!head || !head -> next)
            return head;
        
        ListNode* previous = nullptr;
        ListNode* current = head;
        
        while (current) {
            ListNode* next = current -> next; //next pointer required to keep track of the next node of the linked list
            current -> next = previous;
            previous = current;
            current = next;
        }
        
        return previous;
    }
};