//leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head -> next == nullptr)
            return head;
        
        ListNode* root = new ListNode(0, head);
        ListNode* prev = root;
        ListNode* curr = prev -> next;
        
        while (prev -> next && curr -> next) {
            prev -> next = curr -> next;
            curr -> next = curr -> next -> next;
            prev -> next -> next = curr;
            prev = curr;
            curr = curr -> next;
        } 
        return root -> next;
    }
};