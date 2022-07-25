//leetcode.com/problems/reorder-list/

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
    void reorderList(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head;
        while (first && first -> next) {
            first = first -> next -> next;
            second = second -> next;
        }
        
        ListNode* prev = nullptr;
        ListNode* curr = second;
        ListNode* next;
        while (curr) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        first = head;
        second = prev;
        ListNode* temp;
        while (second -> next) {
            temp = first -> next;
            first -> next = second;
            first = temp;
            temp = second -> next;
            second -> next = first;
            second = temp; 
        }
    }
};