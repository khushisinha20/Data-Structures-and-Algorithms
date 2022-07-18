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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head -> next == nullptr) {
            delete head;
            return nullptr;
        }
        
        ListNode* first = head;
        ListNode* second = head;
        ListNode* prev = head;
        for (int i = 1; i < n; ++i)
            first = first -> next;
        
        if (first -> next == nullptr) {
            ListNode* temp = second -> next;
            delete second;
            return temp;
        }
        
        while (first -> next != nullptr) {
            if (second != head)
                prev = prev -> next;
            second = second -> next;
            first = first -> next;
        }
        
        prev -> next = second -> next;
        delete second;
        return head;
    }
};