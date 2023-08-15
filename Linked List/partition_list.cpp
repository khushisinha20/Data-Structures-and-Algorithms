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
        ListNode* dummyForLess = new ListNode();
        ListNode* dummyForMore = new ListNode();
        ListNode* tailForLess = dummyForLess;
        ListNode* less = dummyForLess;
        ListNode* more = dummyForMore;
        ListNode* current = head;
        
        while (current) {
            if (current -> val < x) {
                less -> next = current;
                tailForLess = current;
                less = less -> next;
            } else {
                more -> next = current;
                more = more -> next;
            }
            current = current -> next;
        }
        
        more -> next = nullptr;
        tailForLess -> next = dummyForMore -> next;
        delete dummyForMore;
        return dummyForLess -> next;
    }
};