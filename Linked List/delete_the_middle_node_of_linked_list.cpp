//leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

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
    ListNode* deleteMiddle(ListNode* head) {
        if (head -> next == nullptr) {
            delete head;
            return nullptr;
        }
        ListNode* prev = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast -> next != nullptr) {
            if (fast != head)
                prev = prev -> next;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        prev -> next = slow -> next;
        delete slow;
        return head;
    }
};