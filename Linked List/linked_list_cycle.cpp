//leetcode.com/problems/linked-list-cycle/

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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast -> next != nullptr) {
            fast = fast -> next -> next;
            slow = slow -> next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};