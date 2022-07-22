//leetcode.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head -> next == nullptr)
            return head;
        
        ListNode* curr = head;
        int length = 1;
        for (curr = head; curr -> next != nullptr; curr = curr -> next) 
            ++length;
        
        k %= length;
        curr -> next = head;
        
        ListNode* kthNodeFromLast = head;
        int countOfNodes = 0;
        ListNode* tail = head;
        
        while (countOfNodes < length - k - 1) {
            tail = tail -> next;
            ++countOfNodes;
        }
        
        kthNodeFromLast = tail -> next;
        tail -> next = nullptr;
        return kthNodeFromLast;
    }
};
