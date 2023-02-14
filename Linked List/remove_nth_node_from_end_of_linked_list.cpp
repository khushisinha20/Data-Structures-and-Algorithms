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
        ListNode* dummy = new ListNode();
        dummy -> next = head;
        
        ListNode* current = dummy;
        ListNode* nth = dummy;
        
        for (int i = 1; i <= n + 1; ++i)
            current = current -> next;
        
        while (current) {
            current = current -> next;
            nth = nth -> next;
        }
        
        ListNode* nthFromLast = nth -> next;
        nth -> next = nth -> next -> next;
        delete nthFromLast;
        return dummy -> next;
    }
};