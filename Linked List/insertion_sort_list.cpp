//leetcode.com/problems/insertion-sort-list/

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode();
        
        while (head) {
            ListNode* next = head -> next;
            ListNode* current = dummy;
            
            while (current -> next && current -> next -> val < head -> val)
                current = current -> next;
            
            head -> next = current -> next;
            current -> next = head;
            head = next;
        }
        
        return dummy -> next;
    }
};